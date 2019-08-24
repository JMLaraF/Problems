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
	ll n , k , x , y = 0 , z = 0;
	vll::iterator xx;
	cin >> n >> k;
	vll v(n);
	for(int i = n-1 ; i >= 0 ; i--)
		cin >> v[i];
	for(int i = 1 ; i < n ; i++)
		v[i] += v[i-1];
	if(n == 1)
	{
		if(v[0] > k)
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
		return 0;
	}
	for(ll i = 0 ; i < n ; i++)
	{
		xx = lower_bound(v.begin() , v.end() , k+y) ;
		if(xx != v.end())
		{
			x = xx-v.begin();
		}else
		{
			x = n-1;
		}
		if(v[x] > k+y)
			x--;
		z = max(z,x-i+1);
		y = v[i];
	}
	cout << z << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}