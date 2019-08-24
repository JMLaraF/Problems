#include <bits/stdc++.h>
#define INF 999999999999
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pll;

struct nodo
{
	ll dist , padre;
	bool encola;
	bool encliclo;
	bool block;
	set<pll> Fx;
	nodo()
	{
		dist = INF;
		padre = -1;
		encola = false;
		encliclo = false;
		block = false;
	}
};
bool DFSA(vector<nodo> &v , vector <bool> &vs, ll x , ll y , ll z)
{
	vs[x] = true;
	if(x == y)
	{
		return true;
	}
	bool ans = false;
	set<pll>::iterator it;
	for(it = v[x].Fx.begin() ; it != v[x].Fx.end() && ans == false; it++)
	{
		if(it->first != z && vs[it->first] == false)
			ans |= DFSA(v,vs,it->first,y,x);
	}
	if(ans)
//		cout << x + 1 << '\n';
	return ans;
}
bool DFS(vector<nodo> &v , vector <bool> &vs, ll x , ll y , ll z)
{
	vs[x] = true;
	if(100 - v[x].dist <= 0)
		return false;
	if(v[x].encliclo)
		return true;
	if(x == y)
	{
//		cout << x + 1 << '\n';
		return true;
	}
	bool ans = false;
	set<pll>::iterator it;
	for(it = v[x].Fx.begin() ; it != v[x].Fx.end() && ans == false; it++)
	{
		if(it->first != z && vs[it->first] == false)
			ans |= DFS(v,vs,it->first,y,x);
	}
	if(ans)
//		cout << x + 1 << '\n';
	return ans;
}

bool bellmanFord(vector<nodo> &v , ll x)
{
	vector<bool> vsa(v.size(),false);
	bool zzz = DFSA(v,vsa,0,v.size() - 1 , -1);
	if(zzz)
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
	//		cout << aux + 1 << " <AUX " << v[aux].dist << " <DIST\n";
			v[aux].encola = false;
			if(++procesados[aux] == 2*v.size())
			{
						
			}
			for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
			{
				if(v[it->first].dist < 0 && v[it->first].dist > v[aux].dist + it->second)
				{
					v[aux].encliclo = true;
				}else
		//		cout << it->first + 1 << " E\n";
				if(v[it->first].dist > v[aux].dist + it->second && (v[it->first].dist <= 100 || v[it->first].dist == INF))
				{
					v[it->first].dist = v[aux].dist + it->second;
					v[it->first].padre = aux;
					if(v[it->first].dist > 100)
						v[it->first].block = true;
					if(!v[it->first].encola && v[it->first].encliclo == false)
					{
						cola.push(it->first);
						v[it->first].encola = true;
					}
						
				}
			}
		}
	//	cout << v[v.size() - 1].dist << " <DSF\n";
		vector<bool> vs(v.size(),false);
		bool ss = DFS(v , vs, 0 , v.size()-1 , -1);
		if(ss)
			cout << "winnable\n";
		else
			cout << "hopeless\n";	
	}else
	{
		cout << "hopeless\n";
	}
	
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n , m , a , b , c ;
	cin >> n;
	while(n != -1)
	{
		vector<nodo> v(n);
		for(int i = 0 ; i < n ; i++)
		{
			cin >> m >> a;
			m *= -1;
			for(int j = 0 ; j < a ; j++)
			{
				cin >> b;
				v[i].Fx.insert(pll(b-1,m));
			}
		}
		bool ans = bellmanFord(v,0);
		cin >> n;
	}
	return 0;
}