# Algorithms & outputs

The output and correctness of each algorithm – You should summarize, visualize, or highlight some part of the full-scale run of each algorithm. Additionally, the report should briefly describe what tests you performed to confirm that each algorithm was working as intended.

## Breadth-First Search (BFS)
This algorithm was used for 

## Dijkstra's algorithm
Dijkstra's algorithm is used for determining the shortest path in a graph from any given vertex to a different one. One of the main differences between Dijkstra's and BFS is that unlike BFS, Dijkstra's can be used to determine shortest path while taking edge weightages into account. BFS will only work on unweighted graphs. So in the context of our problem and program, if we use a dataset of airplane routes that includes a data attribute representing distance between airports, we can factor that attribute in to our final shortest path calcualtion, so that instead of returning paths that simply have the least number of layovers, we can filter out those paths so only the ones with shortest distance AND least layovers remains. So for example, if we were looking for flights from CMI to SFO (Champaign to San Francisco), instead of returning a trip from CMI to MIA to SFO (stopover in Miami), Dijkstra's will return CMI to DFW to SFO (stopver in Dallas/Fort Worth). In context of the problem, though both trips have the same number of layovers, it does not make sense to fly away from the destination before going towards it, when you can just have a layover that is at least between the origin and destination. Our test cases of Dijkstra's algorithm uses this same scenario, and you can see that it correctly returns the DFW trip as the output.

## PageRank

## Betweenness Centrality algorithm


# Leading question & answer

The answer to your leading question – You should direct address your proposed leading question. How did you answer this question? What did you discover? If your project was ultimately unsuccessful, give a brief reflection about what worked and what you would do differently as a team.
