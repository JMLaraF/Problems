#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

ll pot(ll a , ll b , ll c)
{
	if(b == 0)
		return 1;
	ll ans = 1;
	for(int i = 0 ; i < 63 ; i++)
	{
		if((((ll)1<<i)&b)!=0)
			ans = (ans*a)%c;
		a = (a*a)%c;
	}
	return ans;
}

int main()
{_C
	ll n;
	while(cin >> n)
	{
		ll x = 1 , i = 1;
		while(x%n!=0)
		{
			x = (x+pot(10,i,n))%n;
			i++;
		}
		cout << i << '\n'; 
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}