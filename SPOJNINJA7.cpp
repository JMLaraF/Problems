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
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	ll t;
	cin >> t;
	while(t--)
	{
		ll n , s = 0 , a;
		cin >> n;
		vll v(n);
		forn
			cin >> v[i];
		forn
		{
			cin >> a;
			v[i] -= a;
			s += v[i];
		}
		sort(v.begin(),v.end());
		ll i = 0;
		while(s < 0)
		{
			s -= v[i++];
		}
		cout << v.size()-i << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}