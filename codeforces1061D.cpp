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

bool srt(const pll &p1 , const pll &p2)
{
	return p1.xx < p2.xx || (p1.xx == p2.xx && p1.xx > p2.xx);
}

int main()
{_C
	ll n , x , y , c = 0;
	cin >> n >> x >> y;
	vpll v(n);
	forn
		cin >> v[i].xx >> v[i].yy;
	sort(v.begin(),v.end() , srt);
	bool f;
	multiset<ll> mst;
	multiset<ll>::iterator it;
	forn
	{
		f = false;
		it = mst.lower_bound(v[i].xx-1);
		if(*it >= v[i].xx && it != mst.begin())
			it--;
		if(it != mst.end() && *it < v[i].xx && (v[i].xx-(*it))*y <= x)
		{
			c += ((v[i].yy-(*it))*y)%MOD;
			mst.erase(it);
			mst.insert(v[i].yy);
		}else
		{
			mst.insert(v[i].yy);
			c += ((v[i].yy-v[i].xx)*y)%MOD;
		}
	}
	cout << (((((x*mst.size())+MOD)%MOD)+(c))+MOD)%MOD << '\n'; 
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}