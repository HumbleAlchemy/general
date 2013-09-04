max_i = 0
max_j = 0
max_x = 0
for i in xrange(100,1000):
    for j in xrange(100,1000):
        x = i*j
        x = str(x)
        x_rev = x[::-1]
        if(x == x_rev):
            print("i {0} j {1} x {2}").format(i,j,x)
            if(int(x) > max_x):
                max_x = int(x)
print max_x
