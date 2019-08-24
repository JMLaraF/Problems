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
	ll n , a = 0 , b = 0 , c , d;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> c >> d;
		a += c;
		b += d;
	}
	if(a > n/2)
		c = n-a;
	else
		c = a;
	if(b > n/2)
		c += n-b;
	else
		c += b;	
	cout << c << '\n';
	return 0;
}