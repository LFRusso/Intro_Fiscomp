import numpy as np
from matplotlib import pyplot as plt

t, x, y = np.loadtxt("dados.dat", delimiter = "\t", unpack = True)

plt.plot(t, x, label = "presa")
plt.plot(t, y, label = "predador")
plt.legend()
plt.grid()
plt.xlabel("tempo")
plt.ylabel("população")
plt.show()

plt.plot(x, y)
plt.title("espaço de fase")
plt.grid()
plt.xlabel("x")
plt.ylabel("y")
plt.show()