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
	string s  , ans = "";
	cin >> s;
	forn
	{
		switch(s[i])
		{
			case '2':
				ans += "2";
			break;
			case '3':
				ans += "3";
			break;
			case '4':
				ans += "322";
			break;
			case '5':
				ans += "5";
			break;
			case '6':
				ans += "53";
			break;
			case '7':
				ans += "7";
			break;
			case '8':
				ans += "7222";
			break;
			case '9':
				ans += "7332";
			break;
		}
	}
	sort(ans.rbegin() , ans.rend());
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}