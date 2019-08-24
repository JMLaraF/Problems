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
	ll z , a , b;
	ll x[3];
	cin >> x[0] >> x[1] >> z;
	x[0] %= MOD;
	x[1] %= MOD;
	x[2] = (x[1]-x[0])%MOD;
	if(x[0] == 0 && x[1] == 0)
	{
		cout << "0\n";
		return 0;
	}
	z--;
	a = z%3;
	b = z/3;
	if(b%2==0)
	{
		cout << ((x[a] >= 0)?x[a]:MOD+x[a]) << '\n';
	}else
	{
		cout << (((-x[a]) >= 0)?(-x[a]):MOD-x[a]) << '\n';
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}