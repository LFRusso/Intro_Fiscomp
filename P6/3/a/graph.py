import numpy as np
from matplotlib import pyplot as plt

P1 = np.loadtxt("dados1.dat", delimiter = "\t", unpack = True)
P2 = np.loadtxt("dados2.dat", delimiter = "\t", unpack = True)
P3 = np.loadtxt("dados3.dat", delimiter = "\t", unpack = True)


plt.hist(P1, bins = 100, rwidth = 0.5, color = "k")
plt.ylabel("frequência")
plt.xlabel("x")
plt.title("t = 50")
plt.show()
plt.cla()

plt.hist(P2, bins = 100, rwidth = 0.5, color = "k")
plt.ylabel("frequência")
plt.xlabel("x")
plt.title("t = 100")
plt.show()
plt.cla()

plt.hist(P3, bins = 100, rwidth = 0.5, color = "k")
plt.ylabel("frequência")
plt.xlabel("x")
plt.title("t = 200")
plt.show()

