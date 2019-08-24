#include <bits/stdc++.h>
#define INF 999999999999
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pll;

struct nodo
{
	ll dist , padre;
	bool encola;
	bool enciclo;
	set<pll> Fx;
	nodo()
	{
		dist = INF;
		padre = -1;
		encola = false;
		enciclo = false;
	}
};

bool bellmanFord(vector<nodo> &v , ll x)
{
	bool bans = false;
	ll aux;
	set<pll>::iterator it;
	queue<ll> cola;
	cola.push(x);
	v[x].dist = 0;
	v[x].encola = true;
	vector<ll> procesados (v.size() , 0);
	while(!cola.empty())
	{
		aux = cola.front();
		cola.pop();
//		cout << aux << " , " << v[aux].dist << '\n';
		v[aux].encola = false;
		if(++procesados[aux] == v.size())
		{
			bans = true;
			v[aux].enciclo = true;
		}
		for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
		{
			if(v[it->first].dist > v[aux].dist + it->second)
			{
				v[it->first].dist = v[aux].dist + it->second;
				v[it->first].padre = aux;
				if(!v[it->first].encola && v[it->first].enciclo == false)
				{
					cola.push(it->first);
					v[it->first].encola = true;	
				}
			}
		}
	}
	return bans;
}
int main()
{
//	ios::sync_with_stdio(false) ,	cin.tie(0);
	ll n , m , q , a , b , c = 0;
	while(cin >> n)
	{	
			vector <ll> p(n);
			vector <nodo> v(n);
			for(int i = 0 ; i < n ; i++)
				cin >> p[i];
			cin >> m;
			for(int i = 0 ; i < m ; i++)
			{
				cin >> a >> b;
				a--;
				b--;
				v[a].Fx.insert(pll(b,((p[b]-p[a])*(p[b]-p[a])*(p[b]-p[a]))));
			}
			cin >> q;
		if(n > 0)
		{
			bool ans = bellmanFord(v,0);
			cout << "Set #" << ++c << '\n';
			for(int i = 0 ; i < q ; i++)
			{
				cin >> a;
				if(v[a-1].enciclo == false)
				{
					if(v[a-1].dist >= 3 && v[a-1].dist < INF)
					{
						cout << v[a-1].dist << '\n';
					}else
					{
						cout << "?\n";
					}
				}else
				{	
					cout << "?\n";
				}
			}
		}else
		{
			cout << "Set #" << ++c << '\n';
		}
	}
	return 0;
}