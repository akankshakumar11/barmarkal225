# CS225 C++ Final Project: Flight Itinerary Generator
Generates possible flight itineraries from user-inputted start and end airports to calculate the quickest paths with the least amount of layovers/connections.


# Project Proposal

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

