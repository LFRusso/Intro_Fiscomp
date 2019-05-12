import numpy as np
from matplotlib import pyplot as plt

t, rk, ec = np.loadtxt("EM.dat", delimiter = "\t", unpack = True)
plt.plot(t, rk, linewidth = 1, label = "Runge-Kutta")
plt.plot(t, ec, linewidth = 1, label = "Euler-Cromer")
plt.title("Energia Mecanica")
plt.legend()
plt.xlabel("t")
plt.ylabel("EM")
plt.grid()
plt.savefig("EM.png")
