import sys

class Node:
    def __init__(self, nid, distanceTo):
        self.nid = nid
        self.distanceTo = distanceTo

class Vertice:
    def __init__(self, fromNode, toNode, weight):
        self.fromNode = fromNode
        self.toNode = toNode
        self.weight = weight

class Map:
    def __init__(self, file = None):
        self.file = file
        self.nodes = {}
        self.vertices = {}
        self.description = None
        if (file != None):
            self.resetInfo()

    def resetInfo(self): 
        with open(self.file) as fp:
            nodeNum = int(fp.readline())
            verticeNum = int(fp.readline())
            for a in range(nodeNum):
                line = fp.readline()
                data = line.split(" ")
                if(len(data) > 2):
                    self.setNode(data[0], data[1], data[2])
                else:
                    self.setNode(data[0], data[1], None)
            for b in range(verticeNum):
                line = fp.readline()
                data = line.split(" ")
                self.setVertice(data[0], data[1], data[2], data[3])
            self.description = fp.readline()

    def setNode(self, name, nid, distanceTo):
        node = Node(nid, distanceTo)
        self.nodes[str(name)] = node

    def setVertice(self, name, fromNode, toNode, weigth):
        vertice = Vertice(fromNode, toNode, weigth)
        self.vertices[str(name)] = vertice

    def debugPrintInfo(self):
        print(self.file)
        print(self.nodes)
        print(self.vertices)
        print(self.description)
