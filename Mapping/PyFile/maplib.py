import sys

#Node Class
class Node:
    def __init__(self, nodeId, name):
        self.nodeId = nodeId
        self.name = name

#Vertex Class
class Vertex:
    def __init__(self, vertexId, name, fromNode, toNode, weight):
        self.vertexId = vertexId
        self.name = name
        self.fromNode = fromNode
        self.toNode = toNode
        self.weight = weight

#Node-Vertex CLass
class NVMap:
    #Initialization Function
    def __init__(self, file = None, importData = False):
        self.file = file
        self.nodes = {}
        self.vertices = {}
        self.startNode = None
        self.endNode = None
        self.description = None
        if (importData == True):
            self.resetInfo()

    #Reset Info From File
    def resetInfo(self): 
        #Open File
        with open(self.file) as fp:
            #Checking Type
            if fp.readline().replace("\n", "") != "NV":
                raise Exception("Error Reading Map File. Incompatible Type (Not NV)!")
            else:
                #Read Information
                #Get Node Amount
                nodeNum = int(fp.readline().replace("\n", ""))
                #Get Vertex Amount
                vertexNum = int(fp.readline().replace("\n", ""))
                #Get Nodes
                for nodeId in range(nodeNum):
                    line = fp.readline().replace("\n", "")
                    data = line.split(" ")
                    self.setNode(nodeId, data[0])
                #Get Vertexes
                for vertexId in range(vertexNum):
                    line = fp.readline().replace("\n", "")
                    data = line.split(" ")
                    self.setVertex(vertexId, data[0], data[1], data[2], data[3])
                #Get Start And End Node
                self.startNode, self.endNode = fp.readline().replace("\n", "").split(" ")
                self.startNode = self.startNode if self.startNode != 0 else None
                self.endNode = self.endNode if self.endNode != 0 else None
                #Get Description
                self.description = fp.readline().replace("\n", "")

    #Create And Save Node
    def setNode(self, nodeId, name):
        node = Node(nodeId, name)
        self.nodes[str(name)] = node

    #Create And Save Vertex
    def setVertex(self, vertexId, name, fromNode, toNode, weigth):
        vertex = Vertex(vertexId, name, fromNode, toNode, weigth)
        self.vertices[str(name)] = vertex

    #Delete Node By Name
    def deleteNode(self, name):
        del self.nodes[str(name)]

    #Delete Vertex By Name
    def deleteVertex(self, name):
        del self.vertices[str(name)]

    #Save Information Into File
    def saveInfo(self):
        if(self.file != None):
            #Open File
            with open(self.file, "w") as fp:
                #Write Type, Node Amount And Vertex Amount
                fp.write(f"NV\n{len(self.nodes)}\n{len(self.vertices)}\n")
                #Write All Nodes
                for node in list(self.nodes.values()):
                    fp.write(f"{node.name}\n")
                #Write All Verticies
                for vertex in list(self.vertices.values()):
                    fp.write(f"{vertex.name} {vertex.fromNode} {vertex.toNode} {vertex.weight}\n")
                #Write Start And End Node
                fp.write(f"{self.startNode} {self.endNode}\n")
                #Write Description
                fp.write(f"{self.description}")
        else:
           raise Exception("Map Save Failed! File Is Not Set!") 

    #Debug Printing
    def debugPrintInfo(self):
        print(self.file)
        print(self.nodes)
        print(self.vertices)
        print(self.description)
        for vert in list(self.vertices.values()):
            print(vars(vert))
        for node in list(self.nodes.values()):
            print(vars(node))

