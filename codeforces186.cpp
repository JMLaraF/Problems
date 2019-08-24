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
	string s1 , s2;
	cin >> s1 >> s2;
	if(s1.size() != s2.size())
	{
		cout << "NO\n";
		return 0;
	}
	vll v;
	for(int i = 0 ; i < s1.size() ; i++)
		if(s1[i] != s2[i])
			v.push_back(i);
	if(v.size() == 2 || v.size() == 0)
	{
		if(v.size() == 2)
		{
			if(s1[v[0]] == s2[v[1]] && s1[v[1]] == s2[v[0]])
				cout << "YES\n";
			else
				cout << "NO\n";
		}else
			cout << "YES\n";
	}else
		cout << "NO\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}