import numpy as np
from matplotlib import pyplot as plt

t, P = np.loadtxt("data", delimiter = "\t", unpack = True)

plt.plot(t, P)
plt.show()