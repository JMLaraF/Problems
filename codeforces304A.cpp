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

	ll n,c = 0;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = i ; j <= n ; j++)
		{
			if((i*i+j*j)<=(n*n) && fabs(sqrt((ld)(i*i+j*j))-floor(sqrt((ld)(i*i+j*j))))<ERR)
			{
				c++;
			}
		}
	}
	cout << c << '\n';	
	
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}