#include <bits/stdc++.h>

using namespace std;

typedef pair <int,int> pii;

struct nodo
{
	int color;
	set<int> Fx;
	nodo()
	{
		color = -1;
	}
};

pii Bipartite (vector<nodo> &v , int x)
{
	set<int>::iterator it;
	queue<int> cola;
	cola.push(x);
	v[x].color = 0;
	pii cont(1,0);
	while(!cola.empty())
	{
		x = cola.front() , cola.pop();
		for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
		{
			if(v[*it].color == -1)
			{
				v[*it].color = 1 - v[x].color;
				cola.push(*it);
				if(v[*it].color == 0)
					cont.first++;
				else
					cont.second++;
			}else if(v[*it].color == v[x].color)
			{
				return pii(-1,0);
			}
		}
	}
	return cont;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t , n , m , a , b;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		vector<nodo> v(n);
		for(int i = 0 ; i < m ; i++)
		{
			cin >> a >> b;
			v[a].Fx.insert(b);
			v[b].Fx.insert(a);
		}
		int ans = 0;
		bool bp = true;
		for(int i = 0 ; i < n ; i++)
		{
			if(v[i].color == -1)
			{
				pii aux = Bipartite(v,i);
				if(aux.first == -1)
				{
					bp = false;
					break;
				}
				if(aux.second != 0)
					ans += min(aux.first,aux.second);
				else
					ans++;		
			}
		}
		if(bp)
			cout << ans << "\n";
		else
			cout << "-1\n";
	}
	
	return 0;
}