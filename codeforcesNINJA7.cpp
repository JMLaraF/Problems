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
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	ll t , n , c = 0 , mx;
	cin >> t;
	while(t--)
	{
		c = 0;
		mx = 0;
		cin >> n;
		vll a(n);
		vll b(n);
		forn
			cin >> a[i]; 
		forn
			cin >> b[i];
		forn
		{
			if(a[i] >= b[i])
				c++;
			else
			{
				mx = max(c,mx);
				c = 0;
			}
		}
		cout << max(c,mx) << '\n';
	}	
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}