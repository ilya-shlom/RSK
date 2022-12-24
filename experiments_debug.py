import numpy as np
import pandas as pd

Q_amount = []
# Q_uniques = []
Q_W_amount = []
trash = 0
for i in range(8):
    Q_W_amount.append([])
P_amount = []
permutations_amount = []
for i in range(3, 11):
    data = pd.read_csv(f'results/results_{i}.csv', delimiter=';')
    permutations_amount.append(len(data["W"]))
#     experiment 1: count unique Q-tableaux
    Q = set(data["Q"])
    Q_amount.append(len(Q))
#     experiment 2: amount of perms for each Q
    trash, Q_W_amount[i-3] = np.unique(data["Q"], return_counts=True)
print(Q_amount)
print(Q_W_amount[2])
# for x in Q_W_amount:
#     print(*x)
