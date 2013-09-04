i = 2

f = []
limit = 2000000
for i in xrange(0,limit):
    f.append(i)

#for i in f:
#    print i
f[1] = 0
for i in xrange(2,limit):
    if(f[i] != 0):
        print "i: ",f[i]
        for j in xrange(i,limit,i): # taking i steps each loop made the algorithm very fast, because we are not comparing useless values anymore and wokring truely like sieve of erotosthenes.
            #print "\tj: ",f[j]
            if(f[j] != 0):
                if(f[j]%f[i] == 0 and f[j] != f[i]): 
                    f[j] = 0

sum = 0
for i in f:
    if i != 0:
        print i,
        sum += i

print "\ntotal: ",sum
#
#sum = 0              
#count = 0
#fo = open("primes.txt","w")
#
#primes = []
#for i in f:
#    if(i != 0):
#        sum += i
#        primes.append(i)
#        fo.write("\n{}".format(i))
#        count += 1
#        print(i),
#
#
#print "count: ",count
#fo.write("\n total {} primes".format(i))
#print primes[0]
#print primes[10000]
#print primes[10001]
#
#fo.close()


