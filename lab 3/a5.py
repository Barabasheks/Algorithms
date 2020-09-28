fin = open("radixsort.in")
fout = open("radixsort.out", "w")
input = fin.readline().split()
n = int(input[0])
m = int(input[1])
k = int(input[2])
strings = []
for line in fin:
    strings.append(line[0: len(line) - 1])
i = min(k, m)
while i > 0:
    buf = [[] for j in range(57)]
    for j in range(n):
        buf[ord(strings[j][m - 1]) - 65].append(strings[j])
    kol = 0
    for j in range(57):
        for el in buf[j]:
            strings[kol] = el
            kol += 1
    i -= 1
    m -= 1
for i in strings:
    print(i, file=fout)