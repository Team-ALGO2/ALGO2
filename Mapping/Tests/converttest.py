import sys
import maplib

'''
test1 = maplib.MatrixMap(file = sys.argv[1], importData=True)

test2 = maplib.convertMatrixToNodeVertex(test1, file = "./ignore.map")

test2.saveInfo()


test1 = maplib.NVMap(sys.argv[1], importData=True)

test2 = maplib.convertNodeVertexToMatrix(test1, file = "./ignore.map")

test2.saveInfo()
'''

test1 = maplib.MatrixMap(file = sys.argv[1], importData=True)

test2 = maplib.convertMatrixToNodeVertex(test1, file = "./ignore.map")

test2.saveInfo()

print("Continue?")
input()

test2 = maplib.NVMap(file = "./ignore.map", importData=True)

test3 = maplib.convertNodeVertexToMatrix(test2, file = "./ignore.map")

test3.saveInfo()