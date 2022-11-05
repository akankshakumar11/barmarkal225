# CS225 C++ Final Project: Flight Itinerary Generator
Generates possible flight itineraries from user-inputted start and end airports to calculate the quickest paths with the least amount of layovers/connections.


# Project Proposal
## Leading Question
Given the airport dataset from OpenFlights, what is the quickest route/flight itinerary from any valid user-inputted origin airport to any valid user-inputted destination airport, with the least number of layovers/connections?

## Dataset Acquisition
We will acquire our flight/airport dataset from the website OpenFlights.org. The dataset we will be working with is a CSV file that contains a data entry of every airport in the world, along with its location and IATA code. There is an option available of downloading and working with "airports-extended.dat", which contains train stations and ferry terminals in addition to airports, but we will not be using this dataset while working on our project because we would like to start with a simpler version first and ensure that our code works on a base level. Later on, we may be able to modify our code to accommodate for train stations and ferries too. However, for now, we will focus on just airport data. 

## Data Format
As stated above, we will acquire our dataset from OpenFlights.org. The dataset we will be working with is a CSV file titled "airports.dat", which contains a data entry of every airport in the world, along with its location and IATA code, in addition to other relevant characteristics. The file we are using contains 14110 airport data entries. For initial testing, we will use a small subset of approximately 100 airports, preferrable from different countries and continents, and then when we are sure our code works, we will graduate to the overall dataset and test and finalize using that. 

## Data Correction
With regards to data correction, we will first experiement manually with the dataset using Python on Google Colab to determine whether there are any glaring errors or inconsistencies. After filtering out the statistics and characteristics that are not relevant to our project and leading question, we will then simply test on that filtered data, and if we happen to run into any errors while testing that are not resulting from bugs in our code, then we will sift through the dataset and our failed test cases to figure out what the issue is and further adjust our filtered dataset to accommodate for those issues.

## Data Storage
We plan on using a map to store the dataset itself. The key in this dataset map will be an airports IATA code, as that is how we plan on having the users input their desired origin and destination airports IDs. The value of the dataset map will be an array of anyother criteria/characteristics of an airport that we deem necessary for our algorithm later on. The index of this array will correspond to a different characteristic, so for example arrray[0] of the value of a given key will give that airport's location as a string, while array[1] will give the exact latitude/longitude position. Additionally, as a part of our algorithm we will be using a stack for our DFS (depth first search). In the event that we use additional data structures in our code, we will update this section with those structures and their respective purposes. The runtime for our algorithm as of now should be $O(n^2)$ for the storage portion of the algorithm/the function(s) that parse and store our data structure. One $n$ will be from iterating through the map for the key, and the other $n$ will be from storing the remainining characteristics in the value arrays.

## Algorithm
The expected input for our algorithm is the airport dataset itself, and the user input, which would be two IATA codes that correspond to the desired origin and destination airports. Our airport data is in a large CSV file. We will parse through this CSV file using read functions, and store this information in our map structure, as discussed in the Data Storage section. Once we are done constructing this storage map, the next step is traversing through the stored data in order to find the shortest path. For this, we will be using a stack and DFS. Djikstra’s Algorithm is used for finding the shortest path between two nodes on a graph. We will begin by using this algorithm, using the stored data as an inpt and expecting an array of IATA codes representing the output of the best flight itinerary; however, we will also incorporate the A* algorithm. For this algorithm, we will set up weighted edges connecting the keys of the map (which represent the nodes), and the nodes will be weighted based on how many flights enter/leave per day from that airport, which basically is a measure of airport popularity and convenience for flight booking/availability. We will additionally incorporate the PageRank algorithm to further aid in determining the order of airport popularity, which will finally help in determining the absolute best possible flight itinerary given the origin and destination IATAs.

## Timeline
In terms of timeline, our goal for this week was to formulate a rough plan for the remainder of our project, including the specific data structures and algorithms we need to construct working code that answers/solves our leading question. We also created a document where we have compiled resources and articles and documentation regarding the algorithms listed above in the algorithm section in order for us to understand these algorithms and then smoothly construct and carry the our overall program. By next week, we would like to have a working read/parse/store function that reads in the airports.dat CSV file and properly stores it in our data structure (in our case, a map, although this may be subject to change if we discuss and determine a more efficient structure). We will begin working on our actual popularity and traversal and path calculation algorithms in the weeks following, but as for now, our main goal is to figure our the parsing and storing of the dataset by next week.

