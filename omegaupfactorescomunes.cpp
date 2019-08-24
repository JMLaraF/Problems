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

ll GCD(ll a , ll b){return (b == 0)? a:GCD(b , a%b);}

void criba(ll nSize , vll &v)
{
	vector<short> bs(nSize,0);
	v.push_back(2);
	for(ll i = 3; i < nSize; i+=2)
	{
		if(bs[i]==0)
			v.push_back(i);
		for(ll j = i*i; j < nSize; j += i)
			bs[j]=1;
	}
}

int main()
{_C
	ll a , b , c = 2 , d = 1 , p = 0 , z = 0;
	cin >> a >> b;
	ll x = 5;
	x = GCD(a , b);
	
	a /= x;
	b /= x;
	c = 2;
	while(x > 1 && c*c <= x)
	{
		p = 0;
		while(x%c == 0)
		{
			x /= c;
			p++;
		}
		d *= (p+1);
		if(c > 2)
			c += 2;
		else
			c++;	
	}
	if(x > 1)
		d *= 2;
	
	cout << d << '\n';

		#ifdef LOCAL
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
		#endif

	return 0;
}