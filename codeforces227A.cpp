#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ll n , a = 0 , b = 0 , c , m;
	cin >> n;
	map<ll , pll> mp;
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> c;
		if(mp.count(c))
		{
			mp[c].xx = min(mp[c].xx , i+1);
			mp[c].yy = max(mp[c].yy , i);
		}else
		{
			mp[c].xx = i+1;
			mp[c].yy = i;
		}
	}
	cin >> m;
	while(m--)
	{
		cin >> c;
		a += mp[c].xx;
		b += n-mp[c].yy;
	}
	cout << a << ' ' << b << '\n';


	return 0;
}