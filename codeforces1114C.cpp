#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
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
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	ll a , b , c = 2 , d = 0;
	cin >> a >> b;
	vpll fact;
	while(c*c <= b)
	{
		d = 0;
		while(b%c==0)
		{
			d /= c;
			d++;
		}
		if(d > 0)
			fact.push_back(c,d);
		c++;
	}
	if(b > 1)
		fact.push_back(d,1);

	

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}