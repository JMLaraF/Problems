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
	ll q , n , ans;
	cin >> q;
	while(q--)
	{
		ans = 0;
		cin >> n;
		if(n == 1)
		{
			cout << "0\n";
			continue;
		}
		while(n%5== 0)
		{
			n = (n/5)*4;
			ans++;
		}
		while(n%3==0)
		{
			n = (n/3)*2;
			ans++;
		}
		ll i = 0 , k = 1;
		while((k<<=1) < n)
		{
			i++;
		}
		if(k == n)
			cout << ans+i+1 << '\n';
		else
			cout << "-1\n";
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}