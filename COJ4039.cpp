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

vll DVS(1000005,2);

void Divisores()
{
	for(int i = 2 ; i <= 1000000 ; i++)
	{
		for(int j = i+1 ; j <= 1000000 ; j += i+1)
		{
			DVS[j]++;
		}
	}
}

int main()
{_C
	Divisores();
	ll n , q;
	cin >> n;
	forn
	{
		cin >> q;
		cout <<"Case #" << i+1 << ": ";
		cout << q - DVS[q] << '\n';
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}