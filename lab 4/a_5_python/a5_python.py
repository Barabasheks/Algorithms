def sift_up(queue, i):
    if queue[i // 2] > queue[i]:
        queue[i // 2], queue[i] = queue[i], queue[i // 2];
        i = i // 2
        if i > 1:
            sift_up(queue, i)


def sift_down(queue, i):
    if i * 2 + 1 < len(queue):
        if queue[i * 2] < queue[i * 2 + 1] and queue[i] > queue[i * 2]:
            queue[i], queue[i * 2] = queue[i * 2], queue[i]
            i = i * 2
            if i * 2 < len(queue):
                sift_down(queue, i)
        elif queue[i * 2] > queue[i * 2 + 1] and queue[i] > queue[i * 2 + 1]:
            queue[i], queue[i * 2 + 1] = queue[i * 2 + 1], queue[i]
            i = i * 2 + 1
            if i * 2 < len(queue):
                sift_down(queue, i)
    else:
        if queue[i] > queue[i * 2]:
            queue[i], queue[i * 2] = queue[i * 2], queue[i]
            i = i * 2
            if i * 2 < len(queue):
                sift_down(queue, i)


fin = open("priorityqueue.in")
fout = open("priorityqueue.out", "w")
queue = [0]
dict_of_elem = dict()
num_line = 0
for line in fin:
    command = line.split()
    num_line += 1
    if command[0] == "push":
        queue.append(int(command[1]))
        dict_of_elem.update({num_line: int(command[1])})
        if len(queue) - 1 > 1:
            sift_up(queue, len(queue) - 1)
    elif command[0] == "extract-min":
        if len(queue) - 1 > 0:
            print(queue[1])
            queue[1] = queue[len(queue) - 1]
            queue.pop(len(queue) - 1)
            if len(queue) - 1 > 1:
                sift_down(queue, 1)
        else:
            print("*")
    elif command[0] == "decrease-key":
        old_value = dict_of_elem.get(int(command[1]))
        new_value = int(command[2])
        for i in range(1, len(queue)):
            if queue[i] == old_value:
                queue[i] = new_value
                if len(queue) - 1 > 1 and i > 1:
                    sift_up(queue, i)
                break

