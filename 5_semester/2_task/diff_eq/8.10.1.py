#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt

def func(x, y):
    return x + np.cos(y)

def euler_method(x0, y0, x_end, h):
    x_list = [x0]
    y_list = [y0]

    while x_list[-1] < x_end:
        y_next = y_list[-1] + h * func(x_list[-1], y_list[-1])
        x_next = x_list[-1] + h
        x_list.append(x_next)
        y_list.append(y_next)
    return np.array(x_list), np.array(y_list)


x0, y0 = 1, 30
h = 0.01
x_end = 2
x, y = euler_method(x0, y0, x_end, h)

plt.plot(x, y, label="y' = x + cos(y)")
plt.grid()
plt.xlabel("x")
plt.ylabel("y")
plt.show()

