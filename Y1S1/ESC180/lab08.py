def binary_search(L, e):
    low = 0
    high = len(L)-1
    iterations=1
    while high-low >= 2:
        iterations+=1
        mid = (low+high)//2 #e.g. 7//2 == 3
        if L[mid] > e:
            high = mid-1
        elif L[mid] < e:
            low = mid+1
        else:
            return mid
    if L[low] == e:
        return (low,iterations)
    elif L[high] == e:
        return (high,iterations)
    else:
        return (None,iterations)

print(binary_search([x for x in range(10)], 2))
print()
print()
print()
print()
##################################

def searching():
    for n in range(7):
        print(binary_search([x for x in range(10**(n+1))],0)[1])

searching()
print()
print()
print()
print()
##################################

import time
def time_counting():
    # Measure the time for binary search
    start_time = time.time()

    binary_search([x for x in range(1000000)], 1000000-1)
    end_time = time.time()

    binary_search_time = end_time - start_time
    print("Binary Search Time:", binary_search_time)

    # Measure the time for list.index
    start_time = time.time()
    [x for x in range(1000000)].index(1000000-1)
    end_time = time.time()

    index_time = end_time - start_time
    print("list.index Time:", index_time)

time_counting()
print()
print()
print()
print()
##################################

import urllib.request

url = "https://www.gutenberg.org/files/1342/1342-0.txt"

# Download the file content
response = urllib.request.urlopen(url)
file_content = response.read().decode("utf-8")  # Assuming UTF-8 encoding, adjust if needed

# Save the content to a local file (optional)
with open("pride_and_prejudice.txt", "w", encoding="utf-8") as local_file:
    local_file.write(file_content)

# Split the content into a list of words
word_list = file_content.split()

word_counts={}

for word in word_list[:10000]:
    count=0
    for word2 in word_list[:10000]:
        if word==word2:
            count+=1
    word_counts[word]=count

print(word_counts["the"])
##################################
def top10(L):
    return sorted(L)[-10:]
print(top10([100-x for x in range(100)]))

##################################

swapped_dict = {value: key for key, value in word_counts.items()}
print(sorted(swapped_dict.items())[-10:])

