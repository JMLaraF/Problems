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

struct Disjoinset
{
	vll p;
	vll h;
	vll r;
	Disjoinset(ll n)
	{
		for(int i = 0 ;i < n ; ++i)
			p.pb(i);
		h.assign(n,0);
		r.assign(n,0);
	}
	ll getP(ll x)
	{
		return ((p[x] == x)? x : (p[x] = getP(p[x])));
	}
	bool join(ll a , ll b)
	{
		ll x= getP(a) , y = getP(b);
		if(x != y)
		{
			if(r[x] > r[y])
			{
				p[y] = x;
				h[x] += h[y]+1;
			}else
			{
				p[x] = y;
				h[y] += h[x]+1;
				if(r[x] == r[y])
					++r[y];
			}
			return true;
		}
		return false;
	}
};



int main()
{_C
	ll n, m , a , b , ans = 1;
	cin >> n >> m;
	Disjoinset ds(n);
	for(int i = 0 ; i< m ; i++)
	{
		cin >> a >> b;
		ds.join(a-1,b-1);
	}
	set<ll> ps;
	for(int i = 0 ; i < n ; i++)
	{
		ll x = ds.getP(i);
		if(!ps.count(x))
		{
			ans <<= ds.h[x];
			ps.insert(x);
		}
	}
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}