#include<bits/stdc++.h>
#define INF ((ll)1<<60)
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

struct nodo
{
	ll v;
	set<pll> Fx;
	nodo()
	{
		v = INF;
	}
};

class Grafo
{
	private:
		vector<nodo> gp;
	public:
		Grafo(ll sz)
		{
			gp.assign(sz , nodo());
		}
		void join(ll x , ll y , ll z)
		{
			gp[x].Fx.insert(pll(z , y));
			gp[y].Fx.insert(pll(z , x));
		}
		void Dijkstra (ll x , ll y)
		{
			for(ll i = 0 ; i < gp.size() ; i++)
				gp[i].v = INF;
			int xAux;
			priority_queue < pll > pq;
			pq.push(pll (0,x));
			gp[x].v = 0;
			set<pll>::iterator it;
			while(!pq.empty())
			{
				xAux = pq.top().yy;
				pq.pop();
				for(it = gp[xAux].Fx.begin() ; it != gp[xAux].Fx.end() ; it++)
				{
					if(gp[it->yy].v > gp[xAux].v + it->xx && it->xx <= y)
					{
						gp[it->yy].v = gp[xAux].v + it->xx;
						pq.push(pll(-gp[it->yy].v , it->yy));
					}	
				}
			}
		}
		ll getDist(ll x)
		{
			return gp[x].v;
		}

};


int main()
{
	ll n , m , k , a , b , c;
	cin >> n >> m >> k;
	Grafo G(n);
	while(m--)
	{
		cin >> a >> b >> c;
		G.join(--a , --b , c);
	}
	G.Dijkstra(0,INF);
	double dx = G.getDist(n-1)*(1+((double)k/100));
	ll l = 0 , r = INF , mid;
	while(l < r)
	{
		mid = (l+r)/2;
		G.Dijkstra(0,mid);
		if((double)G.getDist(n-1) <= dx)
			r = mid;
		else
			l = mid +1;
	}
	cout << r << '\n';
	return 0;
}