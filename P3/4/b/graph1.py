from matplotlib import pyplot as plt
import numpy as np

nu, theta = np.loadtxt('fort.1', delimiter = ',', unpack = True)

aux = 0
for i in range(len(theta)):
	if (theta[i] + theta[i-1] > max(theta) - 1.0 and theta[i] > 1.0 and theta[i]-theta[i-1] > 1.0):
		nu_m2 = nu[i]
		theta_m2 = theta[i]
		if (aux == 0):
			nu_m1 = nu[i]
			theta_m1 = theta[i] 
			aux += 1
			
nu_m = (nu_m1 + nu_m2)/2
nu_m = round(nu_m, 5)


#plt.plot(nu, theta, linewidth = 1, color = 'r')
plt.scatter(nu, theta, linewidth = 0.5)
plt.xlabel("nu")
plt.ylabel("Theta (rad)")
plt.grid()
plt.title("Nu comparison")
plt.scatter(nu_m1, theta_m1, color = 'r')
plt.scatter(nu_m2, theta_m2, color = 'r')
plt.text(nu_m2, 0, s = "nu* = "+str(nu_m) )

plt.savefig("data.png")
