#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
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
	ll n , a;
	cin >> n;
	bool f;
	if(n%2 == 0)
		f = true;
	else
		f = false;
	vector<vll> matriz(n,vll(n));
	n *= n;
	vll v(1005)
	forn
	{
		cin >> a;
		v[a]++;
	}
	if(f)
	{
		for(int i = 0 ; i < 1005 ; i++)
		{
			if(v[i]%4 != 0)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}