import numpy as np
from matplotlib import pyplot as plt
from scipy.optimize import curve_fit

def f(x, a, b):
	return a*x + b

n, std = np.loadtxt("desvio.dat", delimiter = '\t', unpack = True)

popt, pcov = curve_fit(f, np.log(n), np.log(std))

x = np.linspace(np.log(n[0]), np.log(n[-1]), 50)
plt.plot(x, f(x, popt[0], popt[1]), "r--", label = "y = "+str(round(popt[0],3))+"x "+str(round(popt[1])))
plt.scatter(np.log(n), np.log(std), color = "green")

plt.legend()
plt.xlabel("$Ln(N)$")
plt.ylabel("$Ln(\delta <r>)$")
plt.grid()
plt.savefig("stdxn")
