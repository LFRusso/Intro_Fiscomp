import numpy as np
from matplotlib import pyplot as plt

def histo(V):
	term = []
	freq = []
	for i in V:
		if i not in term:
			term.append(i)
			freq.append(list(V).count(i))
	return term, freq


A = np.loadtxt("A.dat")
B = np.loadtxt("B.dat")
C = np.loadtxt("C.dat")

Aterm, Afreq = histo(A)
Bterm, Bfreq = histo(B)
Cterm, Cfreq = histo(C)

plt.bar(Aterm, Afreq, width = 1, align = "center", color= 'k')
plt.title("jogo A")
plt.xlabel("dinheiro final")
plt.ylabel("número de jogos")
plt.show()
plt.cla()

plt.bar(Bterm, Bfreq, width = 1, align = "center", color= 'k')
plt.title("jogo B")
plt.xlabel("dinheiro final")
plt.ylabel("número de jogos")
plt.show()
plt.cla()

plt.bar(Cterm, Cfreq, width = 1, align = "center", color= 'k')
plt.xlabel("dinheiro final")
plt.ylabel("número de jogos")
plt.show()

