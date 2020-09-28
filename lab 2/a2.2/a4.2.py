fin = open("antiqs.in")
fout = open("antiqs.out", "w")
n = int(fin.readline())
mas = [i + 1 for i in range(n)]
for i in range(2, n):
    mas[i], mas[i // 2] = mas[i // 2], mas[i]

for i in mas:
    print(i, end=' ', file=fout)



