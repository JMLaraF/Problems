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

int main()
{_C
	ll n , mx = 0 , a;
	ll z = 0 , c = 0;
	ll cero = 0;
	cin >> n;
	For(o,n)
	{
		cin >> a;
		cero += (a == 0)? 1 : 0;
		z += a;
		if(z == 45)
		{
			z = 0;
			c++;
		}
	}
	if(cero < 1)
	{
		cout << "-1\n";
		return 0;
	}
	if(c > 0)
	{
		for(int i = 0 ; i < c ; i++)
			cout << "555555555";
		for(int i = 0 ; i < cero ; i++)
			cout << "0";
		cout << "\n";
	}else
		cout << "0\n";

	return 0;
}