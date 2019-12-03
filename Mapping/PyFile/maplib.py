import sys

class Node:
    def __init__(self, nodeId, name):
        self.nodeId = nodeId
        self.name = name

class Vertice:
    def __init__(self, vertexId, name, fromNode, toNode, weight):
        self.vertexId = vertexId
        self.name = name
        self.fromNode = fromNode
        self.toNode = toNode
        self.weight = weight

class NVMap:
    def __init__(self, file = None):
        self.file = file
        self.nodes = {}
        self.vertices = {}
        self.startNode = None
        self.endNode = None
        self.description = None
        if (file != None):
            self.resetInfo()

    def resetInfo(self): 
        with open(self.file) as fp:
            if fp.readline().replace("\n", "") != "NV":
                print("Error Reading Map File. Incompatible Type!")
            else:
                nodeNum = int(fp.readline().replace("\n", ""))
                vertexNum = int(fp.readline().replace("\n", ""))
                for nodeId in range(nodeNum):
                    line = fp.readline().replace("\n", "")
                    data = line.split(" ")
                    self.setNode(nodeId, data[0])
                for vertexId in range(vertexNum):
                    line = fp.readline().replace("\n", "")
                    data = line.split(" ")
                    self.setVertice(vertexId, data[0], data[1], data[2], data[3])
                self.startNode, self.endNode = fp.readline().replace("\n", "").split(" ")
                self.startNode = self.startNode if self.startNode != 0 else None
                self.endNode = self.endNode if self.endNode != 0 else None
                self.description = fp.readline().replace("\n", "")

    def setNode(self, nodeId, name):
        node = Node(nodeId, name)
        self.nodes[str(name)] = node

    def setVertice(self, vertexId, name, fromNode, toNode, weigth):
        vertex = Vertice(vertexId, name, fromNode, toNode, weigth)
        self.vertices[str(name)] = vertex

    def debugPrintInfo(self):
        print(self.file)
        print(self.nodes)
        print(self.vertices)
        print(self.description)
        for vert in list(self.vertices.values()):
            print(vars(vert))
        for node in list(self.nodes.values()):
            print(vars(node))


