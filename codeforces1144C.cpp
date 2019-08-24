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
	ll n;
	map<ll,ll> mp;
	cin >> n;
	vll v(n);
	vll a , b;
	forn
	{
		cin >> v[i];
		mp[v[i]]++;
		if(mp[v[i]] == 1)
			a.push_back(v[i]);
		else if(mp[v[i]] == 2)
			b.push_back(v[i]);
		else if(mp[v[i]] > 2)
		{
			cout << "NO\n";
			return 0;
		}
	}
	sort(a.begin() , a.end());
	sort(b.rbegin() , b.rend());
	cout << "YES\n";
	cout << a.size() << '\n';
	for(int i = 0 ; i < a.size() ; i++)
		cout << a[i] << ((i==a.size()-1)?'\n':' ');
	cout << b.size() << '\n';
	for(int i = 0 ; i < b.size() ; i++)
		cout << b[i] << ((i==b.size()-1)?'\n':' ');
	if(b.size() == 0)
		cout << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}