import numpy as np
from matplotlib import pyplot as plt

x, y = np.loadtxt('fort.2', delimiter= ',', unpack= True)
template = np.linspace(-np.pi, np.pi, 300)


plt.plot(template, np.cos(template), color= 'blue', label = 'COS(X)')
plt.scatter(x, y, color = 'red', label = 'T(x)', marker='x')
plt.axis('equal')
plt.grid()
plt.legend()
plt.show()
