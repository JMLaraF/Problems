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

vvll DP(4 , vll (5005 , -1));
string s;

ll dp(ll x , ll y)
{
	if(y > 2)
		return 0;
	if(x == s.size())
		return 0;
	if(DP[y][x] != -1)
		return DP[y][x];
	ll f = 0;
	if(((y == 0 || y == 2) && s[x] == 'a') || (y == 1 && s[x] == 'b'))
		f = max(dp(x+1,y)+1,dp(x+1,y+1)+1);
	DP[y][x] = max(f,dp(x+1,y));
	return DP[y][x];

}


int main()
{_C
	cin >> s;
	ll ans = 0;
	for(int j = 0 ; j < 3 ; j++)
		for(int i = 0 ; i < s.size() ; i++)
			ans = max(ans , dp(i,j));
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}