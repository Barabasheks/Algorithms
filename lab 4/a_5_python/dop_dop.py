import heapq

fin = open("priorityqueue.in")
fout = open("priorityqueue.out", "w")
queue = []
dict_of_elem = dict()
num_line = 0
for line in fin:
    command = line.split()
    num_line += 1
    if command[0] == "push":
        heapq.heappush(queue, int(command[1]))
        dict_of_elem.update({num_line: int(command[1])})
    elif command[0] == "extract-min":
        if len(queue) > 0:
            print(queue[0], file=fout)
            heapq.heappop(queue)
        else:
            print("*", file=fout)
    elif command[0] == "decrease-key":
        old_value = dict_of_elem.get(int(command[1]))
        new_value = int(command[2])
        queue_dop = []
        flag = True
        for elem in queue:
            if old_value != elem:
                heapq.heappush(queue_dop, elem)
            elif (flag):
                heapq.heappush(queue_dop, new_value)
                flag = False
        queue = queue_dop