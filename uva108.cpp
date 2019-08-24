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
	ll n;
	while(cin >> n)
	{
		vector<vll> v(n,vll(n));
		For(o,n)
		{
			for(int j = 0 ; j < n ; j++)
			{
				cin >> v[i][j];
				if(j > 0)
					v[i][j]+=v[i][j-1];
				if(i > 0)
					v[i][j]+=v[i-1][j];
				if(i > 0 && j > 0)
					v[i][j]-=v[i-1][j-1];
			}
		}
		ll mx = -INF;
		For(o,n)
		{
			for(int j = 0 ; j < n ; j++)
			{
				mx = max(mx , v[i][j]);
				for(int k = -1 ; k < i ; k++)
				{
					if(k >= 0)
							mx = max(mx , v[i][j] - v[k][j]);
					for(int l = 0 ; l < j ; l++)
					{
						if(k >= 0)
							mx = max(mx , v[i][j] - v[k][j] - v[i][l] + v[k][l]);
						else
							mx = max(mx , v[i][j] - v[i][l]);
					}
				}
			}
		}
		if(n == 0)
			cout << "0\n";
		else
			cout << mx << '\n';
	}
	
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}