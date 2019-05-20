import numpy as np
from matplotlib import pyplot as plt

r, x = np.loadtxt("pontos", delimiter = '\t', unpack = True)
plt.scatter(r ,x, linewidth = 1, s = 0.05)
plt.xlabel("r")
plt.ylabel("x*")
plt.show()
