f = open("p8_num_list.txt")
x = f.readline()
#print len(x) #length of string
digit_list = []
counter = 0
while(x[counter] != '\n'):
    digit_list.append(int(x[counter]))
    counter = counter + 1

#print digit_list
#print len(digit_list)
temp_max_product = 0
temp_max_product_index = 0
max_product_now = 0
for i in xrange(0,996):
    max_product_now = digit_list[i]*digit_list[i+1]*digit_list[i+2]*digit_list[i+3]*digit_list[i+4]
    if(temp_max_product < max_product_now):
        temp_max_product = max_product_now
        temp_max_product_index = i

for i in xrange(temp_max_product_index,temp_max_product_index+5):
    print digit_list[i],
print "has product ",temp_max_product

