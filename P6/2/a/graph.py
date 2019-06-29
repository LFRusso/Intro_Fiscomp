import numpy as np
from matplotlib import pyplot as plt

t, P, size, k = np.loadtxt("dados.dat", delimiter = "\t", unpack = True)

size = int(size[0])
k = int(k[0])

aux = 0
aux2 = -1
for i in range(11):
	plt.plot(t[size*i+aux:size*(i+1)+aux2], P[size*i+aux:size*(i+1)+aux2])
	aux += 1
	aux2 += 1


aux = 0
aux2 = -1
med = np.array([0]*(size-1))
print(len(med))
for i in range(k+1):
	med = med + P[size*i+aux:size*(i+1)+aux2]
	time = t[size*i+aux:size*(i+1)+aux2]
	aux += 1
	aux2 += 1
med = med/(k+1)

aux = 0
aux2 = -1
stdev = np.array([0]*(size-1))
for i in range(k+1):
	stdev = (med - P[size*i+aux:size*(i+1)+aux2])**2
	aux += 1
	aux2 += 1
stdev = np.sqrt(stdev/k)
error = stdev/np.sqrt(k)

plt.errorbar(time, med, yerr = error, elinewidth = 1, ecolor = "r", capsize = 1.5, barsabove = True, color = "red", label = "$<N(t)>$ +/- $\sigma /\sqrt{k}$")
plt.xlabel("Tempo")
plt.ylabel("$N^o$ de núcleos")
plt.title(str(k)+" simulações")
plt.grid()
plt.legend()
plt.show()