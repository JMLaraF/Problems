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
	ll n , a , b , c , d = 0;
	cin >> n;
	while(n--)
	{
		cin >> a >> b >> c;
		d += (a+b+c > 1)? 1:0;
	}
	cout << d << '\n';

	return 0;
}