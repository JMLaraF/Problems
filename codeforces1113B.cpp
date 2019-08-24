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
	ll n , a = 0 , mx = -1 , ac = 0;
	cin >> n;
	vll v(n);
	forn
	{
		cin >> v[i];
		ac += v[i];
	}
	a = ac;
	sort(v.begin(),v.end());
	forn
	{
		ll j = 100;
		while(j > 1)
		{
			if(v[i]%j == 0 && v[i] != j)
			{
				ac = min(ac,a-v[i]+(v[i]/j)-v[0]+(v[0]*j));
			}
			j--;
		}
	}	
	cout << ac << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}