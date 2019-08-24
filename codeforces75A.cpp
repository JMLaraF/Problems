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
	string a , aa = "" , b , bb = "" , c , cc = "";
	ll x , y , z;
	cin >> x >> y;
	c = to_string(x+y);
	a = to_string(x);
	b = to_string(y);
	for(int i = 0 ; i < a.size() ; i++)
		if(a[i] != '0')
			aa += a[i];
	for(int i = 0 ; i < b.size() ; i++)
		if(b[i] != '0')
			bb += b[i];
	for(int i = 0 ; i < c.size() ; i++)
		if(c[i] != '0')
			cc += c[i];
	stringstream ss(aa);
	ss >> x;
	ss.clear();
	ss.str(bb);
	ss >> y;
	ss.clear();
	ss.str(cc);
	ss >> z;
	if(x+y == z)
		cout << "YES\n";
	else
		cout << "NO\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}