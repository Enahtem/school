blocks=[2,5]

def OPT(value):
    if value==0:
        return 0
    elif value<min(blocks):
        return -1 #Escape Value
    else:
        min_steps = -1 #Escape Value
        for block in blocks:
            if (OPT(value-block)==-1): #Escape Value
                continue
            else:
                steps = 1+OPT(value-block)
                if (min_steps==-1 or steps<min_steps):
                    min_steps=steps
        return min_steps
    
def OPT2(value):
    if value==0:
        return []
    elif value<min(blocks):
        return [-1] #Escape Value
    else:
        min_steps = [-1] #Escape Value
        
        for block in blocks:
            if (OPT2(value-block)==[-1]): #Escape Value
                continue
            else:
                steps = [block]+OPT2(value-block)
                if (min_steps[0]==-1 or len(steps)<len(min_steps)):
                    min_steps=steps
        return min_steps


def OPTS(num):
    for i in range(num):
        print(str(i)+":",OPT(i),end=" > ")
        print(OPT2(i))
    
OPTS(10)


