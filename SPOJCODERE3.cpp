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
	ll t , n , mx;
	cin >> t;
	while(t--)
	{
		mx = 0;
		cin >> n;
		vpll v(n);
		vpll b(n);
		forn
		{
			cin >> v[i].xx;
			b[i].xx = v[i].xx;
		}
		forn
		{
			v[i].yy = 1;
			b[n-i-1].yy = 1;
			for(int j = i ; j >= 0 ; j--)
			{
				if(v[j].xx < v[i].xx)
					v[i].yy = max(v[i].yy,v[j].yy+1);
				if(b[n-j-1].xx < b[n-i-1].xx)
					b[n-i-1].yy = max(b[n-i-1].yy,b[n-j-1].yy+1);
			}
		}
		forn
			mx = max(mx,v[i].yy+b[i].yy-1);
		cout << mx << '\n';

	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}