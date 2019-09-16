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
	ll a , b , ta , tb , k , ans = 0;
	cin >> a >> b >> ta >> tb >> k;
	vpll av(a);
	vll bv(b);
	for(int i = 0 ; i < a ; i++)
		cin >> av[i].xx;
	for(int i = 0 ; i < b ; i++)
		cin >> bv[i];

	sort(av.begin() , av.end());
	sort(bv.begin() , bv.end());
	if(a <=  k)
	{
		cout << "-1\n";
		return 0;
	}
	vll::iterator low = lower_bound(bv.begin() , bv.end() , av[0].xx+ta);
	if(low == bv.end())
	{
		cout << "-1\n";
		return 0;
	}
	if(b - (low - bv.begin()) <= k)
	{
		cout << "-1\n";
		return 0;
	}
	for(int i = 0 ; i < a ; i++)
	{
		av[i].yy = (lower_bound(bv.begin() , bv.end() , av[i].xx+ta) - bv.begin());
	}

	for(int i = 0 ; i <= k ; i++)
	{
		if(av[i].yy+k-i < b)
			ans = max(ans,bv[av[i].yy+k-i]);
		else
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << ans+tb << '\n';


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}