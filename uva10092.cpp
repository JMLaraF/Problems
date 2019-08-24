#include <bits/stdc++.h>
#define xx first
#define yy second
#define INF (ll)1<<62
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef vector<ll> vll;

/*	El primer elemento de la tripleta es el nodo al cual conecta dicha arista
	El segundo elemento es la capacidad de esta
	El tercer es la cantidad de flujo que lleva en el momento.
*/


struct nodo
{
	ll lv;
	vector<ll> p;
	set<ll> Fx;
	nodo()
	{
		lv = INF;
	}
};

class FGraph
{
	private:
		ll s , t;
		vector<vector<pll> > G;
		vector<vector< vector <ll> > > CH;
		vector<nodo> v;
	public:
		FGraph(ll n)
		{
			s = 0;
			t = n - 1;
			CH.assign(n,vector < vector < ll > >(n));
			v.assign(n,nodo());
			G.assign(n , vector<pll> (n,pll(-1,0)));
		}
		FGraph(ll n , ll sx , ll tx)
		{
			s = sx;
			t = tx;
			v.assign(n,nodo());
			G.assign(n , vector<pll> (n,pll(-1,0)));
		}

		void conect(ll x , ll y , ll z)
		{
			if(!v[x].Fx.count(y))
			{
				v[x].Fx.insert(y);
				v[y].Fx.insert(x);
				G[x][y].xx = z;
				G[x][y].yy = 0;
				G[y][x].xx = z;
				G[y][x].yy = z;
			}else
			{
				G[x][y].xx += z;
				G[y][x].xx += z;
				G[y][x].yy += z;
			}	
		}
		void setS(ll sx)
		{
			s = sx;
		}
		void setT(ll tx)
		{
			t = tx;
		}

		bool BFS()
		{
			ll u;
			bool camino = false;
			set<ll>::iterator it;
			for(ll i = 0 ; i < v.size() ; i++)
				v[i].lv = INF;
			queue<ll> cola;
			cola.push(s);
			v[s].lv = 0;
			while(!cola.empty())
			{
				u = cola.front();
//				cout << u << " <U\n";
				cola.pop();
				if(u == t)
					camino = true;
				for(it = v[u].Fx.begin() ; it != v[u].Fx.end() ; it++)
				{
					if(v[*it].lv > v[u].lv + 1 && G[u][*it].xx > G[u][*it].yy)
					{
						v[*it].lv = v[u].lv + 1;
						cola.push(*it);
					}	
				}
			}
			return camino;
		}

		ll sendF (ll x , ll actFlow , ll asd)
		{
//			cout << x << " , " << actFlow << '\n';
			if(x == t)
				return actFlow;
			set<ll>::iterator it;
			ll temFlow = 0;
			for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
			{
				if(v[*it].lv == v[x].lv + 1 && G[x][*it].xx > G[x][*it].yy)
					temFlow = sendF(*it , min(actFlow , G[x][*it].xx - G[x][*it].yy) , (x == s)? *it : asd);
				if(temFlow > 0)
				{
					CH[x][*it].push_back(asd);
					G[x][*it].yy += temFlow;
					G[*it][x].yy -= temFlow;
					return temFlow;
				}	
			}
			return 0;
		}

		ll maxFlow()
		{
			int q;
			if(s == t)
				return -1;
			ll ans = 0 , flow;
			while(BFS())
			{
				do
				{
					flow = sendF(s,INF,-1);
					ans += flow;
				}while(flow > 0);
					
			}
			return ans;	
		}

		ll size()
		{
			return v.size();
		}

		vector<ll> FA(ll x , ll y)
		{
			return CH[x][y];
		}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n , m , a , b , c , sum = 0 , ans;
	cin >> n >> m;
	while(n != 0 || m != 0)
	{
		sum = 0 , ans = 0;
		FGraph ff(n+m + 2);
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> a;
			sum += a;
			ff.conect(i , ff.size() - 1 , a);
		}
		for(ll i = 1 ; i <= m ; i++)
		{
			ff.conect(0 , n+i , 1);
			cin >> a;
			for(ll j = 0 ; j < a ; j++)
			{
				cin >> b;
//				cout << b << " , " << n + i << '\n';
				ff.conect(n + i , b , 1);
			}
		}
		ans = ff.maxFlow();
//		cout << ans << " <MF\n";
		if(ans == sum)
		{
			cout << "1\n";

			for(int i = 1 ; i <= n ; i++)
			{
				vector<ll> q = ff.FA(i,ff.size() - 1);
				for(int j = 0 ; j < q.size() ; j++)
				{
					cout << q[j] - n ;
				if(j < q.size() - 1)
					cout << ' ';
				else
					cout << '\n';
				}
			}
		}else
			cout << "0\n";
		cin >> n >> m;
	}
	return 0;
}