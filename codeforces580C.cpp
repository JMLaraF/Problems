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

ll m;

struct Grafo
{
	vvll Fx;
	vll v;
	Grafo(ll n)
	{
		Fx.assign(n,vll());
		v.assign(n,0);
	}
	void unir(ll x , ll y)
	{
		Fx[x].pb(y);
		Fx[y].pb(x);
	}
	void setCat(ll x)
	{
		v[x] = 1;
	}
	ll countPaths(ll x , ll y , ll p)
	{
		ll ans = 0;
		vll::iterator it;
		bool f = false;
		if(y+v[x] > m)
			return 0;
		for(it = Fx[x].begin() ; it != Fx[x].end() ; it++)
		{
			if(*it == p)
				continue;
			f = true;
			ans += countPaths(*it , ((v[x] == 0)?0:y+v[x]) , x);
		}
		if(!f)
			return (y+v[x] <= m)? 1 : 0;
		else
			return ans;
	}
};


int main()
{_C
	ll n , a , b;
	cin >> n >> m;
	Grafo g(n);
	forn
	{
		cin >> a;
		if(a != 0)
			g.setCat(i);
	}
	for(int i = 0 ; i < n-1 ; i++)
	{
		cin >> a >> b;
		g.unir(a-1,b-1);
	}
	cout << g.countPaths(0,0,0) << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}