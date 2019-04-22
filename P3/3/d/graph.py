from matplotlib import pyplot as plt
import numpy as np

theta, T = np.loadtxt("fort.1", delimiter =",", unpack = True)
plt.scatter(theta, T, linewidth = 1)
plt.grid()
plt.xlabel("Theta inicial (rad)")
plt.ylabel("Período (s)")
plt.savefig("thetaxper.png")
