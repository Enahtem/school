
# Question 2

def set_ten():
    global a
    a=10

a=5
set_ten()
print(a)



def change_string():
    global s
    s="ssss"+s[4:]

s="initial string"
change_string()
print(s)