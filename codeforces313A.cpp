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
	string s;
	cin >> n;
	s = to_string(n);
	if(n >= 0)
		cout << n << '\n';
	else
	{
		if(s[s.size()-1] > s[s.size()-2])
			s = s.substr(0,s.size()-1);
		else
			s = s.substr(0,s.size()-2)+s.substr(s.size()-1,1);
		cout << atoi(s.c_str()) << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}