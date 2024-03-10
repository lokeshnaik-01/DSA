# Graph Concepts
## Bi Partite Graph
- A bipartite graph is a graph in which the vertices can be divided into two disjoint sets, such that no two vertices within the same set are adjacent. In other words, it is a graph in which every edge connects a vertex of one set to a vertex of the other set.

- graphs with even cycle length can be bipartite 
- graphs with odd cycle length can never be bipartite

## Cycle detection in graphs
- for detecting cycle in undirected and directed graph is different.
- consider here there is no cycle but if we use dfs algo which checks the parent as in undirected graph it says cycle detected
```
         1-->2--->3-->4
             |    |
             v    v
             5--->6
```

## Dijkstra's
- it is not applicable for graphs with negative edge weight
- consider 0--------->1 node weight(-2) it will keep on going for ever and will fall in an infinite loop
- Time Complexity is ElogV ---> E is total no of edges, V is no of nodes
- if queue is used all the paths are passed
- if we used priority_queue unnecessary iterations will be removed by traversing only the minimal first
- time complexity
```
O(v*(pop vertex from min heap+no of edges on each vertex*push into min heap))

O(V*(log(heap size)+ne*log(heap size)))

O(V*(log(heap size)*(ne+1)))

ne can be v-1 in case of condesned graph which is all the nodes are connected

O(V*log(heap size)*(V-1+1))

O(V^2*log(heap size))

heap size can be (V^2) in extreme case

O(V^2*log(V^2))

V^2 = E total edges

O(2*Elog(V))

O(ElogV)
```

## Bellman Ford
- bellman ford helps us to detect negative cycles.
- it is only for directed graph. if it is asked for a undirected graph change it to directed by having two side edges with same wright
- Steps
  1. relax all edges n-1 times sequentially n is the number of nodes
  2. `if(dist[u]+edjWt) < dist[v]` same as dijkstra and update `dist[v]` this is called relaxation of edges 
  3. the loop runs for n-1 times because n-1 is the maximum length of a shortest path in a graph with N vertices  1-->2--->3--->4 in this case we need 3 iterations
  4. on nth iteration the distance array will be done, if at nth iteration still there is a decrease in distance we can say there is a loop

## Floyd Warshall Algo (MultiShource shortest path)
- helps in detecting negative cycle
- We use adjacency matrix which will store the cost from one path to another it is called as cost matrix
- cost[u][v] via k --> cost[u][k] + cost[k][v]
- we do the above for all parts via every node

## Spanning Tree
- a tree in which we have n nodes and n-1 edges and all nodes are reachable from each other is called Spanning tree
## MST
- tree with minimum sum is called spanning tree

## Prim's algo
- We will have a priority_queue and a visited array
  1. start with some node and and push it into priority_queue (node, 0, parent(-1)) and mark it as vis
  2. push adjacent nodes into the priority_queue
  3. repeat 1 and 2

## Disjoint Sets
- used in dynamic graphs which change constantly
- will tell us if two nodes belong to same component or not.
- it will be done in constant time instead of the linear time complexity using dfs and bfs
- `findParent` and `Union` are the two functions
- union in disjoint set connect two nodes
- Union can be implemented using two ways
  1. Rank (Union by Rank)
  2. Size (Union by Size)

### Rank
- assig a rank array and parent array assign rank array to be 0
- parent node will be parent of itself
```
- Union(u,v)
  1. find ultimate parent of u & v---> pu, pv
  2. find rank of pu and pv
  3. connect smaller rank to larger rank always
```