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

vll v;
void criba()
{
	vll bs(500005);
	v.pb(2);
	for(ll i = 3 ; i < 500000 ; i+=2)
	{
		if(bs[i] == 0)
			v.pb(i);
		for(ll j = i*i ; j < 500000 ; j += i)
			bs[j] = 1;
	}
}

ll PN(ll a)
{
	if(a == 1)
		return 0;
	ll i = 0 , ans = 0 , y = 0;
	ll x = v[i++];
	while(x*x <= a)
	{
		while(a%x == 0)
		{
			y++;
			a /= x;
		}
		ans ^= y;
		y = 0;
		x = v[i++];
	}
	if(a > 1)
		ans ^= 1;
	return ans;
}

int main()
{_C
	criba();
	ll t , n , a;
	cin >> t;
	while(t--)
	{
		ll b = 0;
		cin >> n;
		forn
		{
			cin >> a;
			a = PN(a);
			b ^= a;
		}
		if(b)
			cout << "Poo\n";
		else
			cout << "Mak\n";
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}