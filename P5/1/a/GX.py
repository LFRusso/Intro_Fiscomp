from matplotlib import pyplot as plt
import numpy as np

x, g, r = np.loadtxt("GX.dat", delimiter = "\t", unpack = True)

part2 = list(r).index(1)
part3 = list(r).index(2)

plt.plot(x[0:part2], x[0:part2], linewidth = 1, label = "y = x")
plt.plot(x[0:part2], g[0:part2], linewidth = 1, label = "y = G(0.5, x)")
plt.plot(x[part2:part3], g[part2:part3], linewidth = 1, label = "y = G(1, x)")
plt.plot(x[part3:], g[part3:], linewidth = 1, label = "y = G(2, x)")

plt.grid()
plt.legend()
plt.xlabel("X")
plt.ylabel("Y")
plt.savefig("GX.png")
