#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
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
	bool f = true;
	vector<string> v(8);
	for(int i = 0 ; i < 8 ; i++)
	{
		cin >> v[i];
		for(int j = 0 ; j < 8 && f ; j+=2)
		{
			if(!((v[i][j] == 'B' && v[i][j+1] == 'W') || (v[i][j] == 'W' && v[i][j+1] == 'B')))
			{
				cout << "NO\n";
				f = false;
				break;
			}
			if(j > 0)
			{
				if(v[i][j] != v[i][j-2] || v[i][j+1] != v[i][j-1])
				{
					cout << "NO\n";
					f = false;
				}
			}
		}
	}
	if(f)
		cout << "YES\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}