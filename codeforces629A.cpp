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
	ll n , ans = 0;
	cin >> n;
	vector<string> v(n);
	forn
		cin >> v[i];
	for(int i = 0 ; i < n ; i++)
	{
		ll x = 0;
		for(int j = 0 ; j < n ; j++)
			if(v[i][j] == 'C')
				x++;
		ans += (x*(x-1))/2;
	}
	for(int i = 0 ; i < n ; i++)
	{
		ll x = 0;
		for(int j = 0 ; j < n ; j++)
			if(v[j][i] == 'C')
				x++;
		ans += (x*(x-1))/2;
	}
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}