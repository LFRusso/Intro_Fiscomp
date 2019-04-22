from matplotlib import pyplot as plt
import numpy as np

x, y, z= np.loadtxt('fort.1', delimiter=',', unpack = True)
plt.plot(x, y)
plt.plot(x, z, color = 'red')
plt.grid()
plt.show()
