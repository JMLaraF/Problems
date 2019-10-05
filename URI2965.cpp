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
	vll p;
	vll lv;
	Grafo(ll n)
	{
		Fx.assign(n,vll());
		p.assign(n,0);
		lv.assign(n,-1);
	}
	void join(ll x, ll y)
	{
		Fx[x].pb(y);
		Fx[y].pb(x);
	}	
	ll roted(ll x , ll y)
	{
		ll aux = 0; 
		p[x] = y;
		vll::iterator it;
		for(it = Fx[x].begin() ; it != 	Fx[x].end() ; it++)
		{
			if(*it == y)
				continue;
			aux = max(roted(*it,x)+1,aux);
		}
		lv[x] = aux;
		return aux;
	}
	bool kill(ll x , ll y , priority_queue<pll> &pq , ll k)
	{
		if(k == 0)
			return true;
		bool f = false;
		vll::iterator it;
		ll z = -1;
		for(it = Fx[x].begin() ; it != Fx[x].end() && !f ; it++)
		{
			if(*it == y)
				continue;
			f |= kill(*it , x , pq , k-1);
			if(f)
				z = *it;
		}
		for(it = Fx[x].begin() ; it != Fx[x].end() && f; it++)
		{
			if((*it == y) || (*it == z))
				continue;
			pq.push(pll(lv[*it],*it));
		}
		return f;
	}
	ll ans(ll n)
	{
		priority_queue<pll> cola;
		cola.push(pll(lv[0],0));
		pll aux;
		ll ans = 0;
		while(n > 0 && !cola.empty())
		{
			n--;
			aux = cola.top();
			cola.pop();
			ans += aux.xx+1;
			kill(aux.yy,p[aux.yy],cola,aux.xx);
		}
		return ans;
	}


};

int main()
{_C
	ll n , k , a , b;
	cin >> n >> k;
	Grafo g(n--);
	forn
	{
		cin >> a;
		g.join(a-1,i+1);
	}
	g.roted(0,-1);
	cout << g.ans(k) << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}