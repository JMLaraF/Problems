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
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	ll n , k , c = 0;
	cin >> n >> k;
	vll v(n);
	forn
		cin >> v[i];
	sort(v.begin(),v.end());
	if(v[n/2] < k)
	{
		for(int i = n/2 ; v[i] < k && i < n ; i++)
		c += k-v[i];
	}else if (v[n/2] > k)
	{
		for(int i = n/2 ; v[i] > k && i >= 0 ; i--)
		c += v[i]-k;
	}
	
	cout << c << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}