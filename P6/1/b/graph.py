import numpy as np
from matplotlib import pyplot as plt
from scipy.optimize import curve_fit

def f(x, a, b):
	return a/np.sqrt(x) + b

def histo(V):
	term = []
	freq = []
	for i in V:
		if i not in term:
			term.append(i)
			freq.append(list(V).count(i))
	return term, freq


N, med = np.loadtxt("rmed.dat", delimiter = '\t', unpack = True)
n, std = np.loadtxt("desvio.dat", delimiter = '\t', unpack = True)



N1, med1= N[:100], med[:100]
N2, med2 = N[101:201], med[101:201]
N3, med3 = N[200:], med[200:]

term1, freq1 = histo(med1)
term2, freq2 = histo(med2)
term3, freq3 = histo(med3)

plt.bar(term3, freq3, width = 5*10**-3, align = "center", label = "N = $3^4$")
plt.bar(term2, freq2, width = 5*10**-3, align = "center", label = "N = $3^3$")
plt.bar(term1, freq1, width = 5*10**-3, align = "center", label = "N = $3^2$")

plt.legend()
plt.grid()
plt.ylabel("frequência")
plt.xlabel("$<r>$")
plt.savefig("histograma.png")
plt.cla()	


plt.scatter(np.log(n), np.log(std), color = "green")
#x = np.linspace(np.log(n[0]), np.log(n[-1]), 1000)

#popt, pcov = curve_fit(f, np.log(n), np.log(std))
#plt.plot(x, f(x, popt[0], popt[1]), color = "red")
#plt.legend()
plt.xlabel("$Ln(N)$")
plt.ylabel("$Ln(\delta <r>)$")
plt.grid()
plt.savefig("stdxn")
