from matplotlib import pyplot as plt
import numpy as np

rho, v, t = np.loadtxt("dados.dat", delimiter = "\t", unpack = True)

plt.plot(t, rho, linewidth = 1, label = "rho x tau" )
plt.plot(t, v, linewidth = 1, label = "V x tau" )
plt.xlabel("tau")
plt.grid()
plt.legend()
plt.savefig("grafico.png")
