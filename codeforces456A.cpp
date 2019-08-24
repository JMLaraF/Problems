#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
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
	ll n;
	cin >> n;
	vpll v(n);
	forn
	{
		cin >> v[i].xx >> v[i].yy;
	}
	sort(v.begin() , v.end());
	for(int i = 1 ; i < n; i++)
	{
		if(v[i].yy < v[i-1].yy)
		{
			cout << "Happy Alex\n";
			return 0;
		}
	}
	cout << "Poor Alex\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}