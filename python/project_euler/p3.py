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
        for j in xrange(i,limit):
            #print "\tj: ",f[j]
            if(f[j] != 0):
                if(f[j]%f[i] == 0 and f[j] != f[i]): 
                    f[j] = 0

sum = 0              
count = 0
fo = open("primes.txt","w")

primes = []
for i in f:
    if(i != 0):
        sum += i
        primes.append(i)
        fo.write("\n{}".format(i))
        count += 1
        print(i),


print "count: ",count
fo.write("\n total {} primes".format(i))
print primes[0]
print primes[10000]
print primes[10001]

fo.close()

#strategy used to solve the problem
# 1. get first 100 or more primes using a prime sieve
# 2. create a test function that does prime testing using these primes
# 3. divide the number in the problem by half and decrement it, and simultaneously testing it for primes no as well as calculating modulus of 
#    given problem number with it to see if it is the largest prime factor

def isPrime(number):
    Prime = True
    dividedBy = 0
    for i in primes:
        if(number%i == 0):
            Prime = Prime and False
            dividedBy = i
        else:
            Prime = Prime and True
    return dividedBy

def testNumber(number):
    testFactor = int(number / 2)

    if(testFactor%2 != 0):
        testFactor = testFactor - 1

    #assuming that test values is greater than 2000
    i = testFactor - 1
    while(i > 2000):
        print "testing: ",i
        if(isPrime(i) and number%i == 0):
            return i
        i = i -2

    return -1

#print isPrime(90)
#print isPrime(1992)

#import time
#result = 0
#startTime = time.time()
#result = testNumber(600851475143/(839))
#result = testNumber(7607*345)
#endTime = time.time()

#timeTaken = endTime - startTime
#print "greatest prime factor is: ",result  
#print "time taken: ",timeTaken," seconds"

#print isPrime((600851475143/839)/71)

