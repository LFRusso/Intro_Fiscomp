import numpy as np
from matplotlib import pyplot as plt

r, v, t = np.loadtxt("orbita_RK.dat", delimiter = "\t", unpack = True)
plt.plot(t, r, linewidth = 1, label = "Rxt")
plt.plot(t, v, linewidth = 1, label = "Vxt")
plt.legend()
plt.grid()
plt.xlabel("t")
plt.savefig("orbita_RK.png")
