#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ll n , a = 0 , b = 0 , c = 0 , d = 0 , x = 0 , y = 0 , aa , bb , z = 0;
	cin >> n;
	For(o,n)
	{
		cin >> aa >> bb;
		if(aa%2 == 0 && bb%2 != 0)
		{
			x++;
			a++;
			d++;
		}
		else if(aa%2 != 0 && bb%2 == 0)
		{
			y++;
			b++;
			c++;
		}else if(aa%2 == 0 && bb%2 == 0)
		{
			a++;
			c++;
		}else
		{
			b++;
			d++;
		}
	}
	if(b%2 != 0 && x > 0)
	{
		b++;
		a--;
		d--;
		c++;
		z++;
	}
	if(d%2 != 0 && y > 0)
	{
		d++;
		c--;
		b--;
		a++;
		z++;
	}
	if(b%2 == 0 && d%2 == 0)
		cout << z << '\n';
	else
		cout << "-1\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}