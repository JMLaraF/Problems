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
{
	string a , b;
	ll c , z = 0;
	cin >> a >> b;
	while(a != "0" || b != "0")
	{
		c = 0;
		z = 0;
		if(a.size() < b.size())
			swap(a,b);
		while(b.size() < a.size())
			b.insert(0,"0");
		for(int i = a.size() - 1 ; i >= 0 ;i--)
		{
			c += (a[i] - '0') + (b[i] - '0');
			z += (c>9)? 1:0;
			c /= 10;
		}
		if(z == 0)
			cout << "No carry operation.\n";
		else if(z == 1)
			cout << z << " carry operation.\n";
		else
			cout << z << " carry operations.\n";	
		cin >> a >> b;
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}