import math

t = int(input())
for i in range(t):
	xx , yy , zz = input().split()
	a = int(xx)
	b = int(yy)
	c = int(zz)
	d = pow(a,b,c)
	print(d)