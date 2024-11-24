#!/usr/bin/python3
import numpy as np

EPSILON = 0.1

A = np.array([[-7, 4, 5], [4, -6, -9], [5, -9, -8]])
u = np.array([1, 0, 0])
answer = max(np.linalg.eigvals(A), key=abs)
radius = 0
i = 1

print(f"Right answer = {answer:.3f}")
print("i radius")

while(abs(radius - answer) >= EPSILON):
    u_next = np.dot(A, u)
    radius = np.dot(u_next, u) / (np.dot(u, u))
    print(f"{i} {radius:.3f}")
    i += 1
    u = u_next
