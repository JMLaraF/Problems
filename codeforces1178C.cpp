#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 998244353
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

ll pot(ll a , ll b)
{
	ll ans = 1;
	for(int i = 0 ; i < 63 ; i++)
	{
		if(((1LL<<i)&b)!=0)
			ans = (ans*a)%MOD;
		a = (a*a)%MOD;
	}
	return ans;
}

int main()
{_C
	ll h , w;
	cin >> w >> h;
	cout << pot(2,h+w) << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}