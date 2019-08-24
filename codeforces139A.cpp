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
	ll n;
	vll v(7);
	cin >> n;
	for(int i = 0 ; i < 7 ; i++)
		cin >> v[i];
	int i = 0;
	n -= v[i];
	while(n > 0)
	{
		i = (i+1)%7;
		n -= v[i];
	}
	cout << i+1 << '\n';	

	return 0;
}