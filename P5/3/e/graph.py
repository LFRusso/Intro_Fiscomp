import numpy as np
from matplotlib import pyplot as plt

t, x, y = np.loadtxt("dados.dat", delimiter = "\t", unpack = True)

plt.plot(t, x, label = "presa")
plt.plot(t, y, label = "predador")
plt.xlabel("tempo")
plt.ylabel("população (10**3)")
plt.legend()
plt.grid()
plt.show()


for i in range(len(list(x))):
	if (x[i] - y[i] < 0.005):
		fixo = x[i]
		break


plt.plot(x, y)
#plt.scatter(fixo, fixo, marker = "x", color = "red", label = "ponto fixo = " + str(fixo))
plt.xlabel("presa")
plt.ylabel("predador")
plt.grid()
plt.legend()
plt.show()