import numpy as np
from matplotlib import pyplot as plt

t, r2, k = np.loadtxt("dados.dat", delimiter = "\t", unpack = True)

plt.plot(t, r2, color = "green")
plt.xlabel("t")
plt.ylabel("$<r^2>$")
plt.grid()
plt.savefig("r2.png")
plt.cla()