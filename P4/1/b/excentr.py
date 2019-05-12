from matplotlib import pyplot as plt
import numpy as np

x, y, t = np.loadtxt("excentr.dat", delimiter = "\t", unpack = True)
rho = np.sqrt(x*x + y*y)
drho = round(rho.max()/rho.min()-1, 4)

plt.plot(x, y, linewidth = 1, label = "rho_max/rho_min - 1 = " + str(drho)+"\ndt = 0.0009")
plt.ylabel("rho_Y")
plt.xlabel("rho_X")
plt.grid()
plt.legend()
plt.savefig("excentr.png")
