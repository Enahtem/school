import numpy as np


# Printing matrices using NumPy:

# Convert a list of lists into an array:
M_listoflists = [[1,-2,3],[3,10,1],[1,5,3]]
M = np.array(M_listoflists)
# Now print it:
print(M)
#Compute M*x for matrix M and vector x by using
#dot. To do that, we need to obtain arrays
#M and x
M = np.array([[1,-2,3],[3,10,1],[1,5,3]])
x = np.array([75,10,-11])
b = np.matmul(M,x)        
print(M)
#[[ 1 -2  3]
# [ 3 10  1]
# [ 1  5  3]]
# To obtain a list of lists from the array M, we use .tolist()
M_listoflists = M.tolist() 
print(M_listoflists) #[[1, -2, 3], [3, 10, 1], [1, 5, 3]]

print("-----------------------------------")

def print_matrix(M_lol):
    print()
    for row in M_lol:
        print("|", end="")
        for element in row:
            print(" "+str(element)+" ", end="")
        print("|")
    print()

print_matrix(M_listoflists)

print("-----------------------------------")

def get_lead_ind(row):
    for i in range(len(row)):
        if (row[i]!=0):
            return i
    return len(row)

print(get_lead_ind([0,0,0,0,2,3,0]))

print("-----------------------------------")

def get_row_to_swap(M, start_i):
    min_lead=get_lead_ind(M[start_i])
    chosen_i=start_i
    for i in range(start_i,len(M)):
        if (get_lead_ind(M[i])<min_lead):
            min_lead=get_lead_ind(M[i])
            chosen_i=i
    return chosen_i

M = [[5, 6, 7, 8],
[0, 0, 0, 1],
[0, 0, 5, 2],
[0, 1, 0, 0]]
print(get_row_to_swap(M, 1))

print("-----------------------------------")

def add_rows_coefs(r1, c1, r2, c2):
    r_new=[0]*len(r1)
    for i in range(len(r_new)):
        r_new[i]+=c1*r1[i]+c2*r2[i]
    return r_new

print_matrix(M)
print(add_rows_coefs(M[0], 2, M[1], 3))
print_matrix(M)


print("-----------------------------------")

def eliminate(M,row_to_sub, best_lead_ind):
    for i in range(row_to_sub+1, len(M)):
        M[i]=add_rows_coefs(M[row_to_sub], -M[i][best_lead_ind]/M[row_to_sub][best_lead_ind], M[i], 1)

print_matrix(M)
eliminate(M,0,3)
print_matrix(M)


print("-----------------------------------")

M=[[ 0, 0, 1, 0, 2],
   [ 1, 0, 2, 3, 4],
   [ 3, 0, 4, 2, 1],
   [ 1, 0, 1, 1, 2]]


def forward_step(M):
    for i in range(len(M)):
        swap_index=get_row_to_swap(M,i)
        if (swap_index!=i):
            temp = M[i][:]
            M[i]=M[swap_index][:]
            M[swap_index]=temp[:]
            eliminate(M, i, get_lead_ind(M[i]))
            break
        else:
            eliminate(M, i, get_lead_ind(M[i]))

print_matrix(M)
forward_step(M)
print_matrix(M)
forward_step(M)
print_matrix(M)
forward_step(M)
print_matrix(M)
forward_step(M)
print_matrix(M)
forward_step(M)
print_matrix(M)
forward_step(M)
print_matrix(M)




print("-----------------------------------")



def eliminate_back(M,row_to_sub, best_lead_ind):
    for i in range(row_to_sub):
        M[i]=add_rows_coefs(M[row_to_sub], -M[i][best_lead_ind]/M[row_to_sub][best_lead_ind], M[i], 1)

def is_column_solved(M,i):
    count=0
    for j in range(len(M)):
        if M[j][i]!=0:
            count+=1
    return count<=1

def last_nonzero(M,i):
    for j in reversed(range(len(M))):
        if M[j][i]!=0:
            return j
    return 0

def backward_step(M):
    for i in reversed(range(len(M))):
        if (not is_column_solved(M,i)):
            eliminate_back(M,last_nonzero(M,i),i)
            break
backward_step(M)
print_matrix(M)
backward_step(M)
print_matrix(M)
backward_step(M)
print_matrix(M)
backward_step(M)
print_matrix(M)
backward_step(M)
print_matrix(M)
backward_step(M)
print_matrix(M)
backward_step(M)
print_matrix(M)

print("-----------------------------------")
M = [[2, 1, -1],[-3, -1, 2],[-2, 1, 2]]
b = [8, -11, -3]
M_aug = [row + [bi] for row, bi in zip(M, b)]
print(M_aug)

def solve(M_aug):
    for i in range(len(M_aug)):
        forward_step(M_aug)
        print("Forwards ", i)
        print_matrix(M_aug)
    for i in range(len(M_aug)):
        backward_step(M_aug)
        print("Backwards ", i)
        print_matrix(M_aug)

solve(M_aug)

def normalize(M_solved):
    for i in range(len(M_solved)):
        for j in range(len(M_solved[i])):
            if M_solved[i][j]!=0:
                divide_by=M_solved[i][j]
                for k in range(len(M_solved[i])):
                    M_solved[i][k]/=divide_by
                break


normalize(M_aug)
print_matrix(M_aug)
x=[row[-1] for row in M_aug]


print("-----------------------------------")

M = [[2, 1, -1],[-3, -1, 2],[-2, 1, 2]]
b = [8, -11, -3]
M_aug = [row + [bi] for row, bi in zip(M, b)]


def complete_solve(M_aug):
    solve(M_aug)
    normalize(M_aug)
    print_matrix(M_aug)
    return [row[-1] for row in M_aug]

x=complete_solve(M_aug)
print("Solution: ", x)

M = np.array(M)
x = np.array(x)

print("Verification")
print(np.matmul(M,x))
print(b)
