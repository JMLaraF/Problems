#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef unsigned long long ll;
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
	ll n , x , ans = 0;
	string s;
	cin >> n;
	map<char,ll> a;
	map<char,ll> b;
	forn
	{
		cin >> s;
		if(!a.count(s[0]))
			a[s[0]] = 1;
		else if(!b.count(s[0]))
			b[s[0]] = 1;
		else if(a[s[0]] <= b[s[0]])
			a[s[0]]++;
		else
			b[s[0]]++;
	}
	map<char,ll>::iterator it;
	for(it = a.begin() ; it != a.end() ; it++)
	{
		if(it->yy == 1)
			continue;
		else if(it->yy == 2)
			ans += 1;
		else
			ans += ((it->yy%2==0)?((it->yy/2)*(it->yy-1)):((it->yy)*((it->yy-1)/2)));
	}
	for(it = b.begin() ; it != b.end() ; it++)
		if(it->yy == 1)
			continue;
		else if(it->yy == 2)
			ans += 1;
		else
			ans += ((it->yy%2==0)?((it->yy/2)*(it->yy-1)):((it->yy)*((it->yy-1)/2)));
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}	