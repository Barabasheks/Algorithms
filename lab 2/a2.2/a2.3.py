def sort(list_of_countries, fst, lst):
    if fst >= lst: return

    i = fst
    j = lst
    pivot = list_of_countries[(fst + lst) // 2][0]

    while i <= j:
        while list_of_countries[i][0] < pivot: i += 1
        while list_of_countries[j][0] > pivot: j -= 1
        if i <= j:
            list_of_countries[i], list_of_countries[j] = list_of_countries[j], list_of_countries[i]
            i = i + 1
            j = j - 1
    sort(list_of_countries, fst, j)
    sort(list_of_countries, i, lst)


fin = open("race.in")
fout = open("race.out", "w")
n = int(fin.readline())
list_of_sportsmen = []
for line in fin:
    list_of_sportsmen.append([line.split()[0], line.split()[1]])
sort(list_of_sportsmen, 0, len(list_of_sportsmen) - 1)
last_country = list_of_sportsmen[0][0]
i = 0
while i < n:
    print("===", list_of_sportsmen[i][0], "===", file=fout)
    while list_of_sportsmen[i][0] == last_country:
        print(list_of_sportsmen[i][1], file=fout)
        last_country = list_of_sportsmen[i][0]
        i += 1
    i += 1