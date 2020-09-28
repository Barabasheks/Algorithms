import random
from typing import List

fin = open("kth.in")
fout = open("kth.out", "w")
n, k = map(int, fin.readline().split())
A, B, C, a1, a2 = map(int, fin.readline().split())
mas: List[int] = [a1, a2]
for i in range(2, n):
    mas.append(int(A * mas[i - 2] + B * mas[i - 1] + C))
pos_of_random = 0
left = 0
right = n - 1
while pos_of_random != k:
    pos_of_random = random.randint(left, right)
    mas[pos_of_random], mas[right] = mas[right], mas[pos_of_random]
    pos_of_random = left - 1
    for i in range(left, right + 1):
        if mas[right] >= mas[i]:
            pos_of_random += 1
            mas[i], mas[pos_of_random] = mas[pos_of_random], mas[i]
    if pos_of_random < k:
        left = pos_of_random + 1
    elif pos_of_random > k:
        right = pos_of_random - 1
print(mas[pos_of_random - 1], file=fout)