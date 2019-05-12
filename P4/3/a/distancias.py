import numpy as np
from matplotlib import pyplot as plt

t, d12, d13, d23 = np.loadtxt("distancias.dat", delimiter = "\t", unpack = True)

plt.plot(t, d12, linewidth = 1, label = "Distancia 1-2")
plt.plot(t, d13, linewidth = 1, label = "Distancia 1-3")
plt.plot(t, d23, linewidth = 1, label = "Distancia 2-3")
plt.grid()
plt.legend()
#plt.show()
plt.savefig("distancias.png")
