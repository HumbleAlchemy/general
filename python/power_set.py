def power_set(so_far,rest):
    if rest == '':
        if so_far == '':
            print 'phi'
        else:
            print so_far
    else:
        power_set(so_far+rest[0],rest[1:]) #add element for consideration
        power_set(so_far,rest[1:]) #backtrack

def call_power_set(set_string):
    power_set('',set_string)


#call function to test power_set
str = "1234"
call_power_set(str)

