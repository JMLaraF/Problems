#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define For(o,n) for(int i = 0 ; i < n ; i++)
#define nSize 1000005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

vll v;
bitset<nSize> bs;

void criba()
{
	for(ll i = 2 ; i < nSize ; i++)
	{
		if(bs[i] == 0)
			v.push_back(i);
		for(ll j = i*i ; j < nSize ; j += i)
			bs[j] = 1;		
	}
}

int main()
{_C
	criba();
	ll n;
	cin >> n;
	while(n != 0)
	{
		for(int i = 0 ; i < v.size() ; i++)
		{
			if(bs[n-v[i]] == 0)
			{
				cout << n << " = " << v[i] << " + " << n-v[i] << '\n';
				break;
			}
		}
		cin >> n;
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}
