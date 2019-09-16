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
	ll q;
	cin >> q;
	while(q--)
	{
		ll n , k , x , y , ans = 0;
		cin >> n >> k;
		vll v(11);
		x = k%10;
		for(int i = 1 ; i < 11 ; i++)
		{
			v[i] = v[i-1]+x;
			x = (x+k)%10;
		}
		y = n/k;
		ans += v[y%10] + v[10]*(y/10);
		cout << ans << '\n';
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}