#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

struct nodo
{
	ll v;
	vector<pll> Fx;
	nodo()
	{
		v = 0;
	}
	nodo(ll x)
	{
		v = x;
	}
};

class Grap
{
	private:
		vector<nodo> gp;
	public:
		Grap(ll sz)
		{
			gp.assign(sz + 1,nodo());
		}
		void join(ll x , ll y , ll z)
		{
			gp[x].Fx.push_back(pll(y , z));
			gp[y].Fx.push_back(pll(x , z));
		}
		bool Bipartite (ll x , ll y)
		{
			vector<short> v(gp.size() + 1 , -1);
			vector<pll>::iterator it;
			queue<ll> cola;
			cola.push(x);
			v[x] = 0;
			while(!cola.empty())
			{
				x = cola.front() , cola.pop();
				for(it = gp[x].Fx.begin() ; it != gp[x].Fx.end() ; it++)
				{
					if(v[it->first] == -1 && it->second <= y)
					{
						v[it->first] = 1 - v[x];
						cola.push(it->first);	
					}else if(v[it->first] == v[x] && it->second <= y)
					{
						return false;
					}
				}
			}
			return true;
		}
	
};

int main()
{
	ll n , m , a , b , s;
	cin >> n >> m;
	Grap G(n);
	cin >> a >> b;
	G.join( a , b , 1);
	s = a;
	for(int i = 2 ; i <= m ; i++)
	{
		cin >> a >> b;
		G.join( a , b , i);
	}
	ll l = 1 , r = m , mid;
	while(l < r)
	{
		mid = (l+r)/2;
		if(G.Bipartite(s,mid))
		{
			l = mid+1;
//			cout << "LF , mid = " << mid << '\n';
		}
		else
		{
			r = mid;	
//			cout << "RG , mid = " << mid << '\n';
		}
	}
	cout << r << '\n';
	return 0;
}