import numpy as np
from matplotlib import pyplot as plt

P1 = np.loadtxt("dados1.dat", delimiter = "\t", unpack = True)
P2 = np.loadtxt("dados2.dat", delimiter = "\t", unpack = True)
P3 = np.loadtxt("dados3.dat", delimiter = "\t", unpack = True)


plt.hist(P1, align = "mid", rwidth = 0.1)
plt.show()
plt.cla()

plt.hist(P2, rwidth = 0.1)
plt.show()
plt.cla()

plt.hist(P3, rwidth = 0.1)
plt.show()

