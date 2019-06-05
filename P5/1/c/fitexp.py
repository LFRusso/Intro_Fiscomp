from matplotlib import pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

def f(x, a, b):
	return a*x + b

i1, d1 = np.loadtxt('exp1.dat', delimiter = '\t', unpack = True)
i2, d2 = np.loadtxt('exp2.dat', delimiter = '\t', unpack = True)
i3, d3 = np.loadtxt('exp3.dat', delimiter = '\t', unpack = True)


plt.plot(i1, np.log(d1), label = "r = 1.5")
plt.plot(i2, np.log(d2), label = "r = 2.5")
plt.plot(i3, np.log(d3), label = "r = 2.7")

plt.legend()
plt.xlabel("i")
plt.ylabel("ln(d)")
plt.title("x0 = 1/6")
plt.grid()

plt.savefig("confirmexp.png")