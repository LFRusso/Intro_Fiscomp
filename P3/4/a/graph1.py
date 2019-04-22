from matplotlib import pyplot as plt
import numpy as np

tau, theta = np.loadtxt('fort.1', delimiter = ',', unpack = True)
plt.plot(tau, theta, linewidth = 1)
plt.xlabel("T")
plt.ylabel("Theta (rad)")
plt.grid()
plt.title("Verlet")
plt.savefig("verlet.png")
