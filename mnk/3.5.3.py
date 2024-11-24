#!/usr/bin/python3
import numpy as np

data = { -3:-10, -2:-5, -1:-2, 0:0, 1:2, 2:5, 3:10 }
n = len(data)

#Следующие формулы получены с помощью МНК:
U = np.zeros((3, 3))
for i in range(3):
    for j in range(3):
        U[i][j] = sum(x**(i+j) for x in data.keys())

F = np.zeros(3)
for i in range(3):
    F[i] = sum((x**i)*y for x, y in data.items())

answer = np.linalg.solve(U, F)
print(f"Значения коэффициентов: a = {answer[0]}, b = {answer[1]}, c = {answer[2]}")
