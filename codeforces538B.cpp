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
	string s;
	cin >> s;
	char x = '0';
	vector<string> v(9);
	ll mx = 0;
	for(int j = 0 ; j < s.size() ; j++)
	{
		x = '0';
		for(int i = 0 ; i < 9 ; i++)
		{
			if(s[j] > x)
			{
				x++;
				if(x - '0' > mx)
					mx = x - '0';
				v[i] += '1';
			}else
			{
				v[i] += '0';
			}
		}
	}
	cout << mx << '\n';
	for(int i = 0 ; i < 9 ; i++)
	{
		ll x = atoi(v[i].c_str());
		if(x != 0)
			cout << x << ((i == 8)?'\n':' ');
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}