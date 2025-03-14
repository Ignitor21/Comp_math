#!/usr/bin/python3
import numpy as np

def seidel_iteration(A : np.array, f : np.array, u : np.array) -> np.array:
    n = len(A)
    u_next = u.copy()

    for i in range(n):
        s1 = sum(A[i][j] * u[j] for j in range(i))
        s2 = sum(A[i][j] * u_next[j] for j in range(i + 1, n))
        print(s1, s2)
        u_next[i] = (f[i] - s1 - s2) / A[i][i]

    return u_next

A = np.array([[5, -1, 2], [1, 4, -1], [1, 1, 1]])
f = np.array([8, -4, 4])
u = np.array([0, 0, 0])

u = seidel_iteration(A, f, u)
print(f"Result after 1 itertaion:  {u}")

u = seidel_iteration(A, f, u)
print(f"Result after 2 iterations: {u}")

# Сходимость метода Зейделя <=> выполнению следующего условия:
# Все корни уравнения по модулю не превосходят 1:   
#      |a_11*x  a_12   a_13 |
#      |a_21*x a_22*x  a_23 | = 0
#      |a_31*x a_32*x a_33*x|
# 
# В нашем случае имеем уравнение:
# 20x^3 + x = 0
# 
# Его корни: x_1 = 0, x_2 = +i/(20)^0.5, x_3 = -i/(20)^0.5
# 
# Все они по модулю не превосходят 1, следовательно наш итерационный метод Зейделя сходится.
