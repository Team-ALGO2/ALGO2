import maplib
import sys

test = maplib.MatrixMap(file = sys.argv[1], importData=True)

test.debugPrintInfo()

test.file = "./ignore.map"

test.saveInfo()