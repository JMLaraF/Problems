#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;
typedef pair<ld,ld> pld;



ld dif(vector<pld> &v , ld x , ld t)
{
	ld f = x/v[v.size() - 1].xx + ((ld)t-x)/v[v.size() - 1].yy;
	ld ans = 1e9 , g;
	for(int i = 0 ; i < v.size() - 1 ; i++)
	{
//		cout << "DF1 > " << ((x/v[i].xx) + (((ld)t - x)/v[i].yy)) << "\tF > " << f << '\n';
		g = ((x/v[i].xx) + (((ld)t - x)/v[i].yy)) - f;
		ans = min(ans , g);
	}
//	cout << "ANS > " << ans << '\n';
	return ans;
}


int main()
{_C
	ll t , n;
	while(cin >> t >> n)
	{
		vector<pld> v(n);
		for(int i = 0 ; i < n ; i++)
			cin >> v[i].xx >> v[i].yy;
		ld l1 = 0 , l2 , r1 = t , r2 , d1 , d2;
		int a = 40;
		while(a--)
		{
			l2 = l1 + (r1-l1)/3;
			r2 = r1 - (r1-l1)/3;
		//	cout << l2 << " , " << r2 << '\n';
			d1 = dif(v , l2 , t);
			d2 = dif(v , r2 , t);
		//	cout << "d1 > " << d1 << " d2 > " << d2 << '\n';
		/*	if(d1 > 0)
			{
				l1 = l2;
				continue;
			}
			if(d2 < 0)
			{
				r1 = r2;
				continue;
			}
		*/	if(d1 > d2)
			{
				r1 = r2;
			}
			else if(d1 < d2)
			{
				l1 = l2;
			}
			else
			{
				l1 = l2;
				l1 = r2;
			}
	//		cout << "DES > " << l1 << " , " << r1 << '\n';
	//		cin >> qwe;
		}
		ld ans = round(l1*100)/100;
		ld df = dif(v , l1 , t)*3600;
		if(df < ERR)
			cout << "The cheater cannot win.\n";
		else
		cout << "The cheater can win by " << (ll)round(df) << fixed << setprecision(2) << " seconds with r = " << ans << "km and k = " << (t - ans) << "km.\n";
	}

	return 0;
}