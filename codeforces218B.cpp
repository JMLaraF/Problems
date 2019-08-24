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
	cin >> m >> n;
	vll v(n);
	For(o,n)
	{
		cin >> v[i];
	}
	vll v2 = v;
	ll mx = 0 , j = 0 , a = 0 , b = 0;
	ll z = m;
	while(m--)
	{
		for(int i = 0 ; i < n ; i++)
			if(mx < v2[i])
			{
				j = i;
				mx = v2[i];
			}
		a += mx;
		v2[j]--;
		mx = 0;
	}

	mx = (ll)1<<62 , j = 0;
	v2 = v;
	while(z--)
	{
		for(int i = 0 ; i < n ; i++)
			if(mx > v2[i] && v2[i] > 0)
			{
				j = i;
				mx = v2[i];
			}
		b += mx;
		v2[j]--;
		mx = (ll)1<<62;
	}
	cout << a << ' ' << b << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}