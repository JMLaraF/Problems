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

vll criba()
{
	vll ans = {2};
	bitset<100005> bs;
	for(ll i = 3 ; i < 100005 ; i += 2)
	{
		if(bs[i] == 0)
			ans.pb(i);
		for(ll j = i*i ; j < 100005 ; j += i)
			bs[j] = 1;
	}
	return ans;
}

int main()
{_C
	vll primos = criba();
	ll n , m , a , x;
	vll::iterator up;
	cin >> n >> m;
	vvll v(n,vll(m));
	forn
	{
		for(int j = 0 ; j < m ; j++)
		{
			cin >> a;
			up = lower_bound(primos.begin() , primos.end() , a);
			v[i][j] = *up-a;
		}	
	}
	ll ans = INF;
	forn
	{
		x = 0;
		for(int j = 0 ; j < m ; j++)
		{
			x += v[i][j];
		}
		ans = min(ans,x);
	}
	for(int j = 0 ; j < m ; j++)
	{
		x = 0;
		forn
		{
			x += v[i][j];
		}
		ans = min(ans,x);
	}
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}