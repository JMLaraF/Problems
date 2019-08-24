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
	ll t , a , b , c , d , n = 0 , s = 0 , e = 0 , o = 0;
	cin >> t >> a >> b >> c >> d;
	a = c-a;
	b = d-b;
	if(a > 0)
		e = a;
	else
		o = abs(a);
	if(b > 0)
		n = b;
	else
		s = abs(b);
	string ss;
	cin >> ss;
	
	for(int i = 0 ; i < ss.size() ; i++)
	{
		switch(ss[i])
		{
			case 'N':
				n--;
			break;
			case 'S':
				s--;
			break;
			case 'E':
				e--;
			break;
			case 'W':
				o--;
			break;
		}
	//	cout << n << ", " << s << " , " << e << " , " << o << '\n';
		if(n <= 0 && s <= 0 && e <= 0 && o <= 0)
		{
			cout << i+1 << '\n';
			return 0;
		}
	}
	cout << "-1\n";

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}