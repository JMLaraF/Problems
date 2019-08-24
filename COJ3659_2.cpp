F = [1]
ans = 1
for i in range (1 to 41):
	ans = ans*i
	F.append(ans)
t = int(input())
for i in range (0 to t):
	a = int(input())
	print(F[a])
