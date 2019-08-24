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
	ll m , s1 , s2;
	cin >> m >> s1;
	vpll v(m);
	s2 = s1;
	v[0].xx = 1;
	v[0].yy = min(s2,(ll)9);
	if(s1 < 1)
	{
		if(m > 1)
		{
			cout << "-1 -1\n";
		}else
		{
			cout << "0 0\n";
		}
		return 0;
	}
	s1--;
	s2 -= min(s2,(ll)9);
	for(int i = m-1 ; i > 0 && s1 > 0 ; i--)
	{
		v[i].xx += min(s1,(ll)9);
		s1 -= min(s1,(ll)9);
	}
	for(int i = 1 ; i < m && s2 > 0 ; i++)
	{
		v[i].yy += min(s2,(ll)9);
		s2 -= min(s2,(ll)9);
	}
	if(s1 > 8 || s2 > 0)
		cout << "-1 -1\n";
	else
	{
		if(s1 > 0)
		{
			v[0].xx += s1;
		}
		for(int i = 0 ; i < m ; i++)
			cout << v[i].xx;
		cout << ' ';
		for(int i = 0 ; i < m ; i++)
			cout << v[i].yy;
		cout << '\n';
	}


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}