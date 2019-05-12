import numpy as np
from matplotlib import pyplot as plt

t, r = np.loadtxt("Rxt.dat", delimiter = "\t", unpack = True)
rmax = r.max()
rmin = r.min()

plt.plot(t, r, linewidth = 1, label = "Rmax/Rmin = "+str(rmax/rmin))
plt.legend()
plt.ylabel("R")
plt.xlabel("t")
plt.legend()
plt.grid()
plt.savefig("Rxt.png")
