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
	ll n , ans = 0;
	cin >> n;
	string s;
	vll class1(26,0);
	vll class2(26,0);

	forn
	{
		cin >> s;
		if(class1[s[0]-'a'] > class2[s[0]-'a'])
			class2[s[0]-'a']++;
		else
			class1[s[0]-'a']++;
	}
	for(int i = 0 ; i < 26 ; i++)
	{
		ans += (class1[i]*(class1[i]-1))/2;
		ans += (class2[i]*(class2[i]-1))/2;
	}
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}