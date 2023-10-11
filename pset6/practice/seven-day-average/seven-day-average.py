import csv
import requests


def main():
    # Read NYTimes Covid Database
    # The distribution code for this problem uses the python requests library to access the New York Times data stored in an accessible GitHub repository.
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    # {} for Dictionaries = dict()

    """NOTE: In Python, you can't directly declare a dictionary with a fixed size. """
    new_cases = {}
    previous_cases = {}

    for row in reader:
        state = row['state']
        cases = int(row['cases'])

        # Here state is our "key"
        # If it already exists on our new_cases dictionary
        if state in new_cases:
            if len(new_cases[state]) >= 14:
                """Check if the list already contains 14 elements. If it does, you can remove the oldest element"""
                new_cases[state].pop(0)
                """Remove the first (oldest) element"""

                # append the cases we find to that state
            new_cases[state].append(cases - previous_cases[state])
                # will always hold the last known number of cases for that state.
            previous_cases[state] = cases

        # If we dont find that "Key" or state, we create a new index or key with that state
        # and append our first new value
        # Like a hash maps and his nodes
        else:
            # initialize new_cases[state] as a list and add new cases
            new_cases[state] = [cases]
            previous_cases[state] = cases

    return new_cases

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    average = 0
    old_average = 0

    # Iterate over the states list instead of the new_cases dictionary.
    for state in states:
        # For each state, get the list of new cases from the new_cases dictionary.
        if (len(new_cases[state]) >= 7):
           """ gets the last 7 elements of the list, and sum() adds them up """
           average = sum(new_cases[state][-7:])
           old_average = sum(new_cases[state][0:8])
        else:
            average = sum(new_cases[state])

        try:
            average = average / 7
            old_average = old_average / 7

            old_average = (average - old_average) / old_average * 100
        except ZeroDivisionError:
            old_average = 0

        #The "old average" would typically refer to the 7-day average from the previous week. If you're storing daily case numbers in a list,
        # you could calculate this by taking the average of the 8th to 14th last elements in the list.

        if (old_average > 0):
            percentil = "increase"
        else:
            percentil = "decrease"

        # The str() function is used to convert the average to a string so it can be concatenated with the other strings in the print statement.
        print(f"{state} had a 7-day average of {average:0.0f} and a {percentil} of {abs(old_average):0.0f}%.")
        # In this code, {average:.2f} formats the average variable as a floating-point number with 2 digits after the decimal point.

main()
