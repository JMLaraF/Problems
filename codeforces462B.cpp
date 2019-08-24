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
	ll n , k , c = 0;
	char s;
	cin >> n >> k;
	vll v(26);
	forn
	{
		cin >> s;
		v[s-'A']++;
	}
	sort(v.begin() , v.end());
	ll i = 25;
	while(k > 0)
	{
		c += min(k,v[i])*min(k,v[i]);
		k -= min(k,v[i]);
		i--;
	}
	cout << c << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}