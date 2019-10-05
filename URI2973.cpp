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
	ll n, c, t , x = 60;
	cin >> n >> c >> t;
	vll v(n);
	forn
		cin >> v[i];
	ll l = 0 , r = 1LL<<40 , m , y , z , ans;
	while(x--)
	{
		m = (l+r)/2;
		y = t*m;
		z = 1;
		for(int i = 0 ; i < n ; i++)
		{
			if(y >= v[i])
				y -= v[i];
			else if(t*m >= v[i])
			{
				z++;
				y = t*m;
				i--;
			}else
				z = 1LL<<40;
		}
		if(z <= c)
		{
			ans = m;
			r = m;
		}else
		{
			l = m;
		}
	}
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}