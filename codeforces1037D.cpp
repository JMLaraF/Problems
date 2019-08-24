#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
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

struct nodo
{
	bool visit;
	set<ll> Fx;
	nodo()
	{
		visit = false;
	}	
};


class graph
{
	private:
		vector<nodo> v;
	public:
		graph(ll n)
		{
			v.assign(n,nodo());
		}
		void conect(ll x , ll y)
		{
			v[x].Fx.insert(y);
			v[y].Fx.insert(x);
		}
		bool BFS(vll &arr)
		{
			ll aux , visit = 0 , p = 1;
			queue<ll> cola;
			cola.push(arr[0]);
			if(arr[0] != 0)
				return false;
			while(!cola.empty())
			{
				visit++;
				aux = cola.front();
				cola.pop();
				while(p < arr.size() && v[aux].Fx.count(arr[p]))
				{
					cola.push(arr[p]);
					p++;
				}
			}
			if(visit != v.size() || p < arr.size())
				return false;
			return true;
		}
};



int main()
{_C
	ll n , a , b;
	cin >> n;
	graph gp(n);
	vll z(n);
	for(int i = 1 ; i < n ; i++)
	{
		cin >> a >> b;
		gp.conect(a-1,b-1);
	}
	forn
	{
		cin >> z[i];
		z[i]--;
	}
	cout << ((gp.BFS(z))?"YES":"NO") << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}