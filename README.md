# CS225 C++ Final Project: Flight Itinerary Generator
This program generates the best possible flight itineraries from user-inputted origin and destination airports to calculate the quickest paths with the least amount of layovers/connections.

# Project presentation:

[link]

# Report:

See file `report.md`

# About our program:

FlightFinder is a program that allows users to select desired origin and destination airports, and then receive a list of the best possible flight itineraries between those given airports. The top flight paths are calculated using data that has been carefully collected and parsed from the public OpenFlights database. Our program takes in user-inputted IATA codes and determines all possible flight paths between the two given airports. Then, it filters the options until only the shortest trips remain, using algorithms such as PageRank and BFS which we will discuss in a moment. Once these best paths are determined, our program ranks the top few options and returns them in sorted order to the user. FlightFinder allows customers all over the world to conveniently determine the most ideal and efficient flight plan for their next upcoming trip, saving them time, hassle, and confusion.

# Running the Tests

1. Download project from GitHub

2. Open in Docker. Follow these instructions if you are unfamiliar: https://courses.engr.illinois.edu/cs225/sp2022/resources/own-machine/.

3. Change directories into the `barmarkal225-main` folder.

4. Run the following commands in order:

  `g++ test.cpp -o test`
  
  `./test`
  
The program will automatically display the tests passed, and out of how many total tests wwe performed.


# Running the program

1. Download project from GitHub

2. Open in Docker. Follow these instructions if you are unfamiliar: https://courses.engr.illinois.edu/cs225/sp2022/resources/own-machine/.

3. Change directories into the `barmarkal225-main` folder.

4. Run the following commands in order:

  `g++ main.cpp -o main`
  
  `./main CMI SFO`
  
The first parameter after `./main` represents the source, or origin airport, while the second parameter represents the destination airport. Our program will automatically perform BFS, Dijkstra's Algorithm, and PageRank based on these input values. Check the console for the results.
