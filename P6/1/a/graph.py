import numpy as np
from matplotlib import pyplot as plt

N, stdev, med = np.loadtxt("med_stdev.dat", delimiter = '\t', unpack = True)

plt.scatter(N, stdev, label = "desvio padrâo", s = 7)
plt.scatter(N, med, label = "media", s = 7)
plt.legend()
plt.grid()
plt.xlabel("N")
plt.show()
plt.cla()

plt.scatter(N, stdev, label = "desvio padrâo", s = 15, color = "orange")
plt.legend()
plt.grid()
plt.xlabel("N")
plt.savefig("stdevN.png")
plt.cla()

plt.scatter(N, med, label = "media", s = 15)
plt.legend()
plt.grid()
plt.xlabel("N")
plt.savefig("medN.png")
