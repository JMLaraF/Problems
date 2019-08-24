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
	ll z;
	char c;
	vector<vll> matriz(4,vll(4,0));
	for(int i = 0 ; i < 4 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			cin >> c;
			if(c == '#')
				matriz[i][j] = 1;
			if(j > 0)
				matriz[i][j] += matriz[i][j-1];
			if(i > 0)
				matriz[i][j] += matriz[i-1][j];
			if(j > 0 && i > 0)
				matriz[i][j] -= matriz[i-1][j-1];
		}
	}


	for(int i = 1 ; i < 4 ; i++)
	{
		for(int j = 1 ; j < 4 ; j++)
		{
			z = matriz[i][j];
			if(j > 1)
				z -= matriz[i][j-2];
			if(i > 1)
				z -= matriz[i-2][j];
			if(j > 1 && i > 1)
				z += matriz[i-2][j-2];
			if(z == 3 || z == 4 || z == 1 || z == 0)
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}