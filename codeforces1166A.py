n = int(input())
d = {}
e = {}
ans = 0
fac = {0:1}
for i in range(1,60):
	fac[i] = fac[i-1]*i
for i in range(n):
	s = input()
	if(s[0] in d):
		if(s[0] in e):
			if(d[s[0]] < e[s[0]]):
				d[s[0]] += 1
			else:
				e[s[0]] += 1
		else:
			e[s[0]] = 1
	else:
		d[s[0]] = 1
print(d)
print(e)
for x in d:
	print(x)
	ans += fac[d[x]]
for x in e:
	print(x)
	ans += fac[e[x]]
print(ans)