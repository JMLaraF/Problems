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
	ll n , z;
	cin >> n >> z;
	vll v(n);
	forn
		cin >> v[i];
	sort(v.begin() , v.end());
	ll l = 0 , r = n/2 + 1 , m;
	while(r - l > 1)
	{
		m = (l+r)/2;
		bool f = true;
		for(int i = 0 ; i < m ; i++)
			f &= (v[n-m+i] - v[i] >= z);
		if(f)
			l = m;
		else
			r = m;
	}
	cout << l << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}