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
	set<ll> ANG;
	for(int i = 3 ; i < 1000 ; i++)
	{
		if(180.0*(i-2)/i == floor(180.0*(i-2)/i))
		{
			ANG.insert(180*(i-2)/i);
		}
	}
	ll q , a;
	cin >> q;
	while(q--)
	{
		cin >> a;
		cout << ((ANG.count(a))?"YES\n":"NO\n");
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}