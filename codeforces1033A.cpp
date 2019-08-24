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

int mov[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
ll n;


bool BFS(vector<vll> &v , pll &K , pll &C)
{
	queue<pll> cola;
	cola.push(K);
	pll aux;
	ll x, y;
	v[K.xx][K.yy] = 2;
	while(!cola.empty())
	{
		aux = cola.front();
		cola.pop();
		for(int i = 0 ; i < 8 ; i++)
		{
			x = aux.xx+mov[i][0];
			y = aux.yy+mov[i][1];
			if(x < 0 || x >= n || y < 0 || y >= n)
				continue;
			if(x == C.xx && y == C.yy)
				return true;
			if(v[x][y] == 0)
			{
				v[x][y] = 2;
				cola.push(pll(x,y));
			}

		}
	}
	return false;
}

int main()
{_C

	pll Q,K,C;
	cin >> n;
	vector<vll> v(n,vll(n,0));
	cin >> Q.xx >> Q.yy;
	cin >> K.xx >> K.yy;
	cin >> C.xx >> C.yy;
	Q.xx--;
	Q.yy--;
	K.xx--;
	K.yy--;
	C.xx--;
	C.yy--;
	ll x , y;
	v[Q.xx][Q.yy] = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j < 8 ; j++)
		{
			x = Q.xx+i*mov[j][0];
			y = Q.yy+i*mov[j][1];
			if(x < 0 || x >= n || y < 0 || y >= n)
				continue;
			v[x][y] = 1;
		}
	}

	cout << ((BFS(v,K,C))?"Yes\n":"No\n");
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}