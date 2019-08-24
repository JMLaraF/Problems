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

bool comp(const pair<pll,ll> &p1 , const pair<pll,ll> &p2)
{
	return p1.xx.xx < p2.xx.xx || (p1.xx.xx == p2.xx.xx && p1.xx.yy > p2.xx.yy);
}


int main()
{_C
	ll n;
	cin >> n;
	vector<pair<pll,ll> > v(n);
	For(o,n)
	{
		cin >> v[i].xx.xx >> v[i].xx.yy;
		v[i].yy = 1+i;
	}
	sort(v.begin() , v.end() , comp);
	ll a = v[0].xx.xx , b = v[0].xx.yy;
	for(int i = 1 ; i < n ; i++)
	{
		if(v[i].xx.yy > b)
		{
			cout << "-1\n";
			return 0;
		}

	}
	cout << v[0].yy << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}