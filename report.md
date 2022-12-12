# Algorithms & outputs


## Breadth-First Search (BFS)
This algorithm was used for 

## Dijkstra's algorithm
Dijkstra's algorithm is used for determining the shortest path in a graph from any given vertex to a different one. One of the main differences between Dijkstra's and BFS is that unlike BFS, Dijkstra's can be used to determine shortest path while taking edge weightages into account. BFS will only work on unweighted graphs. So in the context of our problem and program, if we use a dataset of airplane routes that includes a data attribute representing distance between airports, we can factor that attribute in to our final shortest path calcualtion, so that instead of returning paths that simply have the least number of layovers, we can filter out those paths so only the ones with shortest distance AND least layovers remains. So for example, if we were looking for flights from CMI to SFO (Champaign to San Francisco), instead of returning a trip from CMI to MIA to SFO (stopover in Miami), Dijkstra's will return CMI to DFW to SFO (stopver in Dallas/Fort Worth). In context of the problem, though both trips have the same number of layovers, it does not make sense to fly away from the destination before going towards it, when you can just have a layover that is at least between the origin and destination. Our test cases of Dijkstra's algorithm uses this same scenario, and you can see that it correctly returns the DFW trip as the output.

## PageRank

## Betweenness Centrality algorithm
Betweeness Centrality makes use of both BFS and Dijkstra's to calculate the "centrality" of each vertex in the graph, in this case an aipport. Centrality is a measure of how "central" a vertex is with regards to the overall graph, so in context of our problem, it is essentially a numerical value that gives us an idea of which airports are "hubs". So if an airport, such as DFW (Dallas/Fort Worth) has a high centrality value returned by this Betweenness Centrality algorithm, that means it likely has a lot of incoming and outgoing flights and is a pretty important airport with lots of flight paths likely containing it. Betweenness Centrality works with both weighted and unweighted graphs. In the case of an unweighted graph, the algorithm will use BFS, but with weighted, it will implement Dijkstra's. The betweenness centrality algorithm returns a map containing keys which are Nodes representing all airports, and values which are doubles representing the corresponding centrality measures of each airport. Though we implemented the betweenness centrality algorithm, we did not end up using or testing it, as we ran out of time, and it was an extra algorithm on top of the required algorithms.


# Leading question & answer

The answer to your leading question – You should direct address your proposed leading question. How did you answer this question? What did you discover? If your project was ultimately unsuccessful, give a brief reflection about what worked and what you would do differently as a team.
