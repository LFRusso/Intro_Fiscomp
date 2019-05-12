import numpy as np
from matplotlib import pyplot as plt

t, rk, ec = np.loadtxt("Rxt.dat", delimiter = "\t", unpack = True)
plt.plot(t, rk, linewidth = 1, label = "Runge-Kutta")
plt.plot(t, ec, linewidth = 1, label = "Euler-Cromer")
plt.title("R x t")
plt.legend()
plt.xlabel("t")
plt.ylabel("R")
plt.grid()
plt.savefig("Rxt.png")
