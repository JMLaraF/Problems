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

ll to_Int(string s)
{
	ll ans = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == 'A')
			ans = ans|1LL;
		if(s[i] == 'B')
			ans = ans|2LL;
		if(s[i] == 'C')
			ans = ans|4LL;	
	}
	return ans;
}

vvll DP(8 , vll(1005 , -1));
ll n;
ll dp(ll x , ll y , vpll &v)
{
	if(y == 7)
		return 0;
	if(x == n)
		return INF;
	if(DP[y][x] != -1)
		return DP[y][x];
	DP[y][x] = min(dp(x+1,y|v[x].yy,v)+v[x].xx , dp(x+1,y,v));
	return DP[y][x];
}


int main()
{_C
	string s;
	cin >> n;
	vpll v(n);
	forn
	{
		cin >> v[i].xx >> s;
		v[i].yy = to_Int(s);
	}
	ll ans = dp(0,0,v);
	cout << ((ans < INF)?ans:-1) << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}