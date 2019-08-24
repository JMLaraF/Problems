#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ll t , n , a;
	cin >> t;
	for(int j = 1 ; j <= t ; j++)
	{
		cin >> n;
		n--;
		ll l = 0 , l2 = 0 , r2 = 1 , s = 0 , mx = 0;
		For(o,n)
		{
			cin >> a;
			s += a;
			if(s > mx || (s == mx && (i-l > r2-l2 || (i-l == r2-l2 && l <= l2))))
			{
				l2 = l;
				r2 = i;
				mx = s;
			}
			if(s < 0)
			{
				l = i+1;
				s = 0;
			}
		}
		if(mx > 0)
			cout << "The nicest part of route " << j << " is between stops " << l2+1 << " and " << r2+2 << '\n';
		else
			cout << "Route " << j << " has no nice parts\n";
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}