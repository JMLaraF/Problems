#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
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
	ll n , a = 0 , b = 0 , c = 0 , x;
	cin >> n;
	forn
	{
		cin >> x;
		if(x == 25)
			a++;
		if(x == 50)
			b++;
		if(x == 100)
			c++;
		if((x -= 25) > 0)
		{
			if(x == 75)
			{
				if(b > 0 && a > 0)
				{
					b--;
					a--;
					continue;
				}
				else if(b <= 0 && a > 2)
				{
					a -= 3;
					continue;
				}
				else
				{
					cout << "NO\n";
					return 0;
				}
			}
			if(x == 25 && a > 0)
			{
				a--;
				continue;
			}else
			{
				cout << "NO\n";
				return 0;
			}

		}
	}
	cout << "YES\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}