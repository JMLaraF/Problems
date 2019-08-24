#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
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
	ll n , x , y , a , b;
	cin >> n;
	vll v(n);
	forn
	{
		cin >> v[i];
	}
	for(int i = 1 ; i < n ; i++)
	{
		x = min(v[i] , v[i-1]);
		y = max(v[i] , v[i-1]);
		for(int j = i+2 ; j < n ; j++)
		{
			a = min(v[j] , v[j-1]);
			b = max(v[j] , v[j-1]);
			if((a >= x && a <= y && b >= y) || (a <= x && b >= x && b <= y))
			{
				cout << "yes\n";
				return 0;
			}
		}
	}
	cout << "no\n";

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}