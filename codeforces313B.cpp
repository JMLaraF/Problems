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
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

vll DP(100005);

int main()
{_C
	string s;
	cin >> s;
	ll n , a , b;
	for(int i = 1 ; i < s.size() ; i++)
	{
		DP[i] = DP[i-1];
		if(s[i] == s[i-1])
			DP[i]++;
	}
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		cout << DP[b-1]-DP[a-1] << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}