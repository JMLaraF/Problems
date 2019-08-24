#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ll n , m;
	cin >> n;
	vll v1(n);
	For(o,n)
		cin >> v1[i];
	cin >> m;
	vll v2(m);
	for(int i = 0 ; i < m ; i++)
		cin >> v2[i];
	map<ll,ll> mp;
	ll x = 0;
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			if(v1[j] > v2[i])
				break;
			if(v2[i]%v1[j] == 0)
			{
				mp[v2[i]/v1[j]]++;
				if(v2[i]/v1[j] > x)
					x = v2[i]/v1[j];
			}
		}
	}
	cout << mp[x] << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}