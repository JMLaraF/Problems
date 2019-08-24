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
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

int mov[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};



int main()
{_C
	ll n , z;
	cin >> n >> z;
	vector<string> matriz(n);
	forn
	{
		cin >> matriz[i];
	}
	ll x , y;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < matriz[i].size() ; j++)
		{
			if(matriz[i][j] == 'S')
			{
				for(int k = 0 ; k < 4 ; k++)
				{
					x = j+mov[k][0];
					y = i+mov[k][1];
					if(x < 0 || x >= matriz[i].size() || y < 0 || y >= n)
						continue;
					if(matriz[y][x] == 'W')
					{
						cout << "No\n";
						return 0;
					}
				}
			}
		}
	}
	cout << "Yes\n";
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < matriz[i].size() ; j++)
		{
			if(matriz[i][j] == '.')
				cout << 'D';
			else
				cout << matriz[i][j];
		}
		cout << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}