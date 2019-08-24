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
	ll q , n , a;
	cin >> q;
	while(q--)
	{
		bool x = true , y = true;
		cin >> n;
		vll v(n);
		forn
		{
			cin >> v[i];
			v[i]--;
		}
		a = v[0];
		for(int i = 1 ; i < n ; i++ , a = (a+1)%n)
			x &= ((a+1)%n == v[i]);
		a = v[n-1];
		for(int i = n-2 ; i >= 0 ; i-- , a = (a+1)%n)
			y &= ((a+1)%n == v[i]);
		if(x || y)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}