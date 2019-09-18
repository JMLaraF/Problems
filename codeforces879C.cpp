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
	ll n , a , orf = 0 , andf = 1023 , xorf = 0 , x = 0;
	char c;
	cin >> n;
	forn
	{
		cin >> c >> a;
		if(c == '|')
			orf |= a;
		else if(c == '&')
			andf &= a;
		else
			xorf ^= a;
	}
	if(orf > 0)
		x++;
	if(andf != 1023)
		x++;
	if(xorf > 0)
		x++;
	cout << x << '\n';
	if(xorf > 0)
		cout << "^ " << xorf << '\n';
	if(orf > 0)
		cout << "| " << orf << '\n';
	if(andf != 1023)
		cout << "& " << andf << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}