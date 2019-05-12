from matplotlib import pyplot as plt
import numpy as np

x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8 = np.loadtxt("orbita.dat", delimiter = " ", unpack = True)

plt.plot(x1, y1, linewidth = 1, label = "Mercurio")
plt.plot(x2, y2, linewidth = 1, label = "Venus")
plt.plot(x3, y3, linewidth = 1, label = "Terra")
plt.plot(x4, y4, linewidth = 1, label = "Marte")
plt.plot(x5, y5, linewidth = 1, label = "Jupiter")
plt.plot(x6, y6, linewidth = 1, label = "Saturno")
plt.plot(x7, y7, linewidth = 1, label = "Urano")
plt.plot(x8, y8, linewidth = 1, label = "Netuno")

plt.ylabel("Y")
plt.xlabel("X")
plt.grid()
plt.legend()
plt.show("orbita.png")
