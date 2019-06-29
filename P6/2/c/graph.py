import numpy as np
from matplotlib import pyplot as plt

x = np.loadtxt("dados.dat")

plt.hist(x, bins = 100, align = "mid", color = "k", rwidth = 0.5)
plt.xlabel("x")
plt.ylabel("frequência")
plt.show()
plt.cla()

plt.hist(x, bins = 100, align = "mid", color = "k", rwidth = 0.5, log = True)
plt.xlabel("x")
plt.ylabel("frequência")
plt.title('Escala logarítmica')
plt.show()