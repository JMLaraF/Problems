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
typedef vector<vll> matrizL;

ll dp(matrizL m , ll x , ll y , ll n)
{
	if(y > n || x > n)
		return 0;
	ll ans = 0;	
	for(int i = x ; i < m.size() ; i++)
	{
		for(int j = y ; j < m[i].size() ; j++)
		{
			if(m[i][j] == -1)
			{
				m[i][j] == 0;
				for(int k = 1 ; k+x < n && k+y < n ; k++)
				{
					m[i+k][j+k] == 0;
					m[i+k][j] == 0;
					m[i][j+1] == 0;
				}
			}
			for(int k = 0 ; k < n ; k++)
			{
				for(int l = 0 ; l < n ; l++)
				{
					cout << m[k][l] << ((l == n-1)? '\n' : ' ');
				}
			}
			cout << "\n\n";
			ans += dp(m , i , j , n) + 1;
		}
	}
	return ans;
}

int main()
{
	ll n;
	while(cin >> n)
	{
		if(n == 1)
		{
			cout << "No Solution.\n";
			continue;
		}else
		{
			matrizL v(n , vll(n , -1));
			ll ans = dp(v , 0 , 0 , n);
			cout << ans << '\n';
		}
	}
	#ifdef LOCAL
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}