#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

struct Grafo
{
	vvll Fx;
	vll dist;
	vll vis;
	Grafo(ll n)
	{
		Fx.assign(n,vll());
		dist.assign(n,0);
	}
	void join(ll x ,ll y)
	{
		Fx[x].pb(y);
		Fx[y].pb(x);
	}
	ll getLoger(ll x)
	{
		vis.assign(Fx.size() , 0);
		vll::iterator it;
		ll aux;
		ll ans;
		queue<ll> cola;
		cola.push(x);
		vis[x] = 1;
		while(!cola.empty())
		{
			aux = cola.front();
			cola.pop();
			ans = aux;
			for(it = Fx[aux].begin() ; it != Fx[aux].end() ; it++)
			{
				if(vis[*it])
					continue;
				cola.push(*it);
				vis[*it] = 1;
			}
		}
		return ans;
	}
	ll Distance(ll x , ll p , ll y)
	{
		vll::iterator it;
		ll ans = 0;
		for(it = Fx[x].begin() ; it != Fx[x].end() ; it++)
		{
			if(*it == p)
				continue;
			ans = max(ans,Distance(*it,x,y+1)+1);
		}
		dist[x] = max(dist[x],max(y,ans));
		return ans;
	}
	void MakeDistances()
	{
		ll a = getLoger(0);
		ll b = getLoger(a);
		Distance(a,-1,0);
		Distance(b,-1,0);
	}

};



int main()
{_C
	ll n , q , a , b;
	while(cin >> n >> q)
	{
		Grafo g1(n);
		Grafo g2(q);
		for(int i = 1 ; i < n ; i++)
		{
			cin >> a >> b;
			g1.join(a-1,b-1);
		}
		for(int i = 1 ; i < q ; i++)
		{
			cin >> a >> b;
			g2.join(a-1,b-1);
		}
		ll x , y , ans = 0 , maxi;
		g1.MakeDistances();
		g2.MakeDistances();
		vll v(q);
		sort(g1.dist.begin() , g1.dist.end());
		sort(g2.dist.begin() , g2.dist.end());
		v[0] = g2.dist[0];
		for(int i = 1 ; i < q ; i++)
				v[i] = g2.dist[i]+v[i-1];
		y = v[q-1];
		maxi = max(g1.dist[n-1] , g2.dist[q-1]);
		for(int i = 0 ; i < n ; i++)
		{
			x = (lower_bound(g2.dist.begin() , g2.dist.end() , maxi - g1.dist[i] - 1) - g2.dist.begin());
			if(x == 0)
				ans += q*(g1.dist[i]+1)+y;
			else
			ans += y-v[x-1]+(q-x)*(g1.dist[i]+1)+x*maxi;
		}
		cout << fixed << setprecision(3) << ((ld)ans)/((ld)(n*q)) << '\n';
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}