#include <bits/stdc++.h>
#define nSize 65000

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll v;
void criba()
{
	bitset<nSize> bs;
	v.push_back(2);
	for(ll i = 3 ; i < nSize ; i += 2)
	{
		if(bs[i] == 0)
			v.push_back(i);
		for(ll j = i*i ; j < nSize ; j += i)
			bs[j] = 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	criba();
	ll n , a;
	cin >> n;
	while(n--)
	{
		cin >> a;
		if(a < 2)
		{
			cout << 2 << '\n';
			continue;
		}

		a--;
		bool d = false;
		do
		{
			d = false;
			a++;
			for(int i = 0 ; v[i]*v[i] <= a && d == false ; i++)
				if(a%v[i] == 0)
					d = true;
		}while(d == true);
		cout << a << '\n';
	}

	return 0;
}