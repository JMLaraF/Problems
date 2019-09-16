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
	vector<ld> ans;
	Grafo(ll n)
	{
		ans.assign(n,0.0);
		Fx.assign(n,vll());
	}
	void unir(ll x , ll y)
	{
		Fx[x].pb(y);
		Fx[y].pb(x);
	}
	ld DFS(ll x , ll p)
	{
		bool f = false;
		vll::iterator it;
		for(it = Fx[x].begin() ; it != Fx[x].end() ; it++)
		{
			if(*it == p)
				continue;
			ans[x] += DFS(*it,x);
			f = true;
		}
		if(f)
		{
			if(x == 0)
				ans[x] /= (ld)(Fx[x].size());
			else
				ans[x] /= (ld)(Fx[x].size()-1);
			ans[x] += 1.0;
		}
		return ans[x];
		
	}
};

int main()
{_C
	ll n , a , b;
	cin >> n;
	Grafo g(n--);
	forn
	{
		cin >> a >> b;
		g.unir(a-1,b-1);
	}
	cout << fixed << setprecision(7) << g.DFS(0,-1) << '\n'; 


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}