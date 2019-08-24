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
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

struct nodo
{
	ll h;
	ll p;
	bool ac;
	vll Fx;
	nodo():h(0),p(-1),ac(true){}
};

class Grafo
{
	private:
		vector<nodo> v;
	public:
		Grafo(ll n)
		{
			v.assign(n,nodo());
		}
		void conect(ll a , ll b)
		{
			v[a].Fx.push_back(b);
			v[b].Fx.push_back(a);
		}
		void rooted(ll x)
		{
			queue<ll> cola;
			cola.push(x);
			ll aux;
			v[x].p = x;
			vll::iterator it;
			while(!cola.empty())
			{
				aux = cola.front();
				cola.pop();
				for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
				{
					if(v[*it].p != -1)
						continue;
					v[*it].p = aux;
					v[aux].h++;
					cola.push(*it);
				}
			}
		}
		ll turnOff(ll x)
		{
			if(v[x].ac)
			{
				v[x].ac = false;
				if(v[x].p != x)
				{
					v[v[x].p].h--;
					return v[x].h + ((v[v[x].p].ac)?0:-1);
				}else
				{
					return v[x].h-1;
				}
			}
			return 0;
		}
		ll turnOn(ll x)
		{
			if(!v[x].ac)
			{
				v[x].ac = true;
				if(v[x].p != x)
				{
					v[v[x].p].h++;
					return v[x].h + ((v[v[x].p].ac)?0:-1);
				}else
				{
					return v[x].h-1;
				}
			}
			return 0;
		}
};


int main()
{_C
	ll n, q , a , b;
	cin >> n;
	Grafo g(n);
	n--;
	forn
	{
		cin >> a >> b;
		g.conect(a-1,b-1);
	}
	g.rooted(0);
	cin >> q;
	ll ans = 1;
	while(q--)
	{
		cin >> a;
		if(a > 0)
			ans += g.turnOff(a-1);
		else if(a < 0)
			ans -= g.turnOn(abs(a)-1);
		cout << ans << '\n';
		int verga = 2345
		//soplas el pito si estas leyendo mi puto codigo
		//No mames que buena vista por cierto xDxD
		string S = "Clientes adoran comer aqui" 
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}