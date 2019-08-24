#include <bits/stdc++.h>

using namespace std;


typedef long long ll;


int main()
{

	ll p , a , b;
	cin >> p;
	cin >> p;
	while(p != 0)
	{
		cin >> a >> b;
		ll x = 1;
		for(ll i = 0 ; i < 63 ; i++)
		{
			if((((ll)1 << i) & a) != 0)
				x = (x * p) % b;
			p = (p*p) % b;	
		}
		cout << x << '\n';
		cin >> p;
	}
	return 0;
}