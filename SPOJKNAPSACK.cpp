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
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

vector<vll> DP(2005,vll(2005,-1));

ll dp(ll x , ll y , vpll &v)
{
	if(x == 0)
		return 0;
	else if(x < 0)
		return -INF;
	if(y >= v.size())
		return 0;
	if(DP[x][y] != -1)
		return DP[x][y];
	DP[x][y] = max(dp(x-v[y].xx,y+1,v)+v[y].yy,dp(x,y+1,v));
	return DP[x][y];
}


int main()
{_C
	ll s , n;
	cin >> s >> n;
	vpll v(n);
	forn
		cin >> v[i].xx >> v[i].yy;
	cout << dp(s,0,v) << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}