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
	
	ll l , k , m , n;
	cin >> l >> k >> m;
	string s;
	vll v(1000005);
	v[0] = 1;
	for(int i = 1 ; i <= 1000000 ; i++)
	{
		bool f = false;
		f |= (v[i-1] == 1);
		if(i >= l)
			f |= (v[i-l] == 1);
		if(i >= k)
			f |= (v[i-k] == 1);
		if(!f)
			v[i] = 1;
	}
	while(m--)
	{
		cin >> n;
		if(v[n])
			s += 'B';
		else
			s += 'A';
	}
	cout << s << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}