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
	ll n , k , ans = 0;
	cin >> n;
	vpll v(n);
	vll b(n,0);
	vpll z;
	forn
		cin >> v[i].xx >> v[i].yy;
	cin >> k;
	vpll vk(k);
	for(int i = 0 ; i < k ; i++)
	{
		cin >> vk[i].xx;
		vk[i].yy = i+1;
	}
	sort(vk.begin() , vk.end());
	for(int i = 0 ; i < k ; i++)
	{
		ll x = -1 , y = 0;
		for(int j = 0 ; j < n ; j++)
		{
			if(b[j] == 0)
			{
				if(v[j].xx <= vk[i].xx && v[j].yy > y)
				{
					if(x >= 0)
						b[x] = 0;
					b[j] = 1;
					x = j;
					y = v[j].yy;
				}
			}
		}
		if(y > 0)
			z.pb(pll(x+1,vk[i].yy));
		ans += y;
	}
	cout << z.size() << ' ' << ans << '\n';
	for(int i = 0 ; i < z.size() ; i++)
		cout << z[i].xx << ' ' << z[i].yy << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}