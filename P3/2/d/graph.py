import numpy as np
from matplotlib import pyplot as plt

v, d = np.loadtxt("fort.1", delimiter = ',', unpack = True)
plt.plot(v, d)
plt.show()
