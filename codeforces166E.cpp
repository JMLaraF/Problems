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
	ll n;
	cin >> n;
	vvll v(4,vll(2,0));
	v[3][0] = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		v[0][i%2] = (v[1][(i-1)%2]+v[2][(i-1)%2]+v[3][(i-1)%2]) % MOD;
		v[1][i%2] = (v[0][(i-1)%2]+v[2][(i-1)%2]+v[3][(i-1)%2]) % MOD;
		v[2][i%2] = (v[1][(i-1)%2]+v[0][(i-1)%2]+v[3][(i-1)%2]) % MOD;
		v[3][i%2] = (v[1][(i-1)%2]+v[2][(i-1)%2]+v[0][(i-1)%2]) % MOD;
	}
	cout << v[3][n%2] << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}