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
	ll a , b , c , x , y , z , ans = 0 , t , w;
	cin >> a >> b >> c;
	t = min(a/3 , min( b/3 , c/3));
	ans += 3*t;
	x = a-t*3;
	y = b-t*3;
	z = c-t*3;
	w = min(x , min(y,z));
	ans += w;
	x -= w;
	y -= w;
	z -= w;
	ans += x/3 + y/3 + z/3;
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}