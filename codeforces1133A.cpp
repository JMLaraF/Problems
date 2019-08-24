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
	ll h1 = 0 , h2 = 0 , m1 = 0 , m2 = 0 , dif = 0 , mx = 0;
	string s1 , s2;
	cin >> s1 >> s2;
	h1 += 10*(s1[0]-'0');
	h1 += s1[1]-'0';
	h2 += 10*(s2[0]-'0');
	h2 += s2[1]-'0';
	
	m1 += 10*(s1[3]-'0');
	m1 += s1[4]-'0';
	m2 += 10*(s2[3]-'0');
	m2 += s2[4]-'0';
	
	m1 += h1*60;
	m2 += h2*60;

	if(m1 > m2);
		swap(m1,m2);
	dif = m2-m1;
	dif /= 2;
	m1 += dif;
	h1 = m1/60;
	m1 %= 60;
	if(h1 > 9)
		s1 = to_string(h1);
	else
		s1 = "0"+to_string(h1);

	if(m1 > 9)
		s2 = to_string(m1);
	else
		s2 = "0"+to_string(m1);

	cout << s1 << ':' << s2 << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}