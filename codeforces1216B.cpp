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
	ll n , ans = 0 , x = 0;
	cin >> n;
	vpll v(n);
	forn
	{
		cin >> v[i].xx;
		v[i].yy = i+1;
	}
	sort(v.begin() , v.end());
	for(int i = n-1 ; i >= 0 ; i--)
	{
		ans += v[i].xx * x + 1;
		++x;
	}
	cout << ans << '\n';
	for(int i = n-1 ; i >= 0 ; i--)
		cout << v[i].yy << ((i == 0)?'\n':' ');

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}