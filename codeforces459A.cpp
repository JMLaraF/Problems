#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	ll x1 , x2 , y1 , y2 , x3 = -1 , x4 , y3 , y4;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2)
	{
		x3 = x1+abs(y2-y1);
		x4 = x3;
		y3 = y1;
		y4 = y2;
	}else if(y1 == y2)
	{
		x3 = x1;
		x4 = x2;
		y3 = y1+abs(x2-x1);
		y4 = y3;
	}else
	{
		if(abs(x2-x1) != abs(y2-y1))
		{
			cout << "-1\n";
			return 0;
		}
		x3 = x1;
		y3 = y2;
		x4 = x2;
		y4 = y1;
	}
	
	cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}