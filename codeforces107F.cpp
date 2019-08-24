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


int main()
{_C
	ll n , b , c = 0 , d = 0, e;
	string a;
	cin >> n;
	vll x,y,z;
	forn
	{
		cin >> a >> b;
		if(a == "11")
		{
				c += b;
				d++;						
		}else if(a == "00")
			x.push_back(b);
		else if(a == "10")
			y.push_back(b);
		else
			z.push_back(b);
	}
	sort(y.begin() , y.end(),greater<ll>());
	sort(z.begin() , z.end(),greater<ll>());
	for(int i = 0 ; i < min(y.size(),z.size()) ; i++)
		c += z[i]+y[i];
	e = min(y.size(),z.size());
	for(e ; e < max(y.size(),z.size()) ; e++)
	{	
		if(e < y.size())
			x.push_back(y[e]);
		if(e < z.size())
			x.push_back(z[e]);
	}
	sort(x.begin() , x.end(),greater<ll>());
	
	for(int i = 0 ; i < d && i < x.size() ; i++)
		c += x[i];

	cout << c << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}