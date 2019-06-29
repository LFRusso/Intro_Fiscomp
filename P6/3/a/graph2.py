import numpy as np
from matplotlib import pyplot as plt

t, x, x2, k = np.loadtxt("dadosK.dat", delimiter = "\t", unpack = True)

plt.plot([0, 200], [0,0], color = "red", label = "y = 0")
plt.plot(t, x, color = "green")
plt.xlabel("t")
plt.ylabel("$<x>$")
plt.legend()
plt.grid()
plt.savefig("x1.png")
plt.cla()

plt.plot([0, 200], [0.3333, 0.3333], color = "red", label = "y = 1/3")
plt.plot(t, x2, color = "purple")
plt.xlabel("t")
plt.ylabel("$<x^2>$")
plt.legend()
plt.grid()
plt.savefig("x2.png")
plt.cla()
