import numpy as np
from matplotlib import pyplot as plt

dt, delta = np.loadtxt("delta_dt.dat", delimiter = "\t", unpack = True)

plt.scatter(dt, delta, linewidth = 1, s = 1)
plt.grid()
plt.xlabel("dt")
plt.ylabel("delta")
plt.savefig("delta_dt.png")
