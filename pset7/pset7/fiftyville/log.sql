-- Keep a log of any SQL queries you execute as you solve the mystery.
-- All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.

-- 1.- Check the type of info table crime_scene_reports had
SELECT * FROM crime_scene_reports LIMIT 5;

-- 2.- Check the crimes on Humphery Street
SELECT * FROM crime_scene_reports WHERE street = "Humphrey Street" AND day = 28 AND month = 7 AND year = 2021;
    -- NOTES: ID = 295 Humphrey Street |  Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
        -- Notes: Robbery at 10:15am

-- 3.- Check the type of info (columns) table interviews had
SELECT * FROM crime_scene_reports LIMIT 5;

-- 4.- Check the interviews with the same of day, month and year of the crime
SELECT * FROM interviews WHERE day = 28 AND month = 7 AND year = 2021;
    ---NOTES: The id from the interviews are from 161-163
        -- Names of the interviewed people: Ruth, Eugene, Raymond
            --NOTES FROM INTERVIEWS: Car - Footage from the bakery 10 minutes of the thieft = 10:25
            -- Earlier, ATM on Legget Str withdrawing money
            -- After the thief, talked with someone less than a minute,
            -- Earliest Fligth to FiftyVille tomorrow (7-29-2021), coplice bought the ticket

/*
Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
*/


-- 5.- Check the type of info (columns) table secutirylogs had
SELECT * FROM bakery_security_logs LIMIT 5;

-- 6.- Check the logs with the same of day, month, year and time of the crime
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = "exit";
  /*
    -- Notes: There are 8 plates within the 10 minutes mark betwwn 10:15 and 10:25 being;
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
+-----+------+-------+-----+------+--------+----------+---------------+
*/

-- CAR FOOTAGE
-- 7.- Check the people table with the plates given
SELECT * FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = "exit");
/*
+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
| 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
| 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+---------+----------------+-----------------+---------------+
*/

-- 8.- Check the type of info (columns) table atm_transactions had
SELECT * FROM atm_transactions LIMIT 5;

-- 9.- Check the transactions (only withdraws) with the same of day, month and year of the crime on Leggett Street
SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
    -- Theres a Total of 8 transactions with the respective account_number

-- MONEY WITHDRAWN
-- 10.- Check the TABLE bank_accounts and get the names from TABLE PEOPLE with the previous information (only withdraws) with the same of day, month and year of the crime on Leggett Street
SELECT bank_accounts.person_id, people.name, bank_accounts.account_number FROM people INNER JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw");
/*
+-----------+---------+----------------+
| person_id |  name   | account_number |
+-----------+---------+----------------+
| 686048    | Bruce   | 49610011       |
| 514354    | Diana   | 26013199       |
| 458378    | Brooke  | 16153065       |
| 395717    | Kenny   | 28296815       |
| 396669    | Iman    | 25506511       |
| 467400    | Luca    | 28500762       |
| 449774    | Taylor  | 76054385       |
| 438727    | Benista | 81061156       |
+-----------+---------+----------------+
*/

-- 12.- Compare the tables to find a relationship
SELECT * FROM
(SELECT * FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = "exit")) AS Q1
INNER JOIN
(SELECT bank_accounts.person_id, people.name, bank_accounts.account_number FROM people INNER JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")) AS Q2
ON Q1.id = Q2.person_id;
/* This should return a list of people who were both at the bakery parking lot during the specified time and made a withdrawal at the ATM on Leggett Street on the same day.
+--------+-------+----------------+-----------------+---------------+-----------+-------+----------------+
|   id   | name  |  phone_number  | passport_number | license_plate | person_id | name  | account_number |
+--------+-------+----------------+-----------------+---------------+-----------+-------+----------------+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       | 686048    | Bruce | 49610011       |
| 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       | 514354    | Diana | 26013199       |
| 396669 | Iman  | (829) 555-5269 | 7049073643      | L93JTIZ       | 396669    | Iman  | 25506511       |
| 467400 | Luca  | (389) 555-5198 | 8496433585      | 4328GD8       | 467400    | Luca  | 28500762       |
+--------+-------+----------------+-----------------+---------------+-----------+-------+----------------+
*/ -- NOTES: Brice, Diana, Iman and Luca as suspects
            --NOTES FROM INTERVIEWS: Car - Footage from the bakery 10 minutes of the thieft = 10:25

-- 13.- Check the phone Calls on the same day of the robbery
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 and duration < 61;


--
-- EXTRA.- Check the phone Calls on the same day of the robbery
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 and duration < 61;
SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 and duration < 61);

