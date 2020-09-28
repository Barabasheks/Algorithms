def sort(list_of_countries, fst, lst):
    if lst - fst == 1:
        if list_of_countries[fst] > list_of_countries[lst]:
            list_of_countries[fst], list_of_countries[lst] = list_of_countries[lst], list_of_countries[fst]
        return
    if fst == lst: return
    mid = (fst + lst) // 2
    sort(list_of_countries, fst, mid)
    sort(list_of_countries, mid + 1, lst)
    buf = []
    i = fst
    j = mid + 1
    k = 0
    while lst - fst + 1 != k:
        if (i > mid):
            buf.append(list_of_countries[j])
            k += 1
            j += 1
        elif (j > lst):
            buf.append(list_of_countries[i])
            k += 1
            i += 1
        elif (list_of_countries[i] > list_of_countries[j]):
            buf.append(list_of_countries[j])
            k += 1
            j += 1
        else:
            buf.append(list_of_countries[i])
            k += 1
            i += 1
    for i in range(lst - fst + 1):
            list_of_countries[i + fst] = buf[i];

fin = open("race.in")
fout = open("race.out", "w")
n = int(fin.readline())
set_of_countries = set()
list_of_sportsmen = []
dict_of_sportsmen = dict()
for line in fin:
    set_of_countries.add(line.split()[0])
    list_of_sportsmen.append([line.split()[0], line.split()[1]])
list_of_countries = list(set_of_countries)
for country in list_of_countries:
    dict_of_sportsmen[country] = []
for sportsmen in list_of_sportsmen:
    dict_of_sportsmen[sportsmen[0]].append(sportsmen[1])
sort(list_of_countries, 0, len(list_of_countries) - 1)

for country in list_of_countries:
    print("===", country, "===", file=fout)
    sportsmen_of_country = dict_of_sportsmen[country]
    for sportsmen in sportsmen_of_country:
        print(sportsmen, file=fout)



