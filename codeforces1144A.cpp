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


int main()
{_C
	ll t;
	string s;
	cin >> t;
	while(t--)
	{
		vll v(27,0);
		cin >> s;
		for(int i = 0 ; i < s.size() ; i++)
			v[s[i]-'a']++;
		int i = -1 , j;
		while(v[++i] == 0);
		j = i-1;
		while(v[++j] == 1);
		if(j-i == s.size())
			cout << "Yes\n";
		else
			cout << "No\n";


	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}