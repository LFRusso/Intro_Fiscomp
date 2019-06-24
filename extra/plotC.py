import numpy as np
from matplotlib import pyplot as plt

d = np.loadtxt("dinheiro.dat")

plt.hist(d)
plt.show()
