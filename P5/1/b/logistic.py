from matplotlib import pyplot as plt
import numpy as np
div = 20

# Programa para dividir os diferentes gráficos (de cada r) para cada valor de x0

ai , ax = np.loadtxt("logistic1.dat", delimiter = "\t", unpack = True)
plt.plot(ai[:div], ax[:div], label = "x = 1/6")
plt.plot(ai[div+1:2*div], ax[div+1:2*div], label = "x = 2/6")
plt.plot(ai[2*div+1:3*div], ax[2*div+1:3*div], label = "x = 3/6")
plt.plot(ai[3*div+1:4*div], ax[3*div+1:4*div], label = "x = 4/6")
plt.plot(ai[4*div+1:], ax[4*div+1:], label = "x = 5/6")
plt.title("r = 1")
plt.grid()
plt.legend()
plt.xlabel("i")
plt.ylabel("X")
plt.savefig("r1.png")
plt.close()

bi , bx = np.loadtxt("logistic2.dat", delimiter = "\t", unpack = True)
plt.plot(bi[:div], bx[:div], label = "x = 1/6")
plt.plot(bi[div+1:2*div], bx[div+1:2*div], label = "x = 2/6")
plt.plot(bi[2*div+1:3*div], bx[2*div+1:3*div], label = "x = 3/6")
plt.plot(bi[3*div+1:4*div], bx[3*div+1:4*div], label = "x = 4/6")
plt.plot(bi[4*div+1:], bx[4*div+1:], label = "x = 5/6")
plt.title("r = 2")
plt.grid()
plt.legend()
plt.xlabel("i")
plt.ylabel("X")
plt.savefig("r2.png")
plt.close()

ci , cx = np.loadtxt("logistic3.dat", delimiter = "\t", unpack = True)
plt.plot(ci[:div], cx[:div], label = "x = 1/6")
plt.plot(ci[div+1:2*div], cx[div+1:2*div], label = "x = 2/6")
plt.plot(ci[2*div+1:3*div], cx[2*div+1:3*div], label = "x = 3/6")
plt.plot(ci[3*div+1:4*div], cx[3*div+1:4*div], label = "x = 4/6")
plt.plot(ci[4*div+1:], cx[4*div+1:], label = "x = 5/6")
plt.title("r = 2.5")
plt.grid()
plt.legend()
plt.xlabel("i")
plt.ylabel("X")
plt.savefig("r25.png")
plt.close()

