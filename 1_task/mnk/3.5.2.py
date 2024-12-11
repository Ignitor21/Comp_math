#!/usr/bin/python3
import numpy as np

data = { -2:-8, -1:-1, 0:15, 1:1, 2:8 }
n = len(data)

#Следующие формулы получены с помощью МНК:
U = np.zeros((2, 2))
for i in range(2):
    for j in range(2):
        U[i][j] = sum(x**(3*(i+j)) for x in data.keys())

F = np.zeros(2)
for i in range(2):
    F[i] = sum((x**(3*i))*y for x, y in data.items())

answer = np.linalg.solve(U, F)
y_1 = answer[0] + answer[1]
print(f'y(1) = {y_1}')
