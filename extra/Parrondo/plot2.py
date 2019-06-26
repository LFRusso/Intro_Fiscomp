import numpy as np
from matplotlib import pyplot as plt

t, A = np.loadtxt("Amed.dat", delimiter = "\t", unpack = True)
t, B = np.loadtxt("Bmed.dat", delimiter = "\t", unpack = True)
t, C = np.loadtxt("Cmed.dat", delimiter = "\t", unpack = True)
t, D = np.loadtxt("Dmed.dat", delimiter = "\t", unpack = True)


plt.plot(t, A, label = "Jogo A")
plt.plot(t, B, label = "Jogo B")
plt.plot(t, C, label = "Aleatório")
plt.plot(t, D, label = "AABB")
plt.title("Média do dinheiro em relação ao tempo")
plt.xlabel("Número de jogadas")
plt.ylabel("Média do dinheiro final")
plt.grid()
plt.legend()
plt.show()

