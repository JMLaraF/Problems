#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
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

vvll DP(305,vll(305,-2));
ll n;


ll dp(ll x , ll y , vector<string> &v)
{
	if(y >= n || x >= n)
		return -2;
	if(DP[x][y] != -2)
		return DP[x][y];
	for(int i = y ; i < n ; i++)
		if(v[x] == v[i])
			DP[x][y] = max(DP[x][y],dp(x+1,i+1,v)+(ll)(2*(v[i].size())));
	return DP[x][y];
}

int main()
{_C
	ll len = 0;
	cin >> n;
	vector<string> v(n);
	forn
	{
		cin >> v[i];
		len += v[i].size()+1;
	}
	len--;
	ll ans = 0;
	forn
		ans = max(ans,dp(i,i+1,v));
	cout << len-ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}