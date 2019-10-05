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
	ll q , n;
	string s[2];
	cin >> q;
	while(q--)
	{
		bool f = false;
		cin >> n;
		cin >> s[0] >> s[1];
		ll x = 0 , y = 0;
		while(x < n)
		{
			if(s[y][x] <= '2')
			{
				x++;
			}else
			{
				if(s[(y+1)%2][x] <= '2')
				{
					f = true;
					cout << "NO\n";
					break;
				}else
				{
					++x;
					y = (y+1)%2;
				}
			}
		}
		if(!f)
		{
			if(y)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}