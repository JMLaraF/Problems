#include <bits/stdc++.h>
#define INF 999999999999
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pll;

struct nodo
{
	ll dist , padre;
	bool encola;
	set<pll> Fx;
	nodo()
	{
		dist = INF;
		padre = -1;
		encola = false;
	}
};

bool bellmanFord(vector<nodo> &v , ll x)
{
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
		v[aux].encola = false;
		if(++procesados[aux] > 2*v.size())
			return true;
		for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
		{
			if(v[it->first].dist > v[aux].dist + it->second)
			{
				v[it->first].dist = v[aux].dist + it->second;
				v[it->first].padre = aux;
				if(!v[it->first].encola)
					cola.push(it->first);
				v[it->first].encola = true;	
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t , n , m , a , b , c ;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		vector <nodo> v(n);
		for(int i = 0 ; i < m ; i++)
		{
			cin >> a >> b >> c;
			v[a].Fx.insert(pll(b,c));
		}
		if(m == 0)
		{
			cout << "not possible\n";
			continue;
		}
		bool ans = bellmanFord(v,0);
		if(ans)
			cout << "possible\n";
		else
			cout << "not possible\n";
	}	
	return 0;
}