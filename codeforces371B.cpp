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

map<ll,ll> divs(ll a)
{
	map<ll,ll> da;
	ll x = 2 , y;
	while(x*x <= a)
	{
		y = 0;
		while(a%x==0)
		{
			y++;
			a/=x;
		}
		if(y > 0)
			da[x] = y;
		x++;
	}
	if(a > 1)
		da[a] = 1;
		return da;
}

int main()
{_C
	vll p = {2,3,5};
	ll a , b , c , ans = 0;
	map<ll,ll> da , db , dc;
	set<ll> ddc;
	cin >> a >> b;
	if(a == b)
	{
		cout << 0 << '\n';
		return 0;
	}
	da = divs(a);
	db = divs(b);
	c = __gcd(a,b);
	dc = divs(c);
	map<ll,ll>::iterator it = dc.begin();
	
	for(int i = 0 ; i < p.size() ; i++)
		ans += max(da[p[i]],db[p[i]])-min(da[p[i]],db[p[i]]);
	for(it = da.begin() ; it != da.end() ; it++)
	{
		if(it->xx <= 5)
			continue;
		if(!dc.count(it->xx))
		{
			cout << "-1\n";
			return 0;
		}
	}
	for(it = db.begin() ; it != db.end() ; it++)
	{
		if(it->xx <= 5)
			continue;
		if(!dc.count(it->xx))
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}