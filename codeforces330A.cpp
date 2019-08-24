#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define forn for(int i = 0 ; i < x ; i++)
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
	ll x , y , c = 0 , d = 0;
	cin >> x >> y;
	vector<string> m(x);
	forn
		cin >> m[i];
	for(int i = 0 ; i < x ; i++)
	{
		d = 0;
		bool f = false;
		for(int j = 0 ; j < y ; j++)
		{
			if(m[i][j] == 'S')
			{
				f = true;
				for(int k = j-1 ; k>= 0 ; k--)
					m[i][k] = '.';
				break;
			}else if(m[i][j] == '.')
			{
				m[i][j] = 'x';
				d++;
			}
		}
		if(!f)
			c += d;
	}

	for(int i = 0 ; i < y ; i++)
	{
		d = 0;
		bool f = false;
		for(int j = 0 ; j < x ; j++)
		{
			if(m[j][i] == 'S')
			{
				f = true;
				for(int k = j-1 ; k>= 0 ; k--)
					m[k][i] = '.';
				break;
			}else if(m[j][i] == '.')
			{
				m[j][i] = 'x';
				d++;
			}
		}
		if(!f)
			c += d;
	}
	cout << c << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}