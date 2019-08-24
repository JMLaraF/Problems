#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
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



int main()
{_C
	ll n , k;
	cin >> n >> k;
	vll v(n);
	vll ans(k);
	vpll q(k);
	forn
		cin >> v[i];
	for(int i = 0 ; i < k ; i++)
	{
		cin >> q[i].xx;
		q[i].yy = i;
	}
	sort(q.begin() , q.end());
	set<ll> st;
	ll z = n-1;
	for(int i = k-1 ; i >= 0 ; i--)
	{
		for(int j = z ; j >= q[i].xx-1 ; j--)
		{
			st.insert(v[j]);
		}
		z = q[i].xx-2;
		ans[q[i].yy] = st.size();
	}
	for(int i = 0 ; i < k ; i++)
		cout << ans[i] << '\n';


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}