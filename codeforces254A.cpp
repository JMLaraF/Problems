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

struct punto
{
	ll x , y;
	punto()
	{
		x = 0;
		y = 0;
	}
};

bool f(const punto &p1 , const punto &p2)
{
	return ((p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y));
}

int main()
{_C

	ll n,t;
	cin >> n;
	

	vector<punto> v((2*n),punto());

	for(int i = 0 ; i < (2*n) ; i++)
	{
		cin >> t;
		v[i].x = t;
		v[i].y = (i+1);
	}

	
	
	if(n == 1)
	{
		cout << "-1\n";
		return 0;
	}
	sort(v.begin(),v.end(),f);
	
	ll z = v[0].x+v[v.size()-1].x;
	vpll ans;
	ans.push_back(pll(v[0].y,v[v.size()-1].y));
	for(int i = 1 ; i < n ; i++)
	{
		if((v[i].x + v[2*n-(1+i)].x) != z)
		{
			cout << "-1\n";
			return 0;
		}
		ans.push_back(pll(v[i].y , v[2*n-(1+i)].y));
	}
	for(int i = 0 ; i < ans.size() ; i++)
		cout << ans[i].xx << ' ' << ans[i].yy << '\n';


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}