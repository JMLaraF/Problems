import math

fact = [1]
x = 1
for i in range(1,100):
	x = x*i
	fact.append(x)
while(1):
    try:
        xx , yy = input().split()
    except:
        break
    a = int(xx)
    b = int(yy)
    x = fact[a]
    ans1 = math.ceil(math.log(x)/math.log(b))
    ans2 = 0
    while(x%b==0):
    	x = x/b
    	ans2 = ans2+1
    print(str(ans2) + " " + str(int(ans1)))