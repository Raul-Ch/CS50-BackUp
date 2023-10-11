# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # This is a LIST [ ]
    teams = []
    # TODO: Read teams into memory from file
    """ The with statement ensures that the file is properly closed after it is no longer needed. """
    with open(sys.argv[1]) as file:
      reader = csv.DictReader(file)

      for row in reader:
        # Here we have our dictionary
            team = {
                "name": row['team'],
                "rating": int(row['rating'])
            }
            # Here we append a team into TEAMS List
            teams.append(team)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    #  if N is an integer, you should use range(N) to loop N times
    # The _ is a common convention in Python for a variable that you don't plan on using.
    # In this case, you don't need to use the loop variable itself; you just want to repeat the loop N times.
    for _ in range(N):
        team_name = simulate_tournament(teams)
        if team_name in counts:
            counts[team_name] += 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    while (len(simulate_round(teams) > 1):
        # Update teams with the winners of each round.
        teams = simulate_round(teams)

    # return the name of the winning team, not the list teams.
    # You can access the name of the winning team with teams[0]["name"]
    return teams[0]["name"]


if __name__ == "__main__":
    main()
