#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

vector<short> bs;

void criba(ll nSize)
{
	bs.assign(nSize,0);
	for(ll i = 2; i < nSize; i++)
	{
		for(ll j = i*i; j < nSize; j += i)
			bs[j]=1;
	}
}

int main()
{_C
	ll n , a;
	cin >> n;
	string s;
	criba(5000);
	For(o,n)
	{
		a = 0;
		cin >> s;
		for(int j = 0 ; j < s.size() ; j++)
		{
			a += (s[j] - '0');
		}
		if(bs[a] == 0)
			cout << "UltraPrimo\n";
		else
			cout << "No UltraPrimo\n";
	}	


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}