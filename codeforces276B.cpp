#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	string s;
	cin >> s;
	ll c = 0;
	vll v(26,0);
	for(int i = 0 ; i < s.size() ; i++)
		v[s[i]-'a']++;
	for(int i = 0 ; i < v.size() ; i++)
		c += (v[i]%2!=0)?1:0;
	if(c%2!=0 || c == 0)
		cout << "First\n";
	else
		cout << "Second\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}