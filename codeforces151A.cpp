#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ll n , k , l , c , d , p , nl , np;
	ll z;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	l *= k;
	c *= d;
	z = min((ll)(l/nl) , (ll)(p/np));
	z = min(z , c);
	cout << z/n << '\n';

	return 0;
}