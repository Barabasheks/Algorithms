def sift_up(heap, startpos, pos):
    newitem = heap[pos]
    while pos > startpos:
        parentpos = (pos - 1) // 2
        parent = heap[parentpos]
        if newitem < parent:
            heap[pos] = parent
            pos = parentpos
            continue
        break
    heap[pos] = newitem


def sift_down(heap, pos):
    endpos = len(heap)
    startpos = pos
    newitem = heap[pos]
    child_left = 2*pos + 1
    while child_left < endpos:
        child_right = child_left + 1
        if child_right < endpos and not heap[child_left] < heap[child_right]:
            child_left = child_right
        heap[pos] = heap[child_left]
        pos = child_left
        child_left = 2*pos + 1
    heap[pos] = newitem
    sift_up(heap, startpos, pos)


def push(heap, item):
    heap.append(item)
    sift_up(heap, 0, len(heap) - 1)


def extract_min(heap):
    print(queue[0], file=fout)
    queue[0] = heap[len(heap) - 1]
    heap.pop()
    if len(heap) > 1:
        sift_down(heap, 0)


fin = open("priorityqueue.in")
fout = open("priorityqueue.out", "w")
queue = []
dict_of_elem = dict()
num_line = 0
for line in fin:
    command = line.split()
    num_line += 1
    if command[0] == "push":
        push(queue, int(command[1]))
        dict_of_elem.update({num_line: int(command[1])})
    elif command[0] == "extract-min":
        if len(queue) > 0:
            extract_min(queue)
        else:
            print("*", file=fout)
    elif command[0] == "decrease-key":
        old_value = dict_of_elem.get(int(command[1]))
        new_value = int(command[2])
        dict_of_elem[int(command[1])] = new_value
        flag = True
        i = 0
        while i < len(queue) and flag:
            if queue[i] == old_value:
                queue[i] = new_value
                sift_up(queue, 0, i)
                flag = False
            i += 1