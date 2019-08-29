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



int main()
{_C
	ll n , d , ans = 0 , ac = 0 , p = 0;
	cin >> n >> d;
	vpll v(n);
	forn
		cin >> v[i].xx >> v[i].yy;
	sort(v.begin() , v.end());
	ll l = 0 , r = 0;
	while(r < n)
	{
		if(p < d)
		{
			ac += v[r].yy;
			p = v[r++].xx-v[l].xx;
			if(p < d)
				ans = max(ans , ac);
		}else
		{
			ac -= v[l].yy;
			p = v[r-1].xx-v[++l].xx;
			if(p < d)
				ans = max(ans , ac);
		}
	}
	while(p >= d && l < n)
	{
		ac -= v[l].yy;
		p = v[r-1].xx-v[++l].xx;
		if(p < d)
			ans = max(ans , ac);
	}
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}