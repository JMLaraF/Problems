#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ll n , m;
	cin >> n >> m;
	vll v(m);
	for(int i = 0 ; i < m ; i++)
		cin >> v[i];
	sort(v.begin() , v.end());
	ll r1 = v[n-1] - v[0];
	for(int i = n ; i < m ; i++)
	{

		r1 = min(r1 , v[i] - v[i-n+1]);
	}
	cout << r1 << '\n';		
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}