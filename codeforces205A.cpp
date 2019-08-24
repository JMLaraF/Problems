#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define For(i,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ll n , m = INF , c = 0 , a , p;
	cin >> n;
	For(i,n)
	{
		cin >> a;
		if(a < m)
		{
			m = a;
			c = 0;
			p = i;
		}else if (a == m)
			c++;
	}
	if(c > 0)
		cout << "Still Rozdil\n";
	else
		cout << p+1 << '\n';


	return 0;
}