#Matrix Class
class MatrixMap:
    #Initialization Function
    def __init__(self, file = None, importData = False):
        self.file = file
        self.nodes = []
        self.vertices = 0
        self.enableName = False
        self.weightMap = []
        self.connectivityMap = []
        self.nameMap = None
        self.startNode = None
        self.endNode = None
        self.description = None
        if (importData == True):
            self.resetInfo()

    #Generate Empty Matrix
    def generateEmptyMaps(self, size):
        self.weightMap = [[0 for i in range(size)] for j in range(size)]
        self.connectivityMap = [[0 for i in range(size)] for j in range(size)]
        if(self.enableName):
           self.nameMap = [["0" for i in range(size)] for j in range(size)]

    #Reset Info From File
    def resetInfo(self): 
        #Open File
        with open(self.file) as fp:
            #Check Type
            if fp.readline().replace("\n", "") != "MATRIX":
                raise Exception("Error Reading Map File. Incompatible Type (Not MATRIX)!")
            else:
                #Get Node Amount
                nodeNum = int(fp.readline().replace("\n", ""))
                #Get Vertex Amount
                vertexNum = int(fp.readline().replace("\n", ""))
                self.vertices = vertexNum
                #Get Name Boolean
                enableName = bool(int(fp.readline().replace("\n", "")))
                self.enableName = enableName
                #Get Node Names
                for nodeId in range(nodeNum):
                    line = fp.readline().replace("\n", "")
                    self.nodes.append(line)
                #Get Node Matrix
                for nodeId in range(nodeNum):
                    line = fp.readline().replace("\n", "")
                    self.weightMap.append([int(x) for x in line.split(" ")])
                #Get Connectivity Matrix
                for nodeId in range(nodeNum):
                    line = fp.readline().replace("\n", "")
                    self.connectivityMap.append([int(x) for x in line.split(" ")])
                #Check If Name Is Enabled
                if(enableName):
                    self.nameMap = []
                    #Get Name Matrix
                    for nodeId in range(nodeNum):
                        line = fp.readline().replace("\n", "")
                        self.nameMap.append(line.split(" "))
                #Get Start And End Node
                self.startNode, self.endNode = fp.readline().replace("\n", "").split(" ")
                self.startNode = self.startNode if self.startNode != 0 else None
                self.endNode = self.endNode if self.endNode != 0 else None
                #Get Description
                self.description = fp.readline().replace("\n", "")

    def saveInfo(self):
        if(self.file != None):
            #Open File
            with open(self.file, "w") as fp:
                #Write Type, Node Amount and Vertex Amount
                fp.write(f"MATRIX\n{len(self.nodes)}\n{self.vertices}\n{int(self.enableName)}\n")
                #Write Node Names
                for nodeId in range(len(self.nodes)):
                    fp.write(f"{self.nodes[nodeId]}\n")
                #Write Node Matrix
                for nodeId in range(len(self.nodes)):
                    fp.write(f"{' '.join([str(x) for x in self.weightMap[nodeId]])}\n")
                #Write Connectivity Matrix
                for nodeId in range(len(self.nodes)):
                    fp.write(f"{' '.join([str(x) for x in self.connectivityMap[nodeId]])}\n")
                #Check If Name Is Enabled
                if(self.enableName):
                    #Write Name Matrix
                    for nodeId in range(len(self.nodes)):
                        fp.write(f"{' '.join(self.nameMap[nodeId])}\n")
                #Write Start And End Node
                fp.write(f"{self.startNode} {self.endNode}\n")
                #Write Description
                fp.write(f"{self.description}")
        else:
           raise Exception("Map Save Failed! File Is Not Set!") 

    #Print Debug Information
    def debugPrintInfo(self):
        print(self.file)
        print(self.nodes)
        print(self.weightMap)
        print(self.connectivityMap)
        print(self.nameMap)
        print(self.startNode)
        print(self.endNode)
        print(self.description)

#Convert From Matrix To Node Vertex
def convertMatrixToNodeVertex(matrix, file=None):
    #Create Node-Vertex Map Object
    NV = NVMap(file = file)
    #Save Start And End Nodes
    NV.startNode = matrix.startNode
    NV.endNode = matrix.endNode
    NV.description = matrix.description

    vertexId = 0
    #Loop Through All From Nodes
    for fromNode in range(len(matrix.nodes)):
        #Save Nodes
        NV.setNode(fromNode, matrix.nodes[fromNode])
        #Loop Through All To Nodes
        for toNode in range(len(matrix.nodes)):
            #Check If Connected
            if(matrix.connectivityMap[fromNode][toNode] == 1):
                #Check If Name Enabled
                if(matrix.enableName):
                    #Save Name
                    vertexName = matrix.nameMap[fromNode][toNode]
                else:
                    #Generate Name
                    vertexName = "Vertex_" + str(vertexId)
                #Save Vertex
                NV.setVertex(vertexId, vertexName, matrix.nodes[fromNode], matrix.nodes[toNode], matrix.weightMap[fromNode][toNode])
                #Increment VertexId
                vertexId = vertexId + 1

    return NV

#Convert From Matrix To Node Vertex
def convertNodeVertexToMatrix(NV, file=None, enableName = True):
    #Save Mahor Information
    matrix = MatrixMap(file = file)
    matrix.startNode = NV.startNode
    matrix.endNode = NV.endNode
    matrix.description = NV.description
    matrix.enableName = enableName
    matrix.nodes = list(NV.nodes.keys())
    matrix.vertices = len(NV.vertices)

    #Create Empty Matricies
    matrix.generateEmptyMaps(len(NV.nodes))

    #Loop All Vertex
    for vertex in list(NV.vertices.values()):
        #Save Vertex Information Into Matrix
        fromNode = matrix.nodes.index(vertex.fromNode)
        toNode = matrix.nodes.index(vertex.toNode)
        matrix.weightMap[fromNode][toNode] = vertex.weight
        matrix.connectivityMap[fromNode][toNode] = 1
        #Check Name
        if(enableName):
            matrix.nameMap[fromNode][toNode] = vertex.name

    return matrix
