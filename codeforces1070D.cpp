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
	ll n , k , b , c = 0 , f = 0;
	cin >> n >> k;
	bool a = false;
	forn
	{
		cin >> b;
		c += (b+f)/k;
		if((b+f)/k == 0 && f > 0 && a)
		{
			c++;
			f = 0;
			a = false;
		}else
		{
			a = true;
			if((b+f)%k != 0)
				f = (b+f)%k;
			else
				f = 0;
		}
	}
	if(f > 0)
		c++;
	
	cout << c << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}