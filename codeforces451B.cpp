#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
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
	ll n , l  = -1, r = -1 , a;
	bool f = false;
	cin >> n;
	vll v(n);
	cin >> v[0];
	for(int i = 1 ; i < n ; i++)
	{
		cin >> v[i];
		if(v[i] < v[i-1] && l == -1)
		{
			l = i-1;
			r = i;
		}else
		if(v[i] < v[i-1] && l != -1)
		{
			if(f)
			{
				cout << "no\n";
				return 0;
			}
			r = i;
		}else
		if(v[i] > v[i-1] && l != -1)
		{
			if(v[i] < v[l])
			{
				cout << "no\n";
				return 0;
			}
			f = true;
		}
	}
	if(l == -1)
		cout << "yes\n1 1\n";
	else
	{
		if(l > 0 && v[r] < v[l-1])
			cout << "no\n";
		else
			cout << "yes\n" << l+1 << ' ' << r+1 << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}