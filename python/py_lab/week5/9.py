import numpy as np
import matplotlib.pyplot as plt

x1 = np.linspace(-2 * np.pi, 2 * np.pi, 400)
x2 = np.linspace(0.1, 2 * np.pi, 400)

y_x2 = x1 ** 2
y_log = np.log(x2)
y_sin = np.sin(x1)

plt.figure(figsize=(10, 6))
plt.plot(x1, y_x2, label = '$y=x^2$', color = 'red')
plt.plot(x2, y_log, label = '$y=\ln(x)$', color = 'blue')
plt.plot(x1, y_sin, label = '$y=\sin(x)$', color = 'green')

# Adding labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title('Plot of $y=x^2$, $y=\ln(x)$, and $y=\sin(x)$')
plt.axhline(0, color = 'black', linewidth = 0.5)
plt.axvline(0, color = 'black', linewidth = 0.5)
plt.grid(True)
plt.legend()

plt.show()