# Team Contract

## Communication
1. **Team Meetings** 
We intend on meeting 2-3 times a week for around 1-2 hours over Zoom or in person. At the end of
each meeting, we will assign one person to record the progress we have made on the project. 
2. **Assistance** 
We will be able to contact each other through text/Messenger anytime one of us need help, and everyone will be expected to answer within 8 hours. Since we see each other fairly often in person, we will also be able to ask each other questions then. 
3. **Respect** 
To ensure every member is equally involved in the project, we will keep each other updated on
our progress and ask for each other's opinions before making decisions regarding the project. To ensure that everyone is actively listening and engaging with the thought of others, we will have members bring up alternatives if they do not agree with someone else's suggestion. 
## Collaboration

4. **Work Distribution** 
We will assign work at the end of each meeting based on each team member's interests and experience. We will assess our progress at each meeting and ensure that we are not heavily impacted by unexpected applications. 
5. **Time Commitment** 
We expect each memeber ot complete 4-5 hours of work per week. We understand that each member has other commitments, so this a soft expectation. As long as each member is equally committed, we will not enforce a hard rule. We will address new conflicts or committments by approaching the issue with understanding while also prioritizing our progress. This can include altering our initial plans for the project. 
6. **Conflict Resolution** 
 When disagreements occur between team members, we will first have each member explain their thoughts and proceed to take a vote on the matter. If one or more members do not complete their tasks, we will check in with that member and hold them accountable based on their state at that time. We will try to be understanding about the situation, but we do expect prior notice about any issues. If a member is habitually late, we will ask if our current schedule is okay and we will reiterate the importance of being on time since we all have busy schedules. We also will use meetings to discuss other issues, whether they relate to logistics or road blocks. 
## Signatures
Shreya Kalyanasundaram  Ananya Barman           Akanksha Kumar
(shreyak8)                  (ananyab3)          			(kumar65)

__________________________________________________________________________________________________________________________________________________________________

# Project Structure
The project structure is created to maximize modularity, increase compartmentalization, and make use of tools through CMake. Each sub-project of the overall project has its own folder, wherein each contains its own test, main methods, CMake files, and header files, thus increasing modularity of the overall project. Thus, each sub-project can actually stand alone on its own, and we add them here together much like applications rather than a hard-stuck part of the project. An example project structure is shown below for better visualization of the structure:
```
project/
> parsing/
    > include/
        - ...header files
    > src/
        - ...src files
    - main.cpp
    - CMakeLists.txt
> bfs/
    |-- ...
```

This is a very similar structure as all other large open-source code bases like OpenCV as it allows maximum modularity and stand-alone applications. 

# First Time
We will refer to the home project directory as `project/`. If this is your first time with the project and you are unfamiliar with the running scripts, then please execute the following in your command line (Note you must type in the stuff after the dollar sign. The stuff before the `$` symbol denotes the current filepath):

`$ cd project/`

`project$ chmod +x run.sh`

`project$ ./run.sh`

This will run the included script that runs the main method with default arguments and also all tests in each subdirectory. This is just a concatenation of running the bake, tests, and main at once.

# Building Files
We decided to use CMake in this project due to its usefulness in helping us create Makefiles through a list of well-defined macros. The following command will bake the project (Build & Make). Run these in your local terminal. Note, please consider doing all of this on EWS as we assume tools on EWS (like CMake3 etc.).

`project$ ./bake.sh`

# Running Main, Tests
## Main
To run main or tests, you can just execute the main script like so:

`project$ ./main.sh`
<!-- 
The main method also includes some additional input if you would like to play around with the inputs. You can run `./main -h` or `./main --help` for more information on the usage type. The result should print something like:

`Usage: ./main [nodes file] [edges file]`

For example, we provided a fake dataset so you could run the following:

`./main ../data/nodes.csv ../data/edges.csv` -->

Note that everything will be relative to the `src/` directory even though the script is in the `project/` directory.

## Tests
I have made a `test.sh` script that runs all the tests in the subdirectories. You can just run it like so:

`project$ ./test.sh`

and you should see the success on all parts.

