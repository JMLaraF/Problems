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
	ll n , k , ans = 0;
	cin >> n >> k;
	vll v(n);
	forn
		cin >> v[i];
	sort(v.begin() , v.end());
	ll i = 0;
	while(i < v.size() && v[i] < 0 && k > 0)
	{
		k--;
		ans += abs(v[i++]);
	}
	if(i == v.size() && k > 0)
	{
		if(k%2!=0)
			ans += 2*v[i-1]; 
		k = 0;
	}
	ll mn = min(abs(v[i-1]),v[i]);
	if(k%2!=0)
	{
		ans -= 2*abs(mn);
	}
	for(; i < v.size() ; i++)
		ans += v[i];

	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}