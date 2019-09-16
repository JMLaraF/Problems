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

void nextLucky(vll &v , string n)
{
	if(n.size() == 10)
		return;
	if(!n.empty())
		v.pb(atoi(n.c_str()));
	nextLucky(v,n+"4");
	nextLucky(v,n+"7");
	return;
}


int main()
{_C
	ll s;
	vll v;
	cin >> s;
	nextLucky(v,"");
	sort(v.begin() , v.end());
	for(int i = 0 ; i < v.size() ; i++)
	{
		if(v[i] == s)
		{
			cout << i+1 << '\n';
			return 0;
		}
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}