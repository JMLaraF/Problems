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

int m[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
ll n , a;

struct lobo
{
	ll x , y , z;
	vpll c;
	lobo():z(0){};

};

bool cmp (const lobo &a , const lobo &b)
{
	return a.z < b.z;
}



int main()
{_C
	ll x;
	ll y;
	cin >> n >> a;
	vector<string> v(n);
	vector<lobo> b;
	forn
	{
		cin >> v[i];
	}
	forn
	{
		for(int j = 0 ; j < v[i].size() ; j++)
		{
			if(v[i][j] == 'W')
			{
				lobo nw;
				for(int k = 0 ; k < 4 ; k++)
				{
					x = j+m[k][0];
					y = i+m[k][1];
					if(x < 0 || x >= a || y < 0 || y >= n)
						continue;
					if(v[y][x] == 'P')
					{
						nw.c.push_back(pll(x,y));
						nw.z++;
					}
				}
				b.push_back(nw);
			}
		}
	}
	ll ans = 0;
	sort(b.begin() , b.end() , cmp);
	for(int i = 0 ; i < b.size() ; i++)
	{
		for(int j = 0 ; j < b[i].c.size() ; j++)
		{
			x = b[i].c[j].xx;
			y = b[i].c[j].yy;
			if(v[y][x] == 'P')
			{
				ans++;
				v[y][x] = '.';
				break;
			}
		}
	}
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}