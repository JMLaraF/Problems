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
	ll n , m , a , b , c;
	cin >> n;
	vll v(n+1);
	vll vv(n+1);
	For(o,n)
	{
		cin >> v[i+1];
		vv[i+1] = v[i+1];
		if(i>0)
			v[i+1] += v[i];
	}
	sort(vv.begin(),vv.end());
	for(int i = 1 ; i <= n; i++)
		vv[i] += vv[i-1];
	cin >> m;
	while(m--)
	{
		cin >> a >> b >> c;
		if(b > c)
			swap(b,c);
		if(a == 1)
		{
			cout << (v[c]-v[b-1]) << '\n';
		}else
		{
			cout << (vv[c]-vv[b-1]) << '\n';
		}
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}