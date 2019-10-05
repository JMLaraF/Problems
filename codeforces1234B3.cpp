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



int main()
{_C
	ll n, k , a , l = 1;
	cin >> n >> k;
	map<ll,ll> screen;
	forn
	{
		cin >> a;
		if(screen.count(a))
		{
			if(screen[a] < l-k)
			{
				screen[a] = l;
				l++;
			}
		}else
		{
			screen[a] = l;
			l++;
		}
	}
	map<ll,ll>::iterator it;
	vpll v;
	for(it = screen.begin() ; it != screen.end() ; it++)
	{
		v.pb(pll(it->yy,it->xx));
	}
	sort(v.begin() , v.end());
	cout << min(k,(ll)v.size()) << '\n';
	for(int i = v.size() -1 , j = 0 ; j < min(k,(ll)v.size()) ; i-- , j++)
		cout << v[i].yy << ((j == min(k,(ll)v.size())-1)?'\n':' ');


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}