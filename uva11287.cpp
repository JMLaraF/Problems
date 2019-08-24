#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

bool prime(ll x)
{
	if(x > 2 && x % 2 == 0)
		return false;
	for(int i = 3 ; i*i <= x ; i += 2)
		if(x%i == 0 )
			return false;
	return true;	
}

int main()
{
	ll p , a , b;
	cin >> p >> a;
	while(a != 0 && p != 0)
	{
		ll x = 1;
		b = a;
		for(ll i = 0 ; i < 63 ; i++)
		{
			if((((ll)1 << i) & p) != 0)
				x = (x * a) % p;
			a = (a*a) % p;	
		}
//		cout << x << " , " << b << '\n';
		if(x != b || prime(p))
			cout << "no\n";
		else
			cout << "yes\n";	
		cin >> p >> a;	
	}
	return 0;
}