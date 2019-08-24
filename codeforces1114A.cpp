#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
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
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	ll x, y , z , a , b , c , w;
	cin >> x >> y >> z >> a >> b >> c;
	if(x <= a)
		a -= x;
	else
	{
		cout << "NO\n";
		return 0;
	}
	if(y <= a + b)
	{
		w = y;
		y -= min(w,b);
		b -= min(w,b);
		a -= y;
	}else
	{
		cout << "NO\n";
		return 0;
	}
	if(a+b+c >= z)
		cout << "YES\n";

	else
	{
		cout << "NO\n";
		return 0;
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}