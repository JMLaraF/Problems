from sys import stdin,stdout
from decimal import *

getcontext().prec = 30
n = int(input())
for i in range(n):
    ans = Decimal("0")
    x = Decimal(input())
    while((Decimal.compare(x , Decimal("0")))):
        ans = ans + x
        x = Decimal(input())
    stdout.write("{:f}".format(ans).rstrip('0').rstrip('.') + '\n')
    