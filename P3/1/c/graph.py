from matplotlib import pyplot as plt
import numpy as np

dt1, v1, area = np.loadtxt('fort.1', delimiter=',', unpack=True)
a1 = round(area[0])
plt.plot(dt1, v1, linewidth = 1, label=str(a1)+" m^2")

dt2, v2, area = np.loadtxt('fort.2', delimiter=',', unpack=True)
a2 = round(area[0])
plt.plot(dt2, v2, linewidth = 1, label=str(a2)+" m^2")

dt3, v3, area = np.loadtxt('fort.3', delimiter=',', unpack=True)
a3 = round(area[0])
plt.plot(dt3, v3, linewidth = 1, label=str(a3)+" m^2")

plt.legend()
plt.grid()
plt.title("Variação da área")
plt.xlabel("Tempo (s)")
plt.ylabel("Velocidade (m/s)")
plt.savefig("vararea.png")
