sum = 0
f = []
f.append(0)
f.append(1)

i = 1
while(f[i] < 4000000):
    f.append(f[i] + f[i-1])
    i += 1

sum = 0
for x in f:
    if x%2 == 0:
        print x
        sum += x
print f
print sum

