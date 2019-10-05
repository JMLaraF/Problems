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
	ll n , x , y;
	string s;
	cin >> n >> s;
	vll v(30,0);
	for(int i = 0 ; i < s.size() ; i++)
		v[s[i]-'a']++;
	x = min(min(v['o'-'a'],v['n'-'a']),v['e'-'a']);
	v['e'-'a'] -= x;
	v['o'-'a'] -= x;
	y = min(min(min(v['z'-'a'],v['e'-'a']),v['r'-'a']),v['o'-'a']);
	for(int i = 1 ; i <= x ; i++)
		cout << 1 << ((y == 0 && i == x)?'\n':' ');
	for(int i = 1 ; i <= y ; i++)
		cout << 0 << ((i == y)?'\n':' '); 
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}