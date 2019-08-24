#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ll n , k;
	cin >> n >> k;
	if((ld)k > ceil((ld)n/2))
	{
		k -= (ll)ceil(((ld)n/2));
		cout << 2*k << '\n';
	}else
	{
		cout << 2*k-1 << '\n';
	}

	return 0;
}