import sys

class Node:
    def __init__(self, nodeId, name):
        self.nodeId = nodeId
        self.name = name

class Vertex:
    def __init__(self, vertexId, name, fromNode, toNode, weight):
        self.vertexId = vertexId
        self.name = name
        self.fromNode = fromNode
        self.toNode = toNode
        self.weight = weight

class NVMap:
    def __init__(self, file = None, importData = False):
        self.file = file
        self.nodes = {}
        self.vertices = {}
        self.startNode = None
        self.endNode = None
        self.description = None
        if (importData == True):
            self.resetInfo()

    def resetInfo(self): 
        with open(self.file) as fp:
            if fp.readline().replace("\n", "") != "NV":
                raise Exception("Error Reading Map File. Incompatible Type (Not NV)!")
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
                    self.setVertex(vertexId, data[0], data[1], data[2], data[3])
                self.startNode, self.endNode = fp.readline().replace("\n", "").split(" ")
                self.startNode = self.startNode if self.startNode != 0 else None
                self.endNode = self.endNode if self.endNode != 0 else None
                self.description = fp.readline().replace("\n", "")

    def setNode(self, nodeId, name):
        node = Node(nodeId, name)
        self.nodes[str(name)] = node

    def setVertex(self, vertexId, name, fromNode, toNode, weigth):
        vertex = Vertex(vertexId, name, fromNode, toNode, weigth)
        self.vertices[str(name)] = vertex

    def deleteNode(self, name):
        del self.nodes[str(name)]

    def deleteVertex(self, name):
        del self.vertices[str(name)]

    def saveInfo(self):
        if(self.file != None):
            with open(self.file, "w") as fp:
                fp.write(f"NV\n{len(self.nodes)}\n{len(self.vertices)}\n")
                for node in list(self.nodes.values()):
                    fp.write(f"{node.name}\n")
                for vertex in list(self.vertices.values()):
                    fp.write(f"{vertex.name} {vertex.fromNode} {vertex.toNode} {vertex.weight}\n")
                fp.write(f"{self.startNode} {self.endNode}\n")
                fp.write(f"{self.description}")
        else:
           raise Exception("Map Save Failed! File Is Not Set!") 

    def debugPrintInfo(self):
        print(self.file)
        print(self.nodes)
        print(self.vertices)
        print(self.description)
        for vert in list(self.vertices.values()):
            print(vars(vert))
        for node in list(self.nodes.values()):
            print(vars(node))

class MatrixMap:
    def __init__(self, file = None, importData = False):
        self.file = file
        self.nodes = []
        self.vertices = 0
        self.enableName = False
        self.weightMap = []
        self.connectMap = []
        self.nameMap = None
        self.startNode = None
        self.endNode = None
        self.description = None
        if (importData == True):
            self.resetInfo()

    def generateEmptyMaps(self, size):
        self.weightMap = [[0 for i in range(size)] for j in range(size)]
        self.connectMap = [[0 for i in range(size)] for j in range(size)]
        if(self.enableName):
           self.nameMap = [["0" for i in range(size)] for j in range(size)]

    def resetInfo(self): 
        with open(self.file) as fp:
            if fp.readline().replace("\n", "") != "MATRIX":
                raise Exception("Error Reading Map File. Incompatible Type (Not MATRIX)!")
            else:
                nodeNum = int(fp.readline().replace("\n", ""))
                vertexNum = int(fp.readline().replace("\n", ""))
                self.vertices = vertexNum
                enableName = bool(int(fp.readline().replace("\n", "")))
                self.enableName = enableName
                for nodeId in range(nodeNum):
                    line = fp.readline().replace("\n", "")
                    self.nodes.append(line)
                for nodeId in range(nodeNum):
                    line = fp.readline().replace("\n", "")
                    self.weightMap.append([int(x) for x in line.split(" ")])
                for nodeId in range(nodeNum):
                    line = fp.readline().replace("\n", "")
                    self.connectMap.append([int(x) for x in line.split(" ")])
                if(enableName):
                    self.nameMap = []
                    for nodeId in range(nodeNum):
                        line = fp.readline().replace("\n", "")
                        self.nameMap.append(line.split(" "))
                self.startNode, self.endNode = fp.readline().replace("\n", "").split(" ")
                self.startNode = self.startNode if self.startNode != 0 else None
                self.endNode = self.endNode if self.endNode != 0 else None
                self.description = fp.readline().replace("\n", "")

    def saveInfo(self):
        if(self.file != None):
            with open(self.file, "w") as fp:
                fp.write(f"MATRIX\n{len(self.nodes)}\n{self.vertices}\n{int(self.enableName)}\n")
                for nodeId in range(len(self.nodes)):
                    fp.write(f"{self.nodes[nodeId]}\n")
                for nodeId in range(len(self.nodes)):
                    fp.write(f"{' '.join([str(x) for x in self.weightMap[nodeId]])}\n")
                for nodeId in range(len(self.nodes)):
                    fp.write(f"{' '.join([str(x) for x in self.connectMap[nodeId]])}\n")
                if(self.enableName):
                    for nodeId in range(len(self.nodes)):
                        fp.write(f"{' '.join(self.nameMap[nodeId])}\n")
                fp.write(f"{self.startNode} {self.endNode}\n")
                fp.write(f"{self.description}")
        else:
           raise Exception("Map Save Failed! File Is Not Set!") 

    def debugPrintInfo(self):
        print(self.file)
        print(self.nodes)
        print(self.weightMap)
        print(self.connectMap)
        print(self.nameMap)
        print(self.startNode)
        print(self.endNode)
        print(self.description)

def convertMatrixToNodeVertex(matrix, file=None):
    NV = NVMap(file = file)
    NV.startNode = matrix.startNode
    NV.endNode = matrix.endNode
    NV.description = matrix.description

    vertexId = 0
    for nodeFrom in range(len(matrix.nodes)):
        NV.setNode(nodeFrom, matrix.nodes[nodeFrom])
        for nodeTo in range(len(matrix.nodes)):
            if(matrix.connectMap[nodeFrom][nodeTo] == 1):
                if(matrix.enableName):
                    vertexName = matrix.nameMap[nodeFrom][nodeTo]
                else:
                    vertexName = "NoName"
                NV.setVertex(vertexId, vertexName, matrix.nodes[nodeFrom], matrix.nodes[nodeTo], matrix.weightMap[nodeFrom][nodeTo])

    return NV

'''
self.file = file
self.nodes = []
self.vertices = 0
self.enableName = False
self.weightMap = []
self.connectMap = []
self.nameMap = None
self.startNode = None
self.endNode = None
self.description = None
'''

'''
self.file = file
self.nodes = {}
self.vertices = {}
self.startNode = None
self.endNode = None
self.description = None
'''

def convertNodeVertexToMatrix(NV, file=None, enableName = True):
    matrix = MatrixMap(file = file)
    matrix.startNode = NV.startNode
    matrix.endNode = NV.endNode
    matrix.description = NV.description
    matrix.enableName = enableName
    matrix.nodes = list(NV.nodes.keys())
    matrix.vertices = len(NV.vertices)

    matrix.generateEmptyMaps(len(NV.nodes))

    for vertex in list(NV.vertices.values()):
        fromNode = matrix.nodes.index(vertex.fromNode)
        toNode = matrix.nodes.index(vertex.toNode)
        matrix.weightMap[fromNode][toNode] = vertex.weight
        matrix.connectMap[fromNode][toNode] = 1
        if(enableName):
            matrix.nameMap[fromNode][toNode] = vertex.name

    return matrix
