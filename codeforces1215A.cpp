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
	ll a , b , x , y , k , ans = 0 , mn = 0;
	cin >> a >> b >> x >> y >> k;
	if(x > y)
	{
		swap(a,b);
		swap(x,y);
	}
	ll c = min(a,(k/x));
	ans += c;
	ll kk = k-c*x;
	if(kk > 0)
		ans += min(b,kk/y);
	x--;
	y--;
	ll z = x*a+y*b;
	mn = max(0LL,k-z);
	mn = min(mn,a+b);
	cout << mn << ' ' << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}