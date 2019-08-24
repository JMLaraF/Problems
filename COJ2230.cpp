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
	ll n;
	cin >> n;
	vll v1(n);
	vll v2(n);
	For(o,n)
		cin >> v1[i];
	For(o,n)
		cin >> v2[i];		
	sort(v1.begin() , v1.end());
	sort(v2.begin() , v2.end());
	ll mn = (ll)1<<62;
	ll ds;
//	do
//	{
//		do
//		{
			ds = 0;
			For(o,n)
				ds += v1[i]*v2[n-1-i];
			mn = min(mn , ds);
			ds = 0;
			For(o,n)
				ds += v1[n-1-i]*v2[i];
			mn = min(mn , ds);
//		}while(next_permutation(v2.begin() , v2.end()));
//	}while(next_permutation(v1.begin() , v1.end()));
	cout << mn << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}