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
	ll n , m , a;
	cin >> m >> n;
	vvll matriz(m,vll(n,1));
	vvll m2(m,vll(n));
	for(int i = 0 ; i < m ; i++)
	{
		for(int j  = 0 ; j < n ; j++)
		{
			cin >> a;
			m2[i][j] = a;
			if(a == 0)
			{
				for(int k = 0 ; k < m ; k++)
					matriz[k][j] = 0;
				for(int k = 0 ; k < n ; k++)
					matriz[i][k] = 0;	
			}
		}
	}

	for(int i = 0 ; i < m ; i++)
	{
		for(int j  = 0 ; j < n ; j++)
		{
			if(m2[i][j] == 1)
			{
				bool f = false;
				for(int k = 0 ; k < m && !f ; k++)
					f |= (matriz[k][j] == 1);
				for(int k = 0 ; k < n && !f ; k++)
					f |= (matriz[i][k] == 1);
				if(!f)
				{
					cout << "NO\n";
					return 0;
				}
			}
		}
	}	
	cout << "YES\n";
	for(int i = 0 ; i < m ; i++)
		for(int j  = 0 ; j < n ; j++)
			cout << matriz[i][j] << ((j == n-1)?'\n':' ');

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}