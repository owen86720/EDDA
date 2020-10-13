# import struct
import numpy as np

# decoded = []
# with open("pf01.bin", "rb") as f:
#     byte = f.read(4)
#     while byte:
#         # Do stuff with byte.
#         value = struct.unpack('<f', byte)[0]
#         decoded.append(value)
#         byte = f.read(4)

# a = np.array(decoded)
# a = np.reshape(a,(500,500,100))
# print(a)

data = np.fromfile("pf01.bin",dtype="float32")
data = np.reshape(data,(500,500,100))
# print(data)
# data.tofile("aaa.bin")
temp = data[0:250,:,:]
temp.tofile("xxx.bin")
temp = data[250:,:,:]
temp.tofile("yyy.bin")
# for i in range(2):
#     for j in range(2):
#         for k in range(2):
#             fileName = "test"+str(i*4+j*2+k) + ".bin"
#             temp = data[250*i:250*(i+1),250*j:250*(j+1),50*k:50*(k+1)]
#             temp.tofile(fileName)