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

struct nodo
{
	bool vis;
	set<ll> Fx;
	nodo()
	{
		vis = false;
	}	
};

struct Grafo
{
	vector<nodo> v;
	Grafo(ll n)
	{
		v.assign(n,nodo());
	}
	void conect (ll x , ll y)
	{
		v[x].Fx.insert(y);
		v[y].Fx.insert(x);
	}

	vll DFS(ll x)
	{
		v[x].vis = true;
		vll ans(1,x+1);
		vll res;
		set<ll>::iterator it;
		for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
		{
			if(v[*it].vis)
				continue;
			res = DFS(*it);
			ans.insert(ans.end() , res.begin() , res.end());
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
		g.conect(a-1,b-1);
	}
	vector<vvll> grupos(4);
	vll res;
	for(int i = 0 ; i < n ; i++)
	{
		if(!g.v[i].vis)
		{
			res = g.DFS(i);
			if(res.size() > 3)
			{
				cout << "-1\n";
				return 0;
			}
			grupos[res.size()].pb(res);
		}
	}
	if(grupos[1].size() < grupos[2].size() && grupos[2].size() > 0 && grupos[1].size() > 0)
	{
		cout << "-1\n";
		return 0;
	}
	if(grupos[2].size() > 0 && grupos[1].size() > 0)
	{
		for(int i = 0 ; i < grupos[2].size() ; i++)
			cout << grupos[2][i][0] << ' ' << grupos[2][i][1] << ' ' << grupos[1][i][0] << '\n';
		for(int i = grupos[2].size() , j = 0 ; i < grupos[1].size() ; i++ , j++)
			cout << grupos[1][i][0] << ((j > 0 && j%3 == 0)?'\n':' ');
	}else if(grupos[1].size() > 0 && grupos[2].size() <= 0)
	{
		for(int i = 0 ; i < grupos[1].size() ; i++)
			cout << grupos[1][i][0] << ((i > 0 && i%3 == 0)?'\n':' ');
	}else if(grupos[2].size() > 0 && grupos[1].size() <= 0) 
	{
		cout << "-1\n";
		return 0;
	}
	for(int i = 0 ; i < grupos[3].size() ; i++)
		cout << grupos[3][i][0] << ' ' << grupos[3][i][1] << ' ' << grupos[3][i][2] << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}