#include <bits/stdc++.h>
#define xx first
#define yy second
#define NOP 25
#define INF 999999999
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

struct nodo
{
	ll lv;
	ll ch;
	set<pll>Fx;
	vector<pll>Pb;
	nodo()
	{
		lv = 0;
		ch = 0;
		Pb.assign(NOP,pll(0,INF));
	}
};

ll root , n;

class Disjoinset
{
	private:
	vll p , rank;
	public:
	Disjoinset(ll n)
	{
		rank.assign(n , 0);
		for(ll i = 0 ; i < n ; i++)
			p.push_back(i);
	}

	ll getset (ll x)
	{
		return (p[x] == x)? x : (p[x] = getset(p[x]));
	}

	bool buscar (ll x , ll y)
	{
		return getset(x) == getset(y);
	}

	bool unir(ll i , ll j)
	{
		ll x = getset(i) , y = getset(j);
		if(x != y)
		{
			if(rank[x] > rank[y])
				p[y] = x;
			else
			{
				p[x] = y;
				if(rank[x] == rank[y])
					rank[y]++;
			}
			return true;		
		}
		return false;
	}
};

class tree
{
	private:
		vector<nodo> v;

	public:
		tree(ll n)
		{
			v.assign(n,nodo());
			root = 0;
		}
		tree(ll n , ll r)
		{
			v.assign(n,nodo());
			root = r;
		}

		void conect(ll x , ll y , ll z)
		{
			v[x].Fx.insert(pll(y,z));
			v[y].Fx.insert(pll(x,z));
		}

		void Centroide (ll x , ll p)
		{
			bool c = true;
			set<pll>::iterator it;
			for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
			{
				if(it->xx != p)
				{
					Centroide(it->xx , x);
					v[x].ch += v[it->xx].ch + 1;
					if(v[it->xx].ch > n/2)
						c = false;
				}
			}
			if(c)
			{
				root = x;
				v[x].Pb[0].xx = x;
			}
		}

		void LV(ll x , ll l , ll p)
		{
			v[x].lv = l;
			set<pll>::iterator it;
			for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
			{
				if(it->xx != p)
				{
					v[it->xx].Pb[0].xx = x;
					v[it->xx].Pb[0].yy = it->yy;
					LV(it->xx , l + 1 , x);
				}
			}
		}

		void BinaryP()
		{
			for(ll i = 1 ; i < NOP ; i++)
			{
				for(ll j = 0 ; j < v.size() ; j++)
				{
					v[j].Pb[i].xx = v[v[j].Pb[i-1].xx].Pb[i-1].xx;
					v[j].Pb[i].yy = min(v[j].Pb[i - 1].yy , v[v[j].Pb[i - 1].xx].Pb[i - 1].yy);
				}
			}
		}

		ll LCA(ll x , ll y)
		{
			ll dif = abs(v[x].lv - v[y].lv);
			ll p1 , p2;
			ll ans = (ll)1<<60;
			if(v[x].lv > v[y].lv)
			{
				p1 = x;
				p2 = y;
			}else
			{
				p1 = y;
				p2 = x;
			}
//			cout << p1 << " , " << p2 << " , " << dif << " <DIF\n";
			if(dif > 0)
			{
				for(ll i = 0 ; ((ll)1<<i) <= dif ; i++)
				{
					if((((ll)1 << i) & dif) != 0)
					{
						ans = min(ans , v[p1].Pb[i].yy);
						p1 = v[p1].Pb[i].xx;
					}
				}
			}

			if(p1 == p2)
				return ans;
			else
			{
				for(ll i = NOP - 1 ; i >= 0 ; i--)
				{
					if(v[p1].Pb[i].xx != v[p2].Pb[i].xx)
					{
						ll t = min(v[p1].Pb[i].yy , v[p2].Pb[i].yy);
						ans = min(ans , t);
						p1 = v[p1].Pb[i].xx;
						p2 = v[p2].Pb[i].xx;
					}
				}
				ll t = min(v[p1].Pb[0].yy , v[p2].Pb[0].yy);
				ans = min(ans , t);
				return ans;
			}
		}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll m , q , a , b , c;
	while(cin >> n >> m >> q)
	{
		tree tr(n);
		priority_queue < pair < ll , pll > > EdgeList;
		for(ll i = 0 ; i < m ; i++)
		{
			cin >> a >> b >> c;
			EdgeList.push(make_pair(c ,pll( --a , --b)));
		}
		Disjoinset ds(n);
		pair < ll , pll > paux;
		while(!EdgeList.empty())
		{
			paux = EdgeList.top();
			EdgeList.pop();
			if(ds.unir(paux.yy.xx , paux.yy.yy))
			{
				tr.conect(paux.yy.xx , paux.yy.yy , paux.xx);
			}
		}
		tr.Centroide(0,0);
		tr.LV(root,0,root);
		tr.BinaryP();
		for(ll i = 0 ; i < q ; i++)
		{
			cin >> a >> b;
			cout << tr.LCA(--a , --b) << '\n';
		}
	}
	return 0;
}