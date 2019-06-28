import numpy as np
from matplotlib import pyplot as plt

n1, med1, e1 = np.loadtxt("data1.dat", delimiter = "\t", unpack = True)
n2, med2, e2 = np.loadtxt("data2.dat", delimiter = "\t", unpack = True)

plt.scatter(n1, med1, color = "green", s = 18, label = "$f(x) = 4/(x^2 + 1)$")
plt.scatter(n2, med2, color = "purple", s = 18, label = "$f(x) = 1/x$")
plt.xlabel("N")
plt.ylabel("$(b - a)\sum_{i = 1}^{N} f(x_i)/N$")
plt.legend()
plt.grid()
plt.show()

plt.scatter(n1, e1, color = "black", s = 18, label = "$f(x) = 4/(x^2 + 1)$")
plt.scatter(n2, e2, color = "orange", s = 18, label = "$f(x) = 1/x$")
plt.xlabel("N")
plt.ylabel("$\delta <f(x)>$")
plt.legend()
plt.grid()
plt.show()