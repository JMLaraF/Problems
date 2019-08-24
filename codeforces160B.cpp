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
	ll n;
	string s1 = "",s2 = "";
	char a;
	cin >> n;
	For(o,n)
	{
		cin >> a;
		s1 += a;
	}
	For(o,n)
	{
		cin >> a;
		s2 += a;
	}
	sort(s1.begin() , s1.end());
	sort(s2.begin() , s2.end());
	bool flag;
	if(s1[0] == s2[0])
	{
		cout << "NO\n";
		return 0;
	}else if(s1[0] > s2[0])
		flag = true;
	else
		flag = false;

	for(int i = 1; i < n; i++)
	{
		if(flag && s1[i] <= s2[i])
		{
			cout << "NO\n";
			return 0;
		}else if(!flag && s1[i] >= s2[i])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}