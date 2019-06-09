from matplotlib import pyplot as plt 
import numpy as np


# Plot do gráfico do log da derivada de G(x) pela iteração
j, l = np.loadtxt("iderivative.dat", delimiter = '\t', unpack = True)

plt.ylabel("Ln(|G'(x)|)")
plt.xlabel("j")
plt.plot(j, l)
plt.grid()
plt.show()

# ==============================================

# A seguir o plot do histograma
h = np.loadtxt("histogram.dat")

count = []
numb = []
for i in h: # loop percorrendo a lista com os valores de Ln(|G'(x)|) e contando sua frequência
	if not i in numb:
		numb.append(i)
		count.append(list(h).count(i))

plt.title("Histograma")
plt.ylabel("Frequência")
plt.xlabel("Ln(|G'(x)|)")
# plot do histograma
plt.bar(numb, count, width = 10**-7, align = "center", color = 'k')


# cálculo da média ponderada dos valores do histograma e do desvio padrão
pond = np.array(numb)*np.array(count)
stder = np.std(pond/max(count))

maxindex = np.argmax(count) 
lamb = round(numb[maxindex], 5)
stder = round(stder, 5)
med = sum(list(pond))/sum(list(count))

# plot do valor do coef de Lyapunov
plt.bar(med, count[maxindex], width = 10**-7, align = "center", color = 'r', label = "lambda = " + str(round(med, 5)) + " +/- " +str(stder))
plt.legend()

plt.show()