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
	ll n , x , y, z , a , b, c , d = 0;
	cin >> n;
	while(n--)
	{
		cin >> x >> y;
		a = x + (y-1);
		c = 0;
		b = 0;
		x--;
		z = x%4;
		if(z == 0)
			c ^= x;
		else if(z == 1)
			c ^= 1;
		else if(z == 2)
			c ^= x+1;

		x += y;
		z = x%4;
		
		if(z == 0)
			b ^= x;
		else if(z == 1)
			b ^= 1;
		else if(z == 2)
			b ^= (x+1);
		d ^= (c^b);
	}
	if(d)
		cout << "tolik\n";
	else
		cout << "bolik\n";

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}