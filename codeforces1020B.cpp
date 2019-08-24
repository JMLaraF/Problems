#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

struct grafo
{
	vector<vll> aristas;
	vll visitado;
	grafo(ll n)
	{
		aristas.assign(n,vll());
		visitado.assign(n,0);
	}
	void conect(ll x , ll y)
	{
		aristas[x].push_back(y);
	}
	ll DFS(ll x)
	{
		ll aux = 0;
		if(visitado[x])
			return x;
		visitado[x] = 1;
		for(int i = 0 ; i < aristas[x].size() ; i++)
		{
			aux = DFS(aristas[x][i]);
			if(aux)
			{
				visitado[x] = 0;
				return aux;
			}

		}
		visitado[x] = 0;
		return aux;
	}
};

int main()
{_C
	ll n , a , b;
	cin >> n;
	grafo g(n);

	forn
	{
		cin >> a;
		g.conect(i,a-1);
	}
	for(int i = 0 ; i < n ; i++)
	cout << g.DFS(i)+1 << ((i == n-1)?'\n':' ');
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}