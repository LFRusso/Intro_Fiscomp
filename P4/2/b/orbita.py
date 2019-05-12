import numpy as np
from matplotlib import pyplot as plt

xt, yt, xj, yj, xs, ys = np.loadtxt("orbita.dat", delimiter = "\t", unpack = True)
plt.plot(xt, yt, linewidth = 1, label = "Terra")
plt.plot(xj, yj, linewidth = 1, label = "Jupiter")
plt.plot(xs, ys, linewidth = 1, label = "Sol")
plt.grid()
plt.legend()
#plt.show()
plt.savefig("orbita.png")
