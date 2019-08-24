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
	ll x , y;
	string s , t;
	cin >> s >> t;
	if(s.size() != t.size())
		cout << "No	\n";
	else
	{
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'i' || s[i] == 'I' || s[i] == 'E' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
				x = 0;
			else
				x = 1;
			if(t[i] == 'a' || t[i] == 'A' || t[i] == 'e' || t[i] == 'E' || t[i] == 'i' || t[i] == 'I' || t[i] == 'o' || t[i] == 'O' || t[i] == 'u' || t[i] == 'U')
				y = 0;
			else
				y = 1;
			if(x != y)
			{
				cout << "No\n";
				return 0;
			}
		}
		cout << "Yes\n";
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}