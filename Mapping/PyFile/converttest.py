import maplib
import sys

'''
test1 = maplib.MatrixMap(file = sys.argv[1], importData=True)

test2 = maplib.convertMatrixToNodeVertex(test1, file = "./ignore.map")

test2.saveInfo()

print("Continue?")
input()
'''

test1 = maplib.NVMap(sys.argv[1], importData=True)

test2 = maplib.convertNodeVertexToMatrix(test1, file = "./ignore.map")

test2.saveInfo()
