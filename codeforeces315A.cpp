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
	ll n;
	cin >> n;
	vpll v(n);
	vll z(1005);
	forn
	{
		cin >> v[i].xx >> v[i].yy;
		z[v[i].xx]++;
	}
	for(int i = 0 ; i < v.size() ; i++
	{
		if(v[i].xx != v[i].yy)
		{
			n -= z[v[i].yy];
			z[v[i].yy] = 0;
		}
	}
	cout << n << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}