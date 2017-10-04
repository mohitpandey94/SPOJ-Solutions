# your code goes here
t = int(raw_input())
while (t > 0):
	line =  raw_input()
	x = line.split(' ')
	#a,b,c=1,1,1
	b = long(x[0])
	c = long(x[1])
	d = long(x[2])
	#a,b,c = x[0],x[1],x[2]
	#a=b=c=1
	ans = 2*c-(b+d)
	print(ans)
	#print ((b*b+(c-b)**2-(c-d)**2)/2)
	#print(a)
	t = t-1