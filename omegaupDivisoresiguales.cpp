#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

void criba(ll nsize ,vector<int> &bs)
{
	for(ll i = 2; i < nsize; i++)
	{
		for(ll j = i; j < nsize; j += i)
			bs[j]++;
	}
}

int main()
{_C
	vector<int> v(1500000,1);
	criba(1500000 , v);
	ll n , a;
	cin >> n;
	a = v[n];
	ll i = 1 , j = 1;
	while(!(v[n-i] == a || v[n+j] == a))
	{
		if(n-i > 0)
			i++;
		if(n+j < v.size())
			j++;

	}
	if((v[n-i] == a && v[n+j] == a) || (v[n-i] != a && v[n+j] == a))
		cout << n+j << '\n';
	else if(v[n-i] == a && v[n+j] != a)
		cout << n-i << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}