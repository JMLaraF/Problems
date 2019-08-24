#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

struct nodo
{
	ll n , p , c;
	nodo()
	{
		n = 0;
		p = 0;
		c = 0;
	}
	nodo(ll z)
	{
		if(z > 0)
		{
			n = 0;
			p = 1;
			c = 0;
		}else if(z < 0)
		{
			n = 1;
			p = 0;
			c = 0;
		}else
		{
			n = 0;
			p = 0;
			c = 1;
		}
	}
};

nodo operator + (const nodo &n1 , const nodo &n2)
{
	nodo nx;
	nx.p = n1.p + n2.p;
	nx.n = n1.n + n2.n;
	nx.c = n1.c + n2.c;
	return nx;
}


nodo ST[300000];


void update(ll v , ll l , ll r , ll x , ll val)
{
	if(x < l || x >= r)
		return;
	if((r - l ) == 1)
	{
		ST[v] = nodo(val);
	//	cout << "X = " << x << " , " << v << " , " << ST[v].p << " , " << ST[v].n << " , " << ST[v].c << '\n';
		return;
	}else
	{
		int m = (l+r)/2;
		update(2*v,l,m,x,val);
		update(2*v+1,m,r,x,val);
		ST[v] = ST[2*v]+ST[2*v+1];
	//	cout << "D " << v << " , " << ST[v].p << " , " << ST[v].n << " , " << ST[v].c << '\n';
		return;
	}
}
nodo query(ll v , ll l , ll r , ll i , ll j)
{
		if(j < l || i >= r)
			return nodo();
		else if(i <= l && r-1 <= j)
		{
			return ST[v];
		}else
		{
			ll m = (l+r)/2;
			nodo c1 = query(2*v , l , m , i , j);
			nodo c2 = query(2*v+1 , m , r , i , j);
			return (c1 + c2);
		}
}

int main()
{_C
	ll n , k , a , b;
	char c;
	nodo aux;
	while(cin >> n >> k)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> a;
			update(1,1,n+1,i,a);
		}
		while(k--)
		{
			cin >> c >> a >> b;
			if(c == 'P')
			{
				aux = query(1,1,n+1,a,b);
		//		cout << aux.c << " , " << aux.n << " , " << aux.p << '\n';
				if(aux.c > 0)
					cout << "0";
				else if(aux.n%2 != 0)
					cout << '-';
				else
					cout << '+';
			}
			else
				update(1,1,n+1,a,b);
		}
		cout << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}