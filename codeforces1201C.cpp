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
	ll n , k , x , ans;
	cin >> n >> k;
	vll v(n);
	forn
		cin >> v[i];
	sort(v.begin() , v.end());
	ll l , r , m;
	l = v[n/2];
	r = 3000000000;
	while(l < r)
	{
		m = (l+r)/2;
		x = 0;
		for(int i = n/2 ; i < n ; i++)
			x += max(0LL,m-v[i]);
		if(x <= k)
		{
			ans = m;
			l = m+1;
		}
		else
			r = m;
	}
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}