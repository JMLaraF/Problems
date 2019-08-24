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
	ll color;
	set<ll> Fx;
	nodo()
	{
		color = -1;
	}	
};

struct Grafo
{
	vector<nodo> v;
	Grafo(ll n)
	{
		v.assign(n,nodo());
	}
	void conect(ll x, ll y)
	{
		v[x].Fx.insert(y);
		v[y].Fx.insert(x);
	}
	ll BFS(ll x)
	{
		ll ans = 0;
		ll aux;
		queue<ll> cola;
		v[x].color = 0;
		cola.push(x);
		set<ll>::iterator it;
		while(!cola.empty())
		{
			aux = cola.front();
			cola.pop();
			if(v[aux].color == 0)
				ans++;
			for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
			{
				if(v[*it].color != -1)
					continue;
				v[*it].color = (v[aux].color+1)%2;
				cola.push(*it);
			}
		}
		return ans;
	}
};


int main()
{_C
	ll q , n , m , a , b , k = 0;
	cin >> q;
	while(q--)
	{
		k = 0;
		cin >> n >> m;
		Grafo g(n);
		for(int i = 0 ; i < m ; i++)
		{
			cin >> a >> b;
			g.conect(a-1,b-1);
		}
		vll ans;
		for(int i = 0 ; i < n ; i++)
		{
			if(g.v[i].color == -1)
				k += g.BFS(i);
		}
		if(k <= n/2)
		{
			cout << k << '\n';
			for(int i = 0 ; i < n ; i++)
				if(g.v[i].color == 0)
					cout << i+1 << ((i == n-1)?"":" ");
			cout << '\n';
		}else
		{
			cout << n-k << '\n';
			for(int i = 0 ; i < n ; i++)
				if(g.v[i].color == 1)
					cout << i+1 << ((i == n-1)?"":" ");
			cout << '\n';
		}
		
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}