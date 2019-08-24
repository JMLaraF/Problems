#include <bits/stdc++.h>

using namespace std;

struct nodo
{
	int color;
	set<int> Fx;
	nodo()
	{
		color = -1;
	}
};

bool Bipartite (vector<nodo> &v , int x)
{
	set<int>::iterator it;
	queue<int> cola;
	cola.push(x);
	v[x].color = 0;
	while(!cola.empty())
	{
		x = cola.front() , cola.pop();
		for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
		{
			if(v[*it].color == -1)
			{
				v[*it].color = 1 - v[x].color;
				cola.push(*it);	
			}else if(*it != x && v[*it].color == v[x].color)
			{
				return false;
			}
		}
	}
	return true;
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
		bool ans = true;
		for(int i = 0 ; i < n ; i++)
		{
			if(v[i].color == -1)
				ans &= Bipartite(v,i); 	
		}
		if(ans)
			cout << "YES\n";
		else
			cout << "NO\n";
		cin >> n;

	}
	
	return 0;
}