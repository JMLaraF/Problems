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
	cin >> n;
	if(n%2 == 1)
		cout << "-1\n";
	else
	{
		vll v(n);
		for(int i = 0 ; i < n ; i += 2)
		{
			cout << i+2 << ' ' << i+1 << ((i+2 == n)?'\n':' ');
		}
	}
	return 0;
}