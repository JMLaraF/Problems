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
typedef int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);



int main()
{
	string s , ans = "";
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(i < s.size()-1 && s[i] == s[i+1])
		{
			ll j = i+2;
			while(j < s.size() && s[j] == s[i])j++;
			ans += s[i];
			i = j-1;
			j = (ll)(ans.size()-3);
			if(j >= 0)
			{
				if(ans[j] != ans[j+1])
					ans += s[i];
			}else
			{
				ans += s[i];
			}
		}else
		{
			ans += s[i];
		}
	}
	cout << ans << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}