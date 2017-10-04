primes = [0]*10005
isprime = [False]*10005
k = 0
def seive():
    isprime[0] = isprime[1] = True
    i = 2
    global k
    for i in range(2,10005):
		if (isprime[i] == False):
		    primes[k] = i;
		    k = k+1
		    for j in range(i+i,10005,i):
			isprime[j] = True
    
seive()
n = (long)(raw_input())
while (n > 0):
    pro = 1
    #print(n)
    #print(k)
    for i in range(k):
	#print(primes[i])
	if(primes[i] > n):
	    break
	expo = 0
	temp = n
	while (temp > 0):
	    expo = expo + (temp/primes[i])
	    temp = temp/primes[i]
	#print(expo)
	pro = pro*(2*expo+1)
    print(pro)
    n = (long)(raw_input())