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
        cases = row['cases']

        # Here state is our "key"
        # If it already exists on our new_cases dictionary
        if state in new_cases:
            if len(new_cases[state]) >= 14:
                """Check if the list already contains 14 elements. If it does, you can remove the oldest element"""
                new_cases[state].pop(0)
                """Remove the first (oldest) element"""
                # append the cases we find to that state
                new_cases[state].append(cases)

        # If we dont find that "Key" or state, we create a new index or key with that state
        # and append our first new value
        # Like a hash maps and his nodes
        else:
            # initialize new_cases[state] as a list and add new cases
            new_cases[state] = [cases]
    print(new_cases)
    return new_cases

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    ...


main()
