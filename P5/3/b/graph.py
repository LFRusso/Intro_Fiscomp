import numpy as np
from matplotlib import pyplot as plt

t, x, y = np.loadtxt("dados.dat", delimiter = "\t", unpack = True)

plt.plot(t, x, label = "presa")
plt.plot(t, y, label = "predador")
plt.legend()
plt.show()