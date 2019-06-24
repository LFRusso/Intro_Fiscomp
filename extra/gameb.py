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

dinheiro = 0
n = 50000
V = []
U = []

for j in range(10000):
	dinheiro = 0
	if(np.random.random() < 0.5):
		for i in range(n):
			if(dinheiro % 3 == 0):
				if(np.random.random() <= 0.095):
					dinheiro += 1
				else:
					dinheiro -= 1
			else:
				if(np.random.random() <= 0.745):
					dinheiro += 1
				else:
					dinheiro -= 1
	else:
		if(np.random.random() <= 0.495):
			dinheiro +=1
		else:
			dinheiro -= 1
		
	V.append(dinheiro)


term, freq = histo(V)
plt.bar(term, freq, width = 1, align = "center", color= 'k')
plt.xlabel("dinheiro final")
plt.ylabel("número de jogos")
plt.show()
