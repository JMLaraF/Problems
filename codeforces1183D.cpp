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
	ll t , n , a , x;
	cin >> t;
	while(t--)
	{
		ll z = 0;
		cin >> n;
		map<ll,ll> v;
		vector<bool> b(300005,false);
		forn
		{
			cin >> a;
			v[a]++;
		}
		map<ll,ll>::iterator it;
		for(it = v.begin() ; it != v.end() ; it++)
		{
			x = it->yy;
			while(x > 0)
			{
				if(!b[x])
				{
					b[x] = true;
					z += x;
					break;
				}
				x--;
			}
		}
		cout << z << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}