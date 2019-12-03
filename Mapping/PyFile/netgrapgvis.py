import networkx as nx
import matplotlib.pyplot as plt
import maplib

test = maplib.NVMap(file = "../Maps/example_nv.map")

test.debugPrintInfo()

G=nx.Graph()
G.add_nodes_from(list(test.nodes.keys()))

verticiesName = {}

for vert in list(test.vertices.values()):
    G.add_edge(vert.fromNode, vert.toNode, weigth=vert.weight)
    verticiesName[(vert.fromNode, vert.toNode)] = vert.name

graph_pos=nx.spring_layout(G)

nx.draw_networkx_nodes(G,graph_pos)
nx.draw_networkx_labels(G,graph_pos)
nx.draw_networkx_edges(G,graph_pos)
nx.draw_networkx_edge_labels(G,graph_pos, edge_labels=verticiesName)

plt.savefig("simple_path.png")
plt.show() 


