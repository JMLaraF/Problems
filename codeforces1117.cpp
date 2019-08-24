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
	ll n , m , k , c = 0;
	cin > n >> m >> k;
	vll v(n);
	forn
		cin >> v[i];
	sort(v.begin(),v.end());
	c = v[n-1]*(m/(k+1))*k+v[n-1]*(m/(k+1));
	m %= (k+1);
	if(m > 0)
		c += v[n-1]*m;
	cout << c;
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}