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
	ll r , g , b , x , y = 0 , z = 0;
	cin >> r >> g >> b;
	x = (r/3)+(g/3)+(b/3);
	if(r && g && b)
	{
		--r;
		--g;
		--b;
		y = (r/3)+(g/3)+(b/3)+1;
		if(r && g && b)
		{
			--r;
			--g;
			--b;
			z = (r/3)+(g/3)+(b/3)+2;
		}
	}
	cout << max(x,max(y,z)) << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}