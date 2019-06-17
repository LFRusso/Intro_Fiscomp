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


x = np.loadtxt("data", delimiter = ' ')

n, f = histo(x)

plt.scatter(n, f)
plt.show()
