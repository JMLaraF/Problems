#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define MOD 10000007
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

ll pot(ll a , ll b)
{
	ll ans = 1;
	if(b == 0)
		return 1;
	for(int i = 0 ; i < 63 ; i++)
	{
		if((((ll)1<<i)&b)!=0)
			ans = ((ans*a)+MOD)%MOD;
		a = ((a*a)+MOD)%MOD;
	}
	return ans;
}

int main()
{_C
	ll n , k;
	cin >> n >> k;
	while(n != 0 && k != 0)
	{
		ll sn = 0 , pn = 0, zn = 0;
		zn = ((pot(n,k) + pot(n,n))%MOD + ((2*pot(n-1,k))%MOD+(2*pot(n-1,n-1))%MOD)%MOD)%MOD;
		cout << zn << '\n';
		cin >> n >> k;
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}