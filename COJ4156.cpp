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
	ll n;
	string s;
	cin >> n >> s;
	vll v(n);
	for(int i = 0 ; i < s.size() ; i+=2)
	{
		if(s[i] == 'A' || s[i] == 'C')
			v[i/2] = 1;
		else
			v[i/2] = 0;
	}
	if(n%2!=0)
		cout << n-1 << '\n';
	else
	{
		bool f = true;
		for(int i = 0 ; i < n ; i += 2)
				f &= (v[i] == 1 && v[i+1] == 0);
		if(f)
			cout << n << '\n';
		else
			cout << n-1 << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}