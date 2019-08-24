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
	ll n , a , par = 0 , imp = 0 , ans = 0;
	cin >> n;
	vll v(n);
	forn
	{
		cin >> a;
		if(a%2==0)
			par++;
		else
			imp++;
		v[i] = a;
	}
	sort(v.begin() , v.end());
	ll k = max(par,imp)-min(par,imp)-1;
	ll j = 0;
	if(par > imp)
	{
		for(int i = 0 ; i < n , j < k ; i++)
		{
			if(v[i]%2==0)
			{
				j++;
				ans += v[i];
			}
		}
	}else if(imp > par)
	{
		for(int i = 0 ; i < n , j < k ; i++)
		{
			if(v[i]%2!=0)
			{
				j++;
				ans += v[i];
			}
		}
	}
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}