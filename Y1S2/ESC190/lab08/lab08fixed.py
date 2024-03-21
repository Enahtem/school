blocks = [2,4,5]


def OPT(n):
    n+=1
    opt_list=[0]*n
    for i in range(1,n):
        values = []
        for block in blocks:
            if (i-block)>=0 and opt_list[i-block]>=0:
                values.append(opt_list[i-block]+1)
        if (values==[]):
            opt_list[i]=-1
        else:
            opt_list[i]=min(values)
    return opt_list[n-1]

 
def get_blocks(n):
    min_opt_value=1000 #large number
    min_block=-1
    for block in blocks:
        if (n-block>=0 and OPT(n-block)>=0):
            if (OPT(n-block)<=min_opt_value):
                min_opt_value=OPT(n-block)
                min_block=block
    if (min_block==-1):
        return []
    else:
        return [min_block]+get_blocks(n-min_block)

def OPTS(n):
    for i in range(n):
        print(str(i)+":",OPT(i),">",get_blocks(i))   

OPTS(10)