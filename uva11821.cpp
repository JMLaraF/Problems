from sys import stdin,stdout
from decimal import *


n = int(input())
while(n != 0):
    ans = Decimal(0)
    for i in range(n):
        x = Decimal(input())
        ans += x
    print(ans)
    n = int(input())
