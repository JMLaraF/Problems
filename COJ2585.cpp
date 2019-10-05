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
	ll a = 0 , a2 = 0 , b = 0;
	bool z = false;
	bool y = false;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == '.')
		{
			z = true;
			a++;
		}
		else
		{
			b ^= a;
			a = 0;
			y = true;
		}
	}
	b ^= a;
	if(!z || !y)
	{
		cout << "Rabbit\n";
		return 0; 
	}
	if(b)
		cout << "Cat\n";
	else
		cout << "Rabbit\n";

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}