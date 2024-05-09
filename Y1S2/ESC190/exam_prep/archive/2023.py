class PriorityQueue:
    def __init__(self):
        self.q = []
    def insert(self, x, p):
        self.q.append([x,p])
    def extract_min(self):
        # Assume self.q has a minimum value
        min = self.q[0]
        index = 0
        for i in range(len(self.q)):
            if (self.q[i][1]<min[1]):
                min = self.q[i]
                index = i
        return self.q.pop(index)[1]
        

pq = PriorityQueue()
pq.insert("h11i", 1)
pq.insert("h4i", 4)
pq.insert("hqeri", 6)
pq.insert("hsdfi", 2)
pq.insert("hisdf", 10)
print(pq.extract_min())
print(pq.q)


class MyList:
    def __init__(self, arr):
        self.arr = sorted(arr)
        self.ave = sum(arr)/len(arr)
    def __lt__(self, other):
        return self.ave<other.ave
    def __repr__ (self):
        return str(self.arr)

my_lists = [MyList([1, 3]), MyList([5, 4, 6]), MyList([20, -20])]
print(sorted(my_lists))


def cumulative_cost(cost):
    steps = [1,2,3]
    cumulative_cost = [0]*len(cost)
    cumulative_cost[0] = cost[0]
    cumulative_cost[1] = cost[1]
    cumulative_cost[2] = cost[2]
    for i in range(3, len(cost)):
        cumulative_cost[i] = min([cumulative_cost[i-j] for j in steps]) + cost[i]
    return retracing(cost, cumulative_cost, len(cumulative_cost)-1)

    
def retracing(cost, cumulative_cost, index, path=[]):
    if index in [0,1,2]:
        return [index+1]+path
    
    steps = [1,2,3]
    min_step = 1
    value = cumulative_cost[index-1]
    for step in steps:
        if  (cumulative_cost[index-step]<value):
            min_step=step
            value = cumulative_cost[index-step]
    return retracing(cost, cumulative_cost, index-min_step, [min_step]+path)

print(cumulative_cost([1,4,2,6,3,7,8]))


def longest_chain(friends):
    max_chain = 0
    for friend in friends:
        visited = set([friend])
        queue = [(friend, 1)]
        while queue:
            parent = queue.pop()
            for parent_friend in friends[parent[0]]:
                if parent_friend not in visited:
                    queue.append((parent_friend, parent[1]+1))
                    visited.add(parent_friend)
                    if (parent[1]+1)>max_chain:
                        max_chain=parent[1]+1
    return max_chain


friends = {"Carl Gauss": ["Isaac Newton", "Gottfried Leibniz", "Charles Babbage"],
"Gottfried Leibniz": ["Carl Gauss"],
"Isaac Newton": ["Carl Gauss", "Charles Babbage"],
"Ada Lovelace": ["Charles Babbage", "Michael Faraday"],
"Charles Babbage": ["Isaac Newton", "Carl Gauss", "Ada Lovelace"],
"Michael Faraday": ["Ada Lovelace"] }


print(longest_chain(friends))