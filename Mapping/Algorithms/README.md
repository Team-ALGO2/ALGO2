# Mapping Algorithms

> NOTE: Mark Non-Working Algorithms With `x-` 

## Dikjtra
Used to find smallest path from one node to any other node with non-negative weigth on vertices.  
An example of its usage could be google maps and finding shortest route.

## Bellman-Ford
Does the same thing as Dikjtra, but it can handle negative weigths. In return, it detect nagative cycles.  

## Floyd-Warshall
Used to find smallest path from all nodes to all other nodes (All Pair Shortest Paths)

## Kruskal 
Used to find minimun spanning tree. The shortest route that goes througth all the nodes.  
An example of this would be in a delivery service that has to go to all houses.

## Prim
Used to find minimun spanning tree, similar to Kruskals. Major difference is Prim scans by nodes, while Kruskals scans by verticies.
