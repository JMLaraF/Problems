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
	ll n , l , r , z = 1;
	cin >> n >> l >> r;
	ll a = 0 , b = 0;
	for(int i = 0 ; i < l ; i++)
	{
		a += (ll)(1<<i);
		b += (ll)(1<<i);
		z = (ll)(1<<i);
	}
	for(int i = l ; i < r ; i++)
	{
		b += (ll)(1<<i);
		z = (ll)(1<<i);
	}
	cout << a+n-l << ' ' << b+(n-r)*z << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}