#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define MOD 1000000007
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;


ll inversoMod(ll a)
	{
		ll b = MOD;
		ll b0 = b, t , q;
		ll x0 = 0 , x1 = 1;
		if(b == 1) return 1;
		while(a > 1)
		{
			q = a / b;
			t = b , b = a % b , a = t;
			t = x0 , x0 = x1 - q * x0 , x1 = t;
		}
		if(x1 < 0) x1 += b0;
		return x1;
	}

int main()
{_C
	ll n;
	ll a;
	cin >> a;
	while(a--)
	{
		cin >> n;
		ll z , x , c;
		z = (n+1);
		x = (ll)floor((ld)n/2);
		c = (x*x)%MOD;
		if(n%2!=0)
			cout << (((z+c)%MOD)+x)%MOD << '\n';
		else
			cout << (z+c)%MOD << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}

