def swap(str,a,b):
    c = list(str)
    c[a], c[b] = c[b], c[a]
    # LANG SPECIFICS: string is immutable type in python, therefore a copy is passed when it is sent to a function
    return ''.join(c)

def permute(str,i):
    if i == len(str): # BASE CASE
        print str
    else:
        for j in xrange(i,len(str)): # trying all available choices
            str = swap(str,i,j)
            permute(str,i+1) # try to solve with choice made
            str = swap(str,i,j) # backtrack step


def call_permute(str):
    permute(str,0)

# test the functions
str = "abcd"
call_permute(str)

