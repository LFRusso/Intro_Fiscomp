from matplotlib import pyplot as plt
import numpy as np

theta, omega = np.loadtxt("fort.1", delimiter = ',', unpack = True)

plt.plot(theta, omega, linewidth = 1)
plt.grid()
plt.xlabel("Theta (rad)")
plt.ylabel("Omega (rad/s)")
plt.title("Espaço de Fase (Euler)")
plt.savefig("thetaxomega.png")
