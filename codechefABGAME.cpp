#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);



int main()
{_C
	ll t;
	string s;
	cin >> t;
	while(t--)
	{
		ll a = 0 , x = 0, b = 0 , acumulado = 0 , c = 0 , d = 0;
		cin >> s;
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(s[i] == '.')
			{
				++acumulado; 
			}else if(s[i] == 'A')
			{
				a++;
				if(a == 2)
				{
					c += acumulado;
					a = 0;
				}else
				if(x == 1)
				{
					b ^= acumulado;
					x = 0;
					a = 0;
				}
				acumulado = 0;
			}else
			{
				x++;
				if(x == 2)
				{
					d += acumulado;
					x = 0;
				}
				if(a == 1)
				{
					b ^= acumulado;
					a = 0;
					x = 0;
				}
				acumulado = 0;
			}
		}
		if(a > 0)
			c += acumulado;
		if(x > 0)
			d += acumulado;
		if(b != 0)
		{
			if(c >= d)
				cout << "A\n";
			else
				cout << "B\n";
		}else
		{
			if(d >= c)
				cout << "B\n";
			else
				cout << "A\n";
		}
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}