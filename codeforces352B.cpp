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
{
	ll n , a , d = 0;
	vector<vll> v(100005);
	map<ll,ll> m;
	cin >> n;
	For(o,n)
	{
		cin >> a;
		v[a].push_back(i+1);
	}
	for(int i = 0 ; i < 100001 ; i++)
	{
		int b = 0;
		bool c = true;

		for(int j = 0 ; j < ((ll)v[i].size() -1) ; j++)
		{
			if(b == 0)
				b = v[i][j+1]-v[i][j];
			else
				c &= (b==v[i][j+1]-v[i][j]);
		}
		if(c && v[i].size() > 0)
		{
			d++;
			m[i] = b;
		}
	}
	cout << d << '\n';
	map<ll,ll>::iterator it;
	for(it = m.begin() ; it != m.end() ; it++)
		cout << it->xx << ' ' << it->yy << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}