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

int A[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int main()
{_C
	ll n , x , y;
	pll z;
	cin >> n;
	vector<vll> v(2*n+1 , vll(2*n+1 , -1));
	v[n][n] = n;
	queue<pll> q;
	bool flag = false , f2 = false;
	q.push(pll(n,n));
	while(!q.empty())
	{
		z = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			x = z.xx + A[i][0];
			y = z.yy + A[i][1];
			if(x < 0 || y < 0 || x >= 2*n+1 || y >= 2*n+1)
				continue;
			if(v[x][y] < v[z.xx][z.yy])
			{
				q.push(pll(x,y));
				v[x][y] = v[z.xx][z.yy] - 1; 
			}
		}
	}
	for(int i = 0 ; i <= 2*n ; i++)
	{
		flag = false;
		f2 = false;
		for(int j = 0 ; j <= 2*n ; j++)
		{
			if(v[i][j] >= 0)
			{
				flag = true;
			}
			if(v[i][j] < 0 && flag == false)
				cout << "  ";
			else if(v[i][j] < 0 && flag == true)
			{
				cout << '\n';
				break;
			}
			else	
			{
				cout << v[i][j];
				if(i == 0 || i == 2*n)
				{
					cout << '\n';
					break;
				}
				if(f2 == true && v[i][j] == 0)
				{
					cout << '\n';
					break;
				}
				cout << ' ';
				f2 = true;
			}
		}
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}