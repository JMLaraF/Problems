#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

ll n , k;
vvll DP(2005 , vll(2000,-1));

ll dp(ll x , ll y)
{
	if(y == 0)
		return (x <= n)? 1 : 0;
	if(DP[x][y] != -1)
		return DP[x][y];
	DP[x][y] = 0;
	for(int i = x ; i <= n ; i += x)
	{
		DP[x][y] += dp(i,y-1);
		DP[x][y] %= MOD;
	}
	return DP[x][y];
}


int main()
{_C
	cin >> n >> k;
	ll ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		ans += dp(i,k-1);
		ans %= MOD;
	}
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}