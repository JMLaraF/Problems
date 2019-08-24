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
{
	ll n , a;
	vector<ll> F;
	F.push_back(1);
	ll ans = 1;
	for(int i = 1 ; i < 41 ; i++)
	{
		ans *= i;
		cout << ans << '\n';
		F.push_back(ans);
	}
	cin >> n;
	while(n--)
	{
		cin >> a;
		cout << F[a] << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}