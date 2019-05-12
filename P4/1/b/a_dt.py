import numpy as np
from matplotlib import pyplot as plt

a, dt = np.loadtxt("a_dt.dat", delimiter = "\t", unpack = True)
plt.scatter(a, dt,s = 10, linewidth = 1)
plt.xlabel("a")
plt.ylabel("dt")
plt.grid()
plt.savefig("a_dt.png")
