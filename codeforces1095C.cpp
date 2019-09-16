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

ll div(ll x , vll &ans , ll z)
{
	if(x == 1 )
	{
		ans.pb(x);
		return 1;
	}
	if(z  == 1)
	{
		ans.pb(x);
		ans.pb(x);
		return 2;
	}
	ll y = x/2;
	ll a = div(y,ans,z-1) , b;
	z -= a;
	if(z > 0)
	{
		b = div(y,ans,z-1);
	}
	else
	{
		ans.pb(x);
		b = 1;
	}
	return a+b;
}

int main()
{_C
	ll n , k;
	cin >> n >> k;
	vll v , ans;
	for(int i = 0 ; i < 15 ; i++)
	{
		if(((1LL<<i)&n) != 0)
			v.pb(1LL<<i);
	}
	if(k < v.size())
	{
		cout << "NO\n";
		return 0;
	}
	ll a = 0 , i = 0 , b;
	while(a < k && i < n)
	{
		b = div(v[i],ans,k-a);
		a += b;
		i++;
	}
	if(ans.size() != k)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i = 0 ; i < ans.size() ; i++)
		cout << ans[i] << ((i == ans.size()-1)?'\n':' ');

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}