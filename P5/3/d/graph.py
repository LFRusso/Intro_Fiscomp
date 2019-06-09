import numpy as np
from matplotlib import pyplot as plt

x, y, n = np.loadtxt("dados.dat", delimiter = "\t", unpack = True)

n = int(n[0])
aux = 0
for i in range(0, 10):
	slicex = x[n*i + aux:(i+1)*n + aux + 1]
	slicey = y[n*i + aux:(i+1)*n + aux + 1]
	plt.plot(slicex, slicey)
	aux += 1
plt.legend()
plt.show()