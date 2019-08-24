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
	ll n , p = 0;
	cin >> n;
	vll v(n);
	bool f = false;
	forn
	{
		cin >> v[i];
		if(v[i] == i)
			p++;
	}
	if(p == n || p == n-2)
		cout << n;
	else
	{
		for(int i = 0 ; i < n ; i++)
			if(v[i] != i && v[v[i]] == i)
				f = true;
		if(f)
			cout << p+2 << '\n';
		else
			cout << p+1 << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}