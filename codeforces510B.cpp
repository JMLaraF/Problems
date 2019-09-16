#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
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

ll n , k;
ll mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

bool DFS(char c , pll a , pll b , vector<string> &v)
{
	bool ans = false;
	ll x , y;
	v[a.yy][a.xx] = c-30;
	for(int i = 0 ; i < 4 ; i++)
	{
		x = a.xx+mov[i][0];
		y = a.yy+mov[i][1];
		if(x < 0 || y < 0 || x >= k || y >= n)
			continue;
		if(x == b.xx && y == b.yy)
			continue;
		if(v[y][x] == c-30)
			return true;
		if(v[y][x] == c)
			ans |= DFS(c,pll(x,y),a,v);
	}
	return ans;
}

int main()
{_C

	bool ans = false;
	cin >> n >> k;
	vector<string> v(n);
	forn
	{
		cin >> v[i];
	}
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < k ; j++)
		{
			if(v[i][j] >= 'A' && v[i][j] <= 'Z')
				ans |= DFS(v[i][j],pll(j,i),pll(-1,-1),v);
		}
	}
	cout << ((ans)?"Yes\n":"No\n");

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}