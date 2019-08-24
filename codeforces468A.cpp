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
	ll n;
	cin >> n;
	if(n < 4)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		if(n % 2 != 0)
		{
			cout << "4 * 5 = 20\n2 + 3 = 5\n20 + 5 = 25\n25 - 1 = 24\n";
			for(int i = 6 ; i < n ; i+= 2)
				cout << i+1 << " - " << i << " = 1\n24 * 1 = 24\n";
		}else
		{
			cout << "4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24\n";
			for(int i = 5 ; i < n ; i+= 2)
				cout << i+1 << " - " << i << " = 1\n24 * 1 = 24\n";
		}
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}