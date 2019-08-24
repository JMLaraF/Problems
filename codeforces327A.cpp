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
	ll n , unos = 0 , mx , x;
	cin >> n;
	vll v(n);
	forn
	{
		cin >> v[i];
		if(v[i] == 1)
			unos++;
	}
	mx = 0;
	x = unos;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i ; j < n ; j++)
		{
			for(int k = i ; k <= j ; k++)
			{
				unos += (v[k] == 0)?1:-1;
			}
			mx = max(unos,mx);
			unos = x;
		}
	}
	cout << mx << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}