-- 14.- Compare last querie with suspects
WITH Q1 AS (
  SELECT * FROM people WHERE license_plate IN
  (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = "exit")
),
Q2 AS (
  SELECT bank_accounts.person_id, people.name, bank_accounts.account_number FROM people
  INNER JOIN bank_accounts ON people.id = bank_accounts.person_id
  WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
)
SELECT phone_calls.caller, phone_calls.receiver, people.id, people.name, people.phone_number, people.passport_number, people.license_plate
FROM phone_calls
INNER JOIN people ON phone_calls.caller = people.phone_number
INNER JOIN Q1 ON people.id = Q1.id
INNER JOIN Q2 ON people.id = Q2.person_id
WHERE phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.year = 2021 and phone_calls.duration < 61;
/*
+----------------+----------------+--------+-------+----------------+-----------------+---------------+
|     caller     |    receiver    |   id   | name  |  phone_number  | passport_number | license_plate |
+----------------+----------------+--------+-------+----------------+-----------------+---------------+
| (367) 555-5533 | (375) 555-8161 | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
| (770) 555-1861 | (725) 555-3243 | 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       |
+----------------+----------------+--------+-------+----------------+-----------------+---------------+
*/

-- 15.- See the call recieviers
SELECT * FROM
(SELECT caller, receiver FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 and duration < 60) AS calls
INNER JOIN people AS caller ON calls.caller = caller.phone_number
INNER JOIN people AS receiver ON calls.receiver = receiver.phone_number
WHERE (caller.name = "Bruce" OR caller.name = "Diana");
-- NOTES SUSPECT: THIEF: Diana , ACCOMPLICE: Philip
-- REAL LIKE: THIEF: Bruce , ACCOMPLICE: Robin

-- 16.- CHECK Airports
SELECT * FROM airports WHERE city = "Fiftyville";
-- Abr: id= 8; CSF, Fiftyville Regional Airport

-- 17.- CEHCK FLGHTS from that airport and the day "Earliest Fligth out of FiftyVille tomorrow (7-29-2021)"
SELECT * FROM flights WHERE origin_airport_id IN (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 AND month = 7 AND year = 2021 ORDER BY month, day, hour, minute;
SELECT * FROM flights WHERE origin_airport_id IN (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 AND month = 7 AND year = 2021 ORDER BY month, day, hour, minute LIMIT 1;
--FLIGTH ID: 36 earlist fligth to fiftyville on the next day of the robbery
-- Leaving from fiftyville: 8
-- To: 4 = LGA = LaGuardia Airport = New York City

-- 18.- See the city escaped
SELECT * FROM airports WHERE id = 4;
SELECT * FROM airports WHERE id IN
(SELECT destination_airport_id FROM flights WHERE origin_airport_id IN
(SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 AND month = 7 AND year = 2021 ORDER BY month, day, hour, minute LIMIT 1);
-- Leaving from fiftyville: 8
-- To: 4 = LGA = LaGuardia Airport = New York City

-- 19.- Passports of passengers on fligth
SELECT passport_number FROM passengers WHERE flight_id IN
(SELECT destination_airport_id FROM flights WHERE origin_airport_id IN
(SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 AND month = 7 AND year = 2021 ORDER BY month, day, hour, minute LIMIT 1);

-- 19.- Passports and names of passengers on fligth
SELECT passengers.passport_number, people.name FROM passengers
INNER JOIN flights ON passengers.flight_id = flights.id
INNER JOIN people ON passengers.passport_number = people.passport_number
WHERE flight_id IN
(SELECT id FROM flights WHERE origin_airport_id IN
(SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 AND month = 7 AND year = 2021 ORDER BY month, day, hour, minute LIMIT 1);
/*
+-----------------+--------+
| passport_number |  name  |
+-----------------+--------+
| 7214083635      | Doris  |
| 1695452385      | Sofia  |
| 5773159633      | Bruce  |
| 1540955065      | Edward |
| 8294398571      | Kelsey |
| 1988161715      | Taylor |
| 9878712108      | Kenny  |
| 8496433585      | Luca   |
+-----------------+--------+
*/

-- 20.- FINAL RESULTS - Merging passengers with the calls and get their partners in crime
WITH Q1 AS (
  SELECT passengers.passport_number, people.name FROM passengers
  INNER JOIN flights ON passengers.flight_id = flights.id
  INNER JOIN people ON passengers.passport_number = people.passport_number
  WHERE flight_id IN
  (SELECT id FROM flights WHERE origin_airport_id IN
  (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 AND month = 7 AND year = 2021 ORDER BY month, day, hour, minute LIMIT 1)
),
Q2 AS (
  SELECT caller.name AS caller_name, receiver.name AS receiver_name FROM
  (SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 and duration < 60) AS calls
  INNER JOIN people AS caller ON calls.caller = caller.phone_number
  INNER JOIN people AS receiver ON calls.receiver = receiver.phone_number
  WHERE (caller.name = "Bruce" OR caller.name = "Diana")
)
SELECT Q1.name, Q2.caller_name AS thief, Q2.receiver_name AS accomplice FROM Q1 INNER JOIN Q2 ON Q1.name = Q2.caller_name;

-- RESULT
/*
+-------+-------+------------+
| name  | thief | accomplice |
+-------+-------+------------+
| Bruce | Bruce | Robin      |
+-------+-------+------------+
*/
