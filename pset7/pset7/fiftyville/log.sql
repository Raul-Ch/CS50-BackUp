-- Keep a log of any SQL queries you execute as you solve the mystery.
-- All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.

-- 1.- Check the type of info table crime_scene_reports had
SELECT * FROM crime_scene_reports LIMIT 5;

-- 2.- Check the crimes on Humphery Street
SELECT * FROM crime_scene_reports WHERE street = "Humphrey Street";
    -- NOTES: Humphrey Street | Theft of the CS50 duck three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
        -- Notes: Robbery at 10:15 am

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

-- 5.- Check the type of info (columns) table secutirylogs had
SELECT * FROM bakery_security_logs LIMIT 5;

-- 6.- Check the logs with the same of day, month, year and time of the crime
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute > 15;
    -- Notes: There are 2 plates within the 10 minutes mark at 10:23 that exit and one at 10:35 being;
        -- 322W7JE, 0NTHK55 and 1106N58

-- CAR FOOTAGE
-- 7.- Check the people table with the plates given
SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute > 15);
-- or
SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE license_plate = "322W7JE" OR license_plate = "0NTHK55" OR license_plate = "1106N58");
/*
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55
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
    -- Theres a Total of 8 transactions with the respective account_number
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
(SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE license_plate = "322W7JE" OR license_plate = "0NTHK55" OR license_plate = "1106N58")) AS Q1
INNER JOIN
(SELECT bank_accounts.person_id, people.name, bank_accounts.account_number FROM people INNER JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")) AS Q2
ON Q1.id = Q2.person_id;
/*
+--------+--------+----------------+-----------------+---------------+-----------+--------+----------------+
|   id   |  name  |  phone_number  | passport_number | license_plate | person_id |  name  | account_number |
+--------+--------+----------------+-----------------+---------------+-----------+--------+----------------+
| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       | 514354    | Diana  | 26013199       |
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       | 449774    | Taylor | 76054385       |
+--------+--------+----------------+-----------------+---------------+-----------+--------+----------------+
*/ -- NOTES: Diana and Taylor as suspects
            --NOTES FROM INTERVIEWS: Car - Footage from the bakery 10 minutes of the thieft = 10:25
-- Diana is the principal suspect, beacause taylor plate was registeres at 10:35 more than minutes after the robbery

-- 13.- Check the phone Calls on the same day of the robbery
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 and duration < 60;

-- 14.- Compare last querie with suspects
SELECT * FROM phone_calls INNER JOIN people ON phone_calls.caller = people.phone_number WHERE day = 28 AND month = 7 AND year = 2021 and duration < 60 AND (people.name = "Diana" OR people.name = "Taylor");
/*
+-----+----------------+----------------+------+-------+-----+----------+--------+--------+----------------+-----------------+---------------+
| id  |     caller     |    receiver    | year | month | day | duration |   id   |  name  |  phone_number  | passport_number | license_plate |
+-----+----------------+----------------+------+-------+-----+----------+--------+--------+----------------+-----------------+---------------+
| 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       | 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       | 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
+-----+----------------+----------------+------+-------+-----+----------+--------+--------+----------------+-----------------+---------------+
*/

-- 15.- See the call recieviers
SELECT * FROM
(SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 and duration < 60) AS calls
INNER JOIN people AS caller ON calls.caller = caller.phone_number
INNER JOIN people AS receiver ON calls.receiver = receiver.phone_number
WHERE (caller.name = "Diana" OR caller.name = "Taylor");
-- NOTES SUSPECT: THIEF: Taylor , ACCOMPLICE: James
-- REAL LIKE: THIEF: Diana , ACCOMPLICE: Philip

-- 16.- CHECK Airports
SELECT * FROM airports WHERE city = "Fiftyville";
-- Abr: id= 8; CSF, Fiftyville Regional Airport

-- 17.- CEHCK FLGHTS from that airport and the day "Earliest Fligth to FiftyVille tomorrow (7-29-2021)"
SELECT * FROM flights WHERE origin_airport_id IN (SELECT id FROM airports WHERE city = "Fiftyville");

