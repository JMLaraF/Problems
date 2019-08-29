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

	string s;
	cin >> s;
	ll x = 0;
	ll z = -1;
	ll ans[3] = {-1,-1,-1};
	for(int i = s.size() -1 ; i >= 2 ; i--)
		{
			for(int j = i-1 ; j >= 1 ; j--)
			{
				for(int k = j-1 ; k >= 0 ; k--)
				{
					x = (s[k]-'0')*100 + (s[j]-'0')*10 + (s[i]-'0');
					if(x%8 == 0 && k > z)
					{
						ans[2] = k;
						ans[1] = j;
						ans[0] = i;
					}
				}
			}
		}
		if(ans[2] == -1)
		{
			for(int i = s.size() -1 ; i >= 1 ; i--)
			{
				for(int j = i-1 ; j >= 0 ; j--)
				{
					x = (s[j]-'0')*10 + (s[i]-'0');
					if(x%8 == 0)
					{
						ans[1] = j;
						ans[0] = i;
					}
				}
			}
		}
		if(ans[1] == -1)
		{
			for(int i = s.size() -1 ; i >= 0 ; i--)
			{
				x = (s[i]-'0');
				if(x%8 == 0)
				{
					ans[0] = i;
				}
			}
		}
		if(ans[0] == -1)
			cout << "NO\n";
		else if(ans[2] != -1)
		{
			cout << "YES\n";
			for(int i = 0 ; i < ans[2] ; i++)
				cout << s[i];
			cout << s[ans[2]] << s[ans[1]] << s[ans[0]] << '\n';

		}else if(ans[1] != -1)
		{
			cout << "YES\n" << s[ans[1]] << s[ans[0]] << '\n';
		}else
		{
			cout << "YES\n" << s[ans[0]] << '\n';
		}
	


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}