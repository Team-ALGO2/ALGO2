#Imprting Required Libraries
import networkx as nx
import matplotlib.pyplot as plt
import maplib
import sys

#Create Map File
test = maplib.NVMap(file = sys.argv[1], importData=True)

#Print Map Info
test.debugPrintInfo()

#Add Nodes Onto Graph
G=nx.Graph()
G.add_nodes_from(list(test.nodes.keys()))

#Add Verticies Onto Gtaph
verticiesName = {}
for vert in list(test.vertices.values()):
    G.add_edge(vert.fromNode, vert.toNode, weigth=vert.weight)
    verticiesName[(vert.fromNode, vert.toNode)] = vert.name

#Generate Graph Object
graph_pos=nx.spring_layout(G)

#Draw Elements Onto Graph
nx.draw_networkx_nodes(G,graph_pos)
nx.draw_networkx_labels(G,graph_pos)
nx.draw_networkx_edges(G,graph_pos)
nx.draw_networkx_edge_labels(G,graph_pos, edge_labels=verticiesName)

#Export Graph
plt.savefig("graph_result.png")
plt.show() 


