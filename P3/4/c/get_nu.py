import numpy as np

nu, theta, initial_theta = np.loadtxt('point.csv', delimiter = ',', unpack = True)

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
		
#print(nu_m, initial_theta[0])

with open('nu-theta.csv', 'a') as datafile:
	datafile.write(str(nu_m)+','+ str(initial_theta[0]))
	datafile.write('\n')
	datafile.close()
	
print(0.1*0.1*nu_m*nu_m*np.cos(initial_theta[0]))
