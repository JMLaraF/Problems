#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
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
	ll v;
	set<ll> Fx;
	nodo()
	{
		v = -1;
	}
};

class Grafo
{
	private:
		vector<nodo> v;
		vpll aristas;
	public:
		Grafo(ll n)
		{
			v.assign(n,nodo());
		}
		void conect(ll x, ll y)
		{
			aristas.push_back(pll(x,y));
			v[x].Fx.insert(y);
			v[y].Fx.insert(x);
		}
		bool BFS()
		{
			ll aux = 0;
			queue<ll> cola;
			set<ll>::iterator it;
			cola.push(0);
			v[0].v = 0;
			while(!cola.empty())
			{
				aux = cola.front();
				cola.pop();
				for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
				{
					if(v[*it].v == v[aux].v)
						return false;
					else if(v[*it].v != -1)
						continue;
					cola.push(*it);
					v[*it].v = (v[aux].v+1)%2;
				}
			}
			return true;
		}
		void ans()
		{
			cout << "YES\n";
			for(int i = 0 ; i < aristas.size() ; i++)
			{
				if(v[aristas[i].xx].v == 0 && v[aristas[i].yy].v == 1)
					cout << 1;
				else
					cout << 0;
			}
			cout << '\n';
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
	bool f = g.BFS();
	if(f)
		g.ans();
	else
		cout << "NO\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}