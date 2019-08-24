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
	ll q,n;
	cin >> q;
	while(q--)
	{
		ll a;
		bool ans = true;
		cin >> n;
		n *= 4;
		vll v(n);
		forn
			cin >> v[i];
		sort(v.begin() , v.end());
		for(int i = 0 ; i < n/2 && ans ; i+= 2)
		{
			if((v[i] != v[i+1]) || (v[n-i-1] != v[n-i-2]))
			{
				ans = false;
			}
			if(i == 0)
			{
				a = v[0]*v[n-1];
			}else
			{
				if(v[i]*v[n-i-1] != a)
					ans = false;
			}
		}
		if(ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}