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
	vll a , b;
	string s;
	cin >> s;
	s = s;
	bool f = false;
	for(int i = 1 ; i < s.size() ; i++)
	{
		if(s[i-1] == 'A' && s[i] == 'B')
			a.pb(i-1);
		if(s[i-1] == 'B' && s[i] == 'A')
			b.pb(i-1);
	}
	if(a.size() == 0 || b.size() == 0)
	{
		cout << "NO\n";
		return 0;
	}
	if (b[b.size() -1] > a[0]+1)
	{
		if(a[0] == 0)
		{
			for(int i = 0 ; i < b.size() ; i++)
			{
				if(b[i] > 1 && b[i] != s.size()-1)
				{
					f = true;
					break;
				}		
			}
		}else
			f = true;
	}
	if (a[a.size()-1] > b[0]+1)
	{
		if(b[0] == 0)
		{
			for(int i = 0 ; i < a.size() ; i++)
			{
				if(a[i] > 1 && a[i] != s.size()-1)
				{
					f = true;
					break;
				}		
			}
		}else
			f = true;
	}
	if(f)
		cout << "YES\n";
	else
		cout << "NO\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}