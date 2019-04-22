from matplotlib import pyplot as plt
import numpy as np

tau, theta = np.loadtxt('fort.3', delimiter = ',', unpack = True)
plt.plot(tau, theta, linewidth = 1)
plt.xlabel("T")
plt.ylabel("Theta (rad)")
plt.grid()
plt.title("Euler")
plt.savefig("euler.png")
