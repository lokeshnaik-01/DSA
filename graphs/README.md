# Graph Concepts
## Bi Partite Graph
- A bipartite graph is a graph in which the vertices can be divided into two disjoint sets, such that no two vertices within the same set are adjacent. In other words, it is a graph in which every edge connects a vertex of one set to a vertex of the other set.

- graphs with even cycle length can be bipartite 
- graphs with odd cycle length can never be bipartite

## Cycle detection in graphs
- for detecting cycle in undirected and directed graph is different.
- consider 1-->2--->3-->4 here there is no cycle but if we use dfs algo which checks the parent as in undirected graph it says cycle detected
-              |    |
-              v    v
-              5--->6


## Dijkstra's
- it is not applicable for graphs with negative edge weight
- consider 0--------->1 node weight(-2) it will keep on going for ever and will fall in an infinite loop
- Time Complexity is ElogV ---> E is total no of edges, V is no of nodes
- if queue is used all the paths are passed
- if we used priority_queue unnecessary iterations will be removed by traversing only the minimal first
- time complexity
`O(v*(pop vertex from min heap+no of edges on each vertex*push into min heap))
O(V*(log(heap size)+ne*log(heap size)))
O(V*(log(heap size)*(ne+1)))
ne can be v-1 in case of condesned graph which is all the nodes are connected
O(V*log(heap size)*(V-1+1))
O(V^2*log(heap size))
heap size can be (V^2) in extreme case
O(V^2*log(V^2))
V^2 = E total edges
O(2*Elog(V))
O(ElogV)`