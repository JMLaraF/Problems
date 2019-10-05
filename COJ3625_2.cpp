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

vvll DP(5005 , vll (5005 , -1));

ll dp(ll x , ll y)
{
	if(x == 0 || x == 3)
		return 1;
	if(x < 0)
		return 0;
	if(DP[x][y] != -1)
		return DP[x][y];
	ll k = max(0LL,(ll)(ceil((double)x/3.0)-1.0));
	bool f = false;
	for(int i = 1 ; i <= min(k,2*y) && !f ; i++)
		f |= dp(x-i,i);
	if(f)
		DP[x][y] = 0;
	else
		DP[x][y] = 1;
	return DP[x][y];
}


int main()
{_C

	ll c , n;
	cin >> c;
	while(c--)
	{
		cin >> n;
		if(dp(n,n))
			cout << "Harry wins\n";
		else
			cout << "Ron wins\n";				
	}


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}