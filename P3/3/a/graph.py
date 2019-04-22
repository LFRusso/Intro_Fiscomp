from matplotlib import pyplot as plt
import numpy as np

t, theta, E = np.loadtxt("fort.1", delimiter = ',', unpack = True)

plt.plot(t, theta, linewidth = 1)
plt.grid()
plt.xlabel("Tempo (s)")
plt.ylabel("Theta (rad)")
plt.title("Theta x Tempo")
plt.savefig("thetaxt.png")
close()

plt.plot(t, E, linewidth = 1)
plt.grid()
plt.xlabel("Tempo (s)")
plt.ylabel("Energia Mecânica (J)")
plt.title("Energia x Tempo")
plt.savefig("ext.png")

