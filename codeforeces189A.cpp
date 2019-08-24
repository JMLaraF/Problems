#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
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

vll SG(4005,-1);
ll a , b , c;


ll dp(ll x)
{
	if(x < 0)
		return -INF;
	if(x == 0)
		return 0;
	if(SG[x] != -1)
		return SG[x];
	return (SG[x] = max(dp(x-a),max(dp(x-b),dp(x-c))) + 1);
}

int main()
{_C
	ll x;
	cin >> x >> a >> b >> c;
	cout << dp(x) << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}