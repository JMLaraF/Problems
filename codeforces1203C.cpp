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

ll divs(ll a)
{
	ll x = 2 , ans = 1 , p = 0;
	while(x*x <= a)
	{
		while(a%x == 0)
		{
			p++;
			a /= x;
		}
		if(p)
			ans *= p+1;
		x++;
		p = 0;
	}
	if(a != 1)
		ans *= 2;
	return ans;
}


int main()
{_C
	ll n , a , b;
	cin >> n >> a;
	for(int i = 1 ; i < n; i++)
	{
		cin >> b;
		a = __gcd(a,b);
	}
	cout << divs(a) << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}