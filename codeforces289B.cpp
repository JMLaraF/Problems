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
	ll n , m , d , f = -1 , c = 0;
	cin >> n >> m >> d;
	n *= m;
	vll v(n);
	forn
	{
		cin >> v[i];
			if(f == -1)
				f = v[i]%d;
			else if(v[i]%d != f)
			{
				cout << "-1\n";
				return 0;
			}
	}
	sort(v.begin() , v.end());
	for(int i = 0 ; i < n ; i++)
	{
		c += abs(v[i]-v[(ll)(n/2)]);
	}
	cout << c/d << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}