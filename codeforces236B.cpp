#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

vll divs(1000005,1);

void criba()
{
	for(ll i = 2 ; i <= 1000000 ; i++)
	{
		for(ll j = i ; j <= 1000000 ; j += i)
			divs[j]++;
	}
}

int main()
{_C
	criba();
//	for(int i = 0 ; i < 100 ; i++)
//		cout << divs[i] << '\n';
	ll x , y , z , ans = 0;
	cin >> x >> y >> z;
	for(int i = 1 ; i <= x ; i++)
	{
		for(int j = 1 ; j <= y ; j++)
		{
			for(int k = 1 ; k <= z ; k++)
			{
				ans = (ans+divs[i*j*k])%1073741824;
			}
		}
	}
	cout << ans << '\n';


	#ifdef LOCAL
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}