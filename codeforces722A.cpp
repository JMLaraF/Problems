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
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	int a;
	string s;
	cin >> a >> s;
	if(a == 12)
	{
		if(s[0]-'0' != 1)
		{
			if(s[0]-'0' > 1 && s[1]-'0' != 0)
				cout << '0' << s[1] << ':';
			else if(s[0]-'0' > 1 && s[1]-'0' == 0)
				cout << '1' << s[1] << ':';
			else
			{
				cout << s[0];
				if(s[1]-'0' != 0) 
					cout << s[1] << ':';
				else
					cout << "1:";
			}
		}
		else if(s[1]-'0' > 2)
			cout << "10:";
		else
			cout << s[0] << s[1] << ':';
	}else
	{
		if(s[0]-'0' != 2)
		{
			if(s[0]-'0' > 2)
				cout << '0' << s[1] << ':';
			else
				cout << s[0] << s[1] << ':';
		}else
		{
			if(s[1]-'0' > 3)
				cout << s[0] << "0:";
			else
				cout << s[0] << s[1] << ':';
		}
	}	
	if(s[3]-'0' > 5)
			cout << '0';
		else
			cout << s[3];
	cout << s[4] << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}