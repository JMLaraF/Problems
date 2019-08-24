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
	ll n , a , b , ds = 10000000;
	cin >> n;
	vector<ll> v(n);
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	for(int i = 0 ; i < n ; i++)
	{
		if(abs(v[i]-v[(i+1)%n]) < ds)
		{
			a = i;
			b = (i+1)%n;
			ds = min(abs(v[i]-v[(i+1)%n]) , ds);
		}
	}
	cout << a+1 << ' ' << b+1 << '\n';
	
	return 0;
}