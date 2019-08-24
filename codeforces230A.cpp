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

bool st(const pll &p1 , const pll &p2) { return ((p1.xx < p2.xx) || (p1.xx == p2.xx && p1.yy > p2.yy));}

int main()
{_C
	ll k , n;
	cin >> k >> n;
	vpll v(n);
	For(o,n)
		cin >> v[i].xx >> v[i].yy;
	sort(v.begin() , v.end() , st);
	For(o,n)
	{
		if(k <= v[i].xx)
		{
			cout << "NO\n";
			return 0;
		}else
			k += v[i].yy;
	}
	cout << "YES\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}