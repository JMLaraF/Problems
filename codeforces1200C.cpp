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
	ll n , m , q , g;
	ll a , b , x , y;
	cin >> n >> m >> q;
	g = __gcd(n,m);
	n /= g;
	m /= g;
	while(q--)
	{
		ll q = 0;
		cin >> a >> x >> b >> y;
		x--;
		y--;
		if(a == 1)
		{
			if(x >= n)
			{
				q = x/n;
				x %= n;
			}
		}else
		{
			if(x >= m)
			{
				q = x/m;
				x %= m;
			}
		}
		if(b == 1)
		{
			y -= n*q;
			if(y >= 0 && y < n)
				cout << "YES\n";
			else
				cout << "NO\n";
		}else
		{
			y -= m*q;
			if(y >= 0 && y < m)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}