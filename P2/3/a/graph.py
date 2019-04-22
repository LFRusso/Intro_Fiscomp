import numpy as np
from matplotlib import pyplot as plt

T = 2
x = np.linspace(-4, 4, 100)
gx = np.tanh(x/T)
fx = x

plt.plot(x, fx)
plt.plot(x, gx)

plt.title("T>1")
plt.show()
