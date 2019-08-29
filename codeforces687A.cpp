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
	vvll Fx;
	vll color;
	Grafo(ll n)
	{
		Fx.assign(n,vll());
		color.assign(n,-1);
	}	
	void unir(ll x , ll y)
	{
		Fx[x].pb(y);
		Fx[y].pb(x);
	}
	bool Bipartite(ll x , vvll &s)
	{
		bool ans = true;
		queue<ll> cola;
		cola.push(x);
		color[x] = 0;
		s[0].pb(x);
		while(!cola.empty())
		{
			ll aux = cola.front();
			cola.pop();
			for(ll it : Fx[aux])
			{
				if(color[it] == color[aux])
					ans = false;
				else if(color[it] == -1)
				{
					color[it] = 1-color[aux];
					cola.push(it);
					s[color[it]].pb(it);
				}
			}
		}
		return ans;
	}
};


int main()
{_C
	ll n, m , a , b;
	cin >> n >> m;
	Grafo g(n);
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a >> b;
		g.unir(a-1,b-1);
	}
	bool ans;
	vvll st(2,vll());
	for(int i = 0 ; i < n ; i++)
	{
		
		if(g.color[i] == -1)
		{
			if(g.Fx[i].empty())
				continue;
			ans = g.Bipartite(i,st); 
		}
		if(!ans)
		{
			cout << "-1\n";			
			return 0;
		}
	}
	for(int k = 1 ; k >= 0 ; k--)
	{
		cout << st[k].size() << '\n';
		for(int j = 0 ; j < st[k].size() ; j++)
			cout << st[k][j]+1 << ((j == st[k].size()-1)?'\n':' ');
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}