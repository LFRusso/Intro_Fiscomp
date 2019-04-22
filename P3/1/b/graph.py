from matplotlib import pyplot as plt
import numpy as np

dt, v = np.loadtxt('fort.1', delimiter=',', unpack=True)
plt.plot(dt, v, linewidth = 1, label="v* = "+ str(round(v[-1], 4))+" m/s")
plt.legend()
plt.ylabel("Velocidade (m/s)")
plt.xlabel("Tempo (s)")
plt.title("V x T")
plt.grid()
plt.savefig("velpt.png")
