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

ll n;
vvll DP(105,vll (3,-1));

ll dp (ll x ,ll i , vll &v)
{
	if(i == 0)
	{
		if(v[i] == 0)
			return 0;
		else
			return 1;
	}
	if(DP[i][x] != -1)
		return DP[i][x];
	if(x == 0)
		DP[i][x] = max(max(dp(0,i-1,v),dp(1,i-1,v)),dp(2,i-1,v));
	else if(x == 1)
		DP[i][x] = max(dp(0,i-1,v),dp(2,i-1,v))+1;
	else
		DP[i][x] = max(dp(0,i-1,v),dp(1,i-1,v))+1;
	return DP[i][x];
}


int main()
{_C
	ll n;
	cin >> n;
	vll v(n);
	forn
		cin >> v[i];
	cout << dp(v[n-1],n-1)
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}