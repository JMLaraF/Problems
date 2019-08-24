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
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
typedef vector<ld> vld;
typedef vector<vld> vvld;
const ld PI = acos(-1);

vvld m(25,vld(25,-1.0));
string s1 , s2;
ll t;

double dp(ll i , ll j)
{
	if(i == s2.size())
	{
		if(j == t)
			return 1.0;
		else
		 return 0.0;
	}
	if(m[i][j] != -1)
		return m[i][j];
	m[i][j] = 0.0;
	if(s2[i] == '+')
		m[i][j] = dp(i+1,j+1);
	else if(s2[i] == '-')
		m[i][j] = dp(i+1,j-1);
	else
		m[i][j] = (dp(i+1,j+1)+dp(i+1,j-1))/2.0;
	return m[i][j];
}

int main()
{_C
	cin >> s1 >> s2;
	for(int i = 0 ; i < s1.size(); i++)
		t += ((s1[i] == '+')?1:-1);
	t += 12;
	cout << fixed << setprecision(9) << dp(0,12) << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}