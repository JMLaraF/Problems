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

set<ll> TP;

void criba()
{
	bitset<nSize+5> bs;
	TP.insert(4);
	for(ll i = 3 ; i <= nSize ; i += 2)
	{
		if(bs[i] == 0)
			TP.insert(i*i);
		for(ll j = i*i ; j <= nSize ; j += i)
			bs[j] = 1;
	}
}


int main()
{_C
	criba();
	ll n , a;
	cin >> n;
	forn
	{
		cin >> a;
		cout << ((TP.count(a))?"YES\n":"NO\n");
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}