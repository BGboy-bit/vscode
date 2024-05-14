import numpy as np
import matplotlib.pyplot as plt

mu, sigma = -1, 1
x = mu + sigma * np.random.randn(10000)

n, bins, patches = plt.hist(x, 100, density = True, facecolor = 'blue', alpha = 0.75)
plt.xlabel('Value')
plt.ylabel('Density')
plt.grid(True)
plt.show()
