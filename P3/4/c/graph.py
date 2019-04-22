import numpy as np
from matplotlib import pyplot as plt

nu, theta = np.loadtxt("nu-theta.csv", delimiter=',', unpack = True)

plt.scatter(theta, nu, linewidth = 1)
plt.xlabel("theta_0")
plt.ylabel("nu*")
plt.grid()
plt.savefig('graph.png')
