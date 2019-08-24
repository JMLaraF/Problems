n = int(input())
c = []
s = ""
mx = 0
c = input().split()
for i in range(0,n+1):
	for j in range(i+1,n+1):
		s = ""
		for k in range(i,j):
			s += c[k]
		print(int(s))	
		if(int(s)%90 == 0 and int(s) > mx):
			print("ESN")
			mx = int(s)
print(mx)