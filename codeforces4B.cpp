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
	ll n , t , m = 0 , d = 0;
	cin >> n >> t;
	vpll v(n);
	forn
	{
		cin >> v[i].xx >> v[i].yy;
		m += v[i].xx;
		d += v[i].yy; 
	}
	if(m > t || d < t)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for(int i = 0 ; i < n ; i++)
		{
			if(m < t)
			{
				ll x = min(t-m,v[i].yy-v[i].xx);
				m += x;
				cout << v[i].xx+x << ((i == n-1)?'\n':' ');
			}else
				cout << v[i].xx << ((i == n-1)?'\n':' ');
		}
	}


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}