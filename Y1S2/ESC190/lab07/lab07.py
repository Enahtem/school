class CircularQueue:
    def __init__(self, size):
        self.size = size
        self.data = [None]*size
        self.start = size//2-1
        self.end = size//2-1
    def enqueue(self, item):
        self.end=(self.end+1)%self.size
        self.data[self.end]=item
        print(self)

    def dequeue(self):
        self.start=(self.start+1)%self.size
        self.data[self.start]=None
        print(self)

    def __str__(self):
        out = ""
        for value in self.data:
            out = out +str(value)+" "
        out = out+"\n"+str(self.start)+", "+str(self.end)
        return out

    def __lt__(self, other):
        for i in range(min((self.end-self.start)%self.size, (other.end-other.start)%other.size)):
            print(i)
            if self.data[(self.start + 1+ i) % self.size] < other.data[(other.start +1+ i) % other.size]:
                return True
            elif self.data[(self.start +1+ i) % self.size] > other.data[(other.start +1+ i) % other.size]:
                return False
        return True

# Question 1
cq = CircularQueue(5)
cq.enqueue(1)
cq.enqueue(1)
cq.enqueue(1)
cq.enqueue(1)
cq.enqueue(1)
cq.dequeue()
cq.dequeue()
cq.dequeue()
cq.dequeue()
cq.dequeue()



# Question 2
cq1 = CircularQueue(6)
cq1.enqueue(2)
cq1.enqueue(5)
cq1.enqueue(10)
cq1.enqueue(11)

cq2 = CircularQueue(6)
cq2.enqueue(2)
cq2.enqueue(5)
cq2.enqueue(10)
cq2.enqueue(10)

cq3 = CircularQueue(6)
cq3.enqueue(3)
cq3.enqueue(5)
cq3.enqueue(10)

queues = [cq1, cq2, cq3]
sorted_queues = sorted(queues)

print("\nSorted Queues:")
for cq in sorted_queues:
    print(cq)
