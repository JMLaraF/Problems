while(1):
	try:
		xx , yy = input().split()
	except:
		break
	a = int(xx)
	b = int(yy)
	ans = 0;
	for i in range(1 , a+1):
		ans = ans + i*(b**i)
	print(ans)

