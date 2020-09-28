def rec(mas, num, fst, lst):
    if fst == lst:
        if mas[fst] == 0:
            mas[fst] = num
        return
    mid = (fst + lst) // 2
    mas[mid] = num
    num -= 1
    if fst == mid:
        rec(mas, num, mid + 1, lst)
    else:
        rec(mas, num, fst, mid - 1)
        rec(mas, num - (lst - mid), mid + 1, lst)

fin = open("antiqs.in")
fout = open("antiqs.out", "w")
n = int(fin.readline())
mas = [0 for i in range(n)]
fst = 0
lst = n -1
rec(mas, n, fst, lst)
for i in mas:
    print(i, end=' ', file=fout)