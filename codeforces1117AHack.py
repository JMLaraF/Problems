t=int(raw_input())
d=map(int,raw_input().split())
f=max(d)
ma=0
c=0
for i in range(t):
	
	if d[i]==f:
		c=c+1
	else:
		ma=max(c,ma)
		c=0
print max(c,ma)