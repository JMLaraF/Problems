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



int main()
{_C
	ll n , x , y , z , b, c , d, g[4];
	cin >> n;
	vvll v(n,vll(n));
	forn
	{
		for(int j = 0 ; j < n ; j++)
		{
			cin >> v[i][j];
		}
	}
	x = v[n-1][n-2];
	y = v[n-2][n-3];
	z = v[n-1][n-3];
	if(x == y)
	{
		b = round(sqrt(z));
		d = b;
		c = y/b;
	}else if(y == z)
	{
		c = round(sqrt(x));
		d = c;
		b = z/d;
	}else if(z == x)
	{
		c = round(sqrt(y));
		b = c;
		d = x/c;
	}else
	{
		g[0] = __gcd(x,y);
		g[1] = __gcd(y,z);
		g[2] = __gcd(z,x);
		g[3] = __gcd(g[0],g[1]);
		g[3] = __gcd(g[3],g[2]);
		if(g[0]*g[1] == y)
		{
			c = g[0];
			b = g[1];
			d = x/c;
		}else if(g[0]*g[2] == x)
		{
			c = g[0];
			d = g[2];
			b = z/d;
		}else if(g[1]*g[2] == z)
		{
			b = g[1];
			d = g[2];
			c = x/d;
		}else
		{
			b = g[1]/g[3];
			c = g[0]/g[3];
			d = g[2]/g[3];	
		}	
	}
	for(int i = 0 ; i < n-1 ; i++)
		cout << v[n-1][i]/d << ' ';
	cout << d << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}