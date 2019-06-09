import numpy as np
from matplotlib import pyplot as plt

x0, r, x, d, i = np.loadtxt("dados.dat", delimiter = '\t', unpack = True)

x1 = x[:101]
d1 = d[:101]
x2 = x[101:202]
d2 = d[101:202]
x3 = x[202:303]
d3 = d[202:303]
x4 = x[303:404]
d4 = d[303:404]
x5 = x[404:]
d5 = x[404:]

axis = np.linspace(0, 100, 101)

# ======== plot x i graph ========
plt.scatter(axis, x1, s= 5, label = "x0 = "+ str(x0[0]))
plt.scatter(axis, x2, s= 5, label = "x0 = "+ str(x0[102]))
plt.scatter(axis, x3, s= 5, label = "x0 = "+ str(x0[203]))
plt.scatter(axis, x4, s= 5, label = "x0 = "+ str(x0[304]))
plt.scatter(axis, x5, s= 5, label = "x0 = "+ str(x0[-1]))

plt.xlabel("i")
plt.ylabel("x(i)")
plt.legend()
plt.title("X(i) x i\nr = " + str(r[0]))
plt.grid()

title = "xi" + str(round(r[0], 4)) + ".png"
plt.savefig(title)
plt.close()
# ================================

# ======== plot d i graph ========
plt.scatter(axis, d1, s= 5, label = "x0 = "+ str(x0[0]))
plt.scatter(axis, d2, s= 5, label = "x0 = "+ str(x0[102]))
plt.scatter(axis, d3, s= 5, label = "x0 = "+ str(x0[203]))
plt.scatter(axis, d4, s= 5, label = "x0 = "+ str(x0[304]))
plt.scatter(axis, d5, s= 5, label = "x0 = "+ str(x0[-1]))

plt.xlabel("i")
plt.ylabel("d(i)")
plt.legend()
plt.title("d(i) x i\nr = " + str(r[0]))
plt.grid()
title = "Di" + str(round(r[0], 4)) + ".png"
plt.savefig(title)
plt.close()
# ================================