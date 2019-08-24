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

void BFS(vector<string> &mtz , ll x , ll y)
{
	mtz[y][x] = 'B';
	queue<pll> q;
	q.push(pll(y,x));
	pll z;

	while(!q.empty())
	{
		z = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			x = z.yy + A[i][0];
			y = z.xx + A[i][1];
			if(x < 0 || y < 0 || x >= mtz[0].size() || y >= mtz.size())
				continue;
			if(mtz[y][x] == '.')
			{
				if(mtz[z.xx][z.yy] == 'B')
					mtz[y][x] = 'W';
				else
					mtz[y][x] = 'B';
				q.push(pll(y,x));	
			}
		}
	}
}


int main()
{_C
	ll n , m;
	cin >> n >> m;
	vector<string> mtz(n);
	For(o,n)
		cin >> mtz[i];
	For(o,n)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(mtz[i][j] == '.')
				BFS(mtz , j , i);
		}
	}
	For(o,n)
		for(int j = 0 ; j < m ; j++)
			cout << mtz[i][j] << ((j == m-1)?"\n":"");
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}