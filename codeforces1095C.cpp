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
	ll n , k , a = 0;
	cin >> n >> k;
	vll v , ans;
	for(int i = 0 ; i < 40 ; i++)
	{
		if(((1LL<<i)&n) != 0)
		{
			v.pb(1LL<<i);
			a += (1LL<<i);
		}
	}
	if(k < v.size() || k > a)
	{
		cout << "NO\n";
		return 0;
	}
	ll i = 0;
	a = 0;
	while(v.size()-a < k)
	{
		ll b = v[i];
		if(b == 1)
		{
			ans.pb(1);
			i++;
		}
		else
		{
			a++;
			v.pb(b/2);
			v.pb(b/2);
			i++;
		}
	}
	for(; i < v.size() ; i++)
		ans.pb(v[i]);
	cout << "YES\n";
	for(int z = 0 ; z < ans.size() ; z++)
		cout << ans[z] << ((z == ans.size()-1)?'\n':' ');	

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}