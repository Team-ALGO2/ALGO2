import networkx as nx
import matplotlib.pyplot as plt
import maplib

test = maplib.Map(file = "../Maps/map1.map")

G=nx.Graph()
G.add_nodes_from(list(test.nodes.keys()))

for vert in list(test.vertices.values()):
    G.add_edge(vert.fromNode, vert.toNode, weigth=vert.weight)

graph_pos=nx.spring_layout(G)

nx.draw_networkx_nodes(G,graph_pos)
nx.draw_networkx_edges(G,graph_pos)

plt.savefig("simple_path.png")
plt.show() 


