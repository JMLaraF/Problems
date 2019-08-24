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

bitset<3000000> bs;
vll primos;
void criba()
{
	bs[0] = 1;
	bs[1] = 1;
	for(ll i = 2 ; i < 3000000 ; i++)
	{
		if(bs[i] == 0)
			primos.pb(i);
		for(ll j = i*i ; j < 3000000 ; j++)
			bs[j] = 1;
	}
}

int main()
{_C
	criba();
	vll apariciones(3000000);
	ll n , a;
	cin >> n;
	vll ans;
	forn
	{
		cin >> a;
		apariciones[a]++;
	}
	
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}