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

void resize(pll &m, ll x , ll y)
{
	if(m.xx == 0)
		m.xx = 1;
	if(m.yy == 0)
		m.yy = 1;
	if(m.xx % x != 0)
		m.xx += (x-(m.xx % x));
	if(m.yy % y != 0)
		m.yy += (y-(m.yy % y));
}


int main()
{_C
	ll a , b , x , y , z = 40;
	pll l , r , m , ans;
	cin >> a >> b >> x >> y;
	ll g = __gcd(x,y);
	x /= g;
	y /= g;
	l = pll(0,0);
	r = pll(2000000000*x,2000000000*y);
	while(z--)
	{
		m = pll(((l.xx+r.xx)/2),((l.yy+r.yy)/2));
		resize(m,x,y);
		if(m.xx <= a && m.yy <= b)
		{
			l.xx = m.xx;
			l.yy = m.yy;
			resize(l,x,y);
			ans = l;
		}else
		{
			r.xx = m.xx;
			r.yy = m.yy;
			resize(r,x,y);
		}
	}

	cout << ans.xx << ' ' << ans.yy << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}