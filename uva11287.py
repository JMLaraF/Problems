p , a = input().split()
p = int(p)
a = int(a)
while(p != 0 and a != 0):
	x = 1
	for i in range (0,p):
		x = (x * a) % p
	print(x)
	if(x == a):
		print('yes')
	else:
		print('no')	
	p , a = input().split()
	p = int(p)
	a = int(a)