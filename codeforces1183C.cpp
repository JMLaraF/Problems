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
	ll t , k , n , a , b , l , r , m , x , z;
	cin >> t;
	while(t--)
	{
		cin >> k >> n >> a >> b;
		k--;
		l = 0 ;
		r = k/a;
		z = -1; 
		for(int i = 0 ; i < 40 ; i++)
		{
			m = (l+r)/2;
			x = (k-(m*a))/b;
			if(x+m >= n)
			{
				z = m;
				l = m+1;
			}else
			{
				r = m;
			}
		}
		cout << min(z,n) << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}