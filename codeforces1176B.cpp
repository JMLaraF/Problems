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
	ll q , n;
	cin >> q;
	while(q--)
	{
		ll a[3] = {0,0,0};
		cin >> n;
		vll v(n);
		forn
		{
			cin >> v[i];
			v[i] %= 3;
			a[v[i]]++;
		}
		ll z = min(a[1],a[2]);
		a[0] += z;
		a[1] -= z;
		a[2] -= z;
		cout << a[0] + a[1]/3 + a[2]/3 << '\n';

	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}