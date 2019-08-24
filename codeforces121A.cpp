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

vll v;

void funcion(string s)
{
	if(s.size() > 9)
		return;
	string a = s+"4" , b = s+"7";
	stringstream ss(a);
	ll x;
	ss >> x;
	v.push_back(x);
	ss.clear();
	ss.str(b);
	ss >> x;
	v.push_back(x);
	funcion(a);
	funcion(b);

}

int main()
{_C
	funcion("");
	sort(v.begin() , v.end());
	ll i = 0 , ans = 0;
	ll l , r , x;
	cin >> l >> r;
	while(v[i] <= r)
	{
		if(v[i] < l)
			i++;
		else
		{
			ans += (v[i]-l+1)*v[i];
			l = v[i]+1;
			i++;
		}
	}
	if(i < v.size())
		ans += (r-l+1)*v[i];
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}