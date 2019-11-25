import networkx as nx
import matplotlib.pyplot as plt


G=nx.Graph()
G.add_nodes_from(["a", "b","c", "d"])

G.add_edge("a", "b", weigth=10)
G.add_edge("a", "c", weigth=10)
G.add_edge("b", "c", weigth=10)
G.add_edge("b", "d", weigth=10)
G.add_edge("c", "d", weigth=10)

graph_pos=nx.spring_layout(G)

nx.draw_networkx_nodes(G,graph_pos)
nx.draw_networkx_edges(G,graph_pos)

plt.savefig("simple_path.png")
plt.show() 


