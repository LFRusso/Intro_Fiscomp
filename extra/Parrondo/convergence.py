import numpy as np
from matplotlib import pyplot as plt

M = np.array([[0, 0.5*(0.745 + 0.495), 0.5*(0.255 + 0.505)], [0.5*(0.255 + 0.505), 0, 0.5*(0.745 + 0.495)], [0.5*(0.095 + 0.495), 0.5*(0.905 + 0.505), 0]])

MB = np.array([[0, 0.745, 0.255], [0.255, 0, 0.745], [0.095, 0.905, 0]])

n = 100
v = np.array([0, 0, 1])


A = [[],[]]
B = [[],[]]
C = [[],[]]
for i in range(n):
	A[0].append(i)
	A[1].append(v[0])
	B[0].append(i)
	B[1].append(v[1])
	C[0].append(i)
	C[1].append(v[2])

	v = np.dot(v, M)

plt.scatter(A[0], A[1], label = "$\pi_1$", s= 15)
plt.scatter(B[0], B[1], label = "$\pi_2$", s = 15)
plt.scatter(C[0], C[1], label = "$\pi_3$", s = 15)
plt.xlabel("i")
plt.grid()
plt.legend()
plt.show()
plt.cla()

plt.bar(['$\pi_1$', '$\pi_2$', "$\pi_3$"], v, color = "k")
plt.show()
