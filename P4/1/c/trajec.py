import numpy as np
from matplotlib import pyplot as plt

x, y = np.loadtxt("trajec.dat", delimiter = "\t", unpack = True)
plt.plot(x, y, linewidth = 1)
plt.xlabel("x")
plt.ylabel("y")
plt.title("RK4")
plt.grid()
plt.savefig("trajec.png")
