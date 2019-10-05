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
	ll bp , sp , cp , ba = 0 , sa = 0 , ca = 0 , bn = 0 , cn = 0 , sn = 0 , r;
	ll ans = 0 , x = INF , y = INF , z = INF;
	string s;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == 'S')
			sn++;
		if(s[i] == 'C')
			cn++;
		if(s[i] == 'B')
			bn++;
	}
	cin >> ba >> sa >> ca;
	cin >> bp >> sp >> cp;
	cin >> r;
	if(bn > 0)
		x = ba/bn;
	else
		ba = 0;
	if(sn > 0)
		y = sa/sn;
	else
		sa = 0;
	if(cn > 0)
		z = ca/cn;
	else
		ca = 0;
	x = min(x,min(y,z));
	ans += x;
	ba -= x*bn;
	sa -= x*sn;
	ca -= x*cn;
	while(ba > 0 || sa > 0 || ca > 0)
	{
		if(bn >= ba)
		{
			r -= bp*(bn-ba);
			ba = 0;
		}
		else
			ba -= bn;
		if(sn >= sa)
		{
			r -= sp*(sn-sa);
			sa = 0;
		}
		else
			sa -= sn;
		if(cn >= ca)
		{
			r -= cp*(cn-ca);
			ca = 0;
		}
		else
			ca -= cn;
		if(r >= 0)
			ans++;
	}
	x = bn*bp+cn*cp+sn*sp;
	ans += r/x;
	cout << ans << '\n';	




	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}