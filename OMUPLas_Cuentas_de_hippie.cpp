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
	ll c , n , a;
	cin >> c >> n;
	vll v(2*n);
	For(o,n)
	{
		cin >> v[i];
		v[n+i] = v[i];
	}
	ll l = 0 , r = 0 , mn = INF;
	a = 0;

	while(r < 2*n)
	{
		if(c > 0)
		{
			if(v[r] == 0)
				c--;
			else
				a++;
			r++;
		}else
		{
			mn = min(mn , a);
			if(v[l] == 0)
				c++;
			else
				a--;
			l++;
		}
	//	cout << l << " , " << r << '\n';
	}
	cout << mn << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}