from matplotlib import pyplot as plt 
import numpy as np

j, l = np.loadtxt("iderivative.dat", delimiter = '\t', unpack = True)

plt.ylabel("Ln(|G(x)|)")
plt.xlabel("j")
plt.plot(j, l)
plt.grid()
plt.show()

h = np.loadtxt("histogram.dat")

count = []
numb = []
for i in h:
	if not i in numb:
		numb.append(i)
		count.append(list(h).count(i))

plt.title("Histograma")
plt.ylabel("Frequência")
plt.xlabel("Ln(|G(x)|)")
plt.bar(numb, count, width = 10**-7, align = "center", color = 'k')

pond = np.array(numb)*np.array(count)
stder = np.std(pond/max(count))

maxindex = np.argmax(count) 
lamb = round(numb[maxindex], 5)
stder = round(stder, 5)
med = sum(list(pond))/sum(list(count))

plt.bar(med, count[maxindex], width = 10**-7, align = "center", color = 'r', label = "lambda = " + str(round(med, 5)) + " +/- " +str(stder))
plt.legend()

plt.show()