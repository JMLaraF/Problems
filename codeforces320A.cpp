#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
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
	int t = -1;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == '1' || s[i] == '4')
		{
			if(s[i] == '1')
				t = 0;
			else if(t == 0 && s[i] == '4')
				t = 1;
			else if(t == 1 && s[i] == '4')
				t = 2;
			else if(t > 1 && s[i] == '4')
			{
				cout << "NO\n";
				return 0;
			}else if(t > 1 && s[i] == '1')
				t = 0;
			else
			{
				cout << "NO\n";
				return 0;
			}	
		}else
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