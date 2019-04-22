from matplotlib import pyplot as plt
import numpy as np

x, y= np.loadtxt('fort.1', delimiter=',', unpack = True)
plt.plot(x, y)
plt.grid()
plt.show()
