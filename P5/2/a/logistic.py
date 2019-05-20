import numpy as np
from matplotlib import pyplot as plt

def f(x):
	return x

def G(x, r):
	return  r*x*(1 - x)

x = np.linspace(0, 1, 1000)

plt.plot(x, f(x))
plt.plot(x, G(G(x, 2.9), 2.9), label = "r = 2.9")
plt.plot(x, G(G(x, 3), 3), label = "r = 3")
plt.plot(x, G(G(x, 3.1), 3.1), label = "r = 3.1")

plt.grid()
plt.xlabel("x")
plt.ylabel("y")
plt.legend()

#plt.savefig("ex2a.png")
plt.show()
