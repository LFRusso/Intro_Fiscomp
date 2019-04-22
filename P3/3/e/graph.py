from matplotlib import pyplot as plt
import numpy as np

t, theta, E, omega = np.loadtxt("fort.1", delimiter = ',', unpack = True)

plt.plot(t, theta, linewidth = 1, label = "Theta x T")
plt.grid()
plt.xlabel("Tempo (s)")
plt.ylabel("Theta (rad)/Energia Mecânica (J)")

plt.plot(t, E, linewidth = 1, label = "E x T")
plt.xlabel("Tempo (s)")
plt.title("Verlet")
plt.legend()
plt.savefig("verlet.png")
plt.close()

plt.plot(theta, omega, linewidth = 1)
plt.grid()
plt.xlabel("Tempo (s)")
plt.ylabel("Energia Mecânica (J)")
plt.title("Espaço de Fase (Verlet)")
plt.savefig("thetaxomega.png")
