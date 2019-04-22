from matplotlib import pyplot as plt
import numpy as np

x, y = np.loadtxt("fort.1", delimiter = ',', unpack = True)
theta_max = x[np.argmax(y)]
plt.plot(x, y, linewidth=1)
plt.grid()
plt.title("theta_max = "+str(theta_max))
plt.savefig("maxtheta.png")

