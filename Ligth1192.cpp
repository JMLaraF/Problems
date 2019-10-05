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
	ll t , n;
	cin >> t;
	for(int i = 1 ; i <= t ; i++)
	{
		ll a , b , c = 0;
		cin >> n;
		forn
		{
			cin >> a >> b;
			b = b-1-a;
			c ^= b;
		}
		cout << "Case " << i << ": ";
		if(c)
			cout << "Alice\n";
		else
			cout << "Bob\n";
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}