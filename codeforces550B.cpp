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
typedef int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

ll n , l , r , x;

ll ansF(ll mask , vll &v , ll ac , ll mi , ll ma , ll z)
{
	ll m = mask;
	ll ans = 0;
	if(ac >= l && ac <= r && v[ma]-v[mi] >= x)
		ans++;
	for(int i = z ; i < n ; i++)
	{
		if(!(m&(1<<i)))
		{
			m += (1<<i);
			ans += ansF(m,v,ac+v[i],min(mi,i) , max(ma,i) , i+1);
			m -= (1<<i);
		}
	}
	return ans;
}

int main()
{_C

	cin >> n >> l >> r >> x;
	vll v(n);
	forn
		cin >> v[i];
	sort(v.begin() , v.end());
	cout << ansF(0,v,0,99,0,0) << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}