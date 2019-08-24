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
{
	string s1 , s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i = 0 ; i < s2.size() ; i++)
	{
		if(s2[i] == ' ')
			continue;
		bool flag = false;
		for(int j = 0 ; j < s1.size() && !flag ; j++)
		{
			if(s2[i] == s1[j])
			{
				s1 = s1.substr(0,j)+s1.substr(j+1,s1.size()-j-1);
			//	cout << s1 << "\n";
				flag = true;
			}
		}
		if(!flag)
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