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
	ll n , k;
	cin >> n >> k;
	vll v(n);
	For(o,n)
	{
		cin >> v[i];
		if(i > 0)
			v[i] += v[i-1];
	}
	pll mn;
	if(n > 1)
		mn = pll(v[k-1],1);
	else
		mn = pll(v[0],1);
	for(int i = k ; i < n ; i++)
	{
		
		if((v[i]-v[i-k]) < mn.xx)
		{
			mn.xx = (v[i]-v[i-k]);
			mn.yy = i-k+2;
		}
	}
	cout << mn.yy << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}