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

bool c2(const pll &p1 , const pll &p2)
{
	return p1.yy < p2.yy || (p1.yy == p2.yy && p1.xx < p2.xx);
}

int main()
{_C
	ll n , x = 0 , ans = 0 , y = 0;
	cin >> n;
	vpll v(n);
	forn
		cin >> v[i].xx >> v[i].yy;
	sort(v.begin() , v.end());
	for(int i = 1 ; i < n ; i++)
	{
		if(v[i].xx == v[i-1].xx)
		{
			x++;
		}
		else
		{
			ans += (x*(x+1))/2;
			x = 0;
		}
	}
	ans += (x*(x+1))/2;
	x = 0;
	sort(v.begin() , v.end() , c2);
	for(int i = 1 ; i < n ; i++)
	{
		if(v[i].yy == v[i-1].yy)
		{
			x++;
			if(v[i].xx == v[i-1].xx)
			{
				y++;
			}else
			{
				ans -= (y*(y+1))/2;
				y = 0;
			}
		}
		else
		{
			ans += (x*(x+1))/2;
			ans -= (y*(y+1))/2;
			y = 0;
			x = 0;
		}
	}
	ans += (x*(x+1))/2;
	ans -= (y*(y+1))/2;
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}