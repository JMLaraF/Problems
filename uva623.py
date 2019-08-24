fact = [1]
x = 1
for i in range(1,1001):
	x = x*i
	fact.append(x)
while(1):
    try:
        n = int(input())
    except:
        break
    print(str(n)+"!")
    print(fact[n])