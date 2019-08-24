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
	ll n = (ll)ceil((double)s.size()/2.0);
	ll unos = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == '1')
			unos++;
	}
	if(unos == 0)
	{
		cout << "0\n";
	}else if(unos == 1)
	{
		if(s.size()%2 == 0)
		{
			cout << n << '\n';
		}else
		{
			cout << n-1 << '\n';
		}
	}else
	{
		cout << n << '\n';
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}

