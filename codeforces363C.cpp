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
	ll x;
	string s;
	cin >> s;
	cout << s[0];
	for(int i = 1 ; i < s.size() ; i++)
	{
		if(s[i] == s[i-1])
		{
			x = i;
			if(i < s.size()-2 && s[i+1] != s[i] && s[i+1] == s[i+2])
			{
				cout << s[i+1];
				i += 2;
			}else
			{
				while(s[++i] == s[x]);
				i--;
				cout << s[x];
			}
		}else
		{
			cout << s[i];
		}
	}
	cout << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}