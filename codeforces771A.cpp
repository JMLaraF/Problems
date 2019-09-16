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

struct Grafo
{
	vll v;
	vvll Fx;
	Grafo(ll n)
	{
		v.assign(n,0);
		Fx.assign(n,vll());
	}
	void unir(ll x , ll y)
	{
		Fx[x].pb(y);
		Fx[y].pb(x);
	}	
	bool DFS(ll x , ll y , ll z)
	{
		v[x] = 1;
		bool f = false, k = true;
		vll::iterator it;
		for(it = Fx[x].begin() ; it != Fx[x].end() ; it)
		{
			if(*it == y)
				continue;
			if(z != -1)
			{
				f |= (*it == z);
			}else
			{
				f = true;
			}
			if(v[*it] == 0)
				k &= DFS(*it,x,y);
		}
		return (f&&k);
	}
	void clear()
	{
		v.assign(v.size(),0);
	}

};


int main()
{_C
	ll n , m , a , b;
	cin >> n >> m;
	Grafo g(n);
	bool f = true;
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a >> b;
		g.unir(a-1,b-1);
	}
	f &= g.DFS(0,-1,-1);
	g.clear();
	f &= g.DFS(n/2,-1,-1);
	g.clear();
	f &= g.DFS(n-1,-1,-1);
	g.clear();
	if(f)
		cout << "YES\n";
	else
		cout << "NO\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}