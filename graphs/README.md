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
- 