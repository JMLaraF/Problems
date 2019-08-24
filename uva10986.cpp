#include <bits/stdc++.h>
#define INF (int)10e9
using namespace std;

typedef pair < int , int > pll;


struct nodo
{
	int v;
	vector<pll>Fx;
	nodo()
	{
		v = INF;
	}
};

void Dijkstra (vector < nodo > &v , int x )
{
	int xAux;
	priority_queue < pll > pq;
	pq.push(pll (0,x));
	while(!pq.empty())
	{
		xAux = pq.top().second;
		pq.pop();
		for(int it = 0 ; it < v[xAux].Fx.size() ; it++)
		{
			if(v[v[xAux].Fx[it].second].v > v[xAux].v + v[xAux].Fx[it].first)
			{
				v[v[xAux].Fx[it].second].v = v[xAux].v + v[xAux].Fx[it].first;
				pq.push(pll(-v[v[xAux].Fx[it].second].v , v[xAux].Fx[it].second));
			}	
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t , m , n , a , b , c , x , y , cs = 0;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> x >> y;
		vector < nodo > v(n);
		for(int i = 0 ; i < m ; i++)
		{
			cin >> a >> b >> c;
			v[a].Fx.push_back(pll(c,b));
			v[b].Fx.push_back(pll(c,a));
		}
		v[x].v = 0;
		Dijkstra(v , x);
		if(v[y].v != INF)
			cout << "Case #" << ++cs << ": " << v[y].v << '\n';
		else
			cout << "Case #" << ++cs << ": unreachable\n";
	}

	return 0;
}