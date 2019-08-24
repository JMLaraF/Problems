#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define forn for(int i = 0 ; i < n ; i++)
#define fornr for(int i = n-1 ; i >= 0 ; i--)
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
	ll n , c = 0;
	cin >> n;

	vll v(n);
	vll b(n);
	forn
		cin >> v[i];
	if (n == 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	else if(n == 2)
	{
		cout << 0 << '\n';
		return 0;
	}else if(n == 3)
	{
		if(v[0] == v[1])
			c++;
		if(v[0] == v[2])
			c++;
		if(v[1] == v[2])
			c++;
		cout << c << '\n';
		return 0;
	}
	b[n-1] = v[n-1];
	b[n-2] = v[n-2];
	for(int i = n-3 ; i >= 0 ; i--)
	{
		b[i] = b[i+2]+v[i];
	}
	for(int i = 0 ; i < n ; i++)
	{
		if(i == 0)
		{
			c += ((b[i+1] == b[i+2])?1:0);
			b[i] = v[i];
		}
		else if(i == 1)
		{
			c += ((b[i+1] == b[i+2]+b[i-1])?1:0);
			b[i] = v[i];
		}else if(i == n-2)
		{
			c += ((b[i+1]+b[i-2] == b[i-1])?1:0);
			b[i] = b[i-2]+v[i];
		}else if (i == n-1)
		{
			c += ((b[i-2] == b[i-1])?1:0);
		}
		else
		{
			c += ((b[i+1]+b[i-2] == b[i+2]+b[i-1])?1:0);
			b[i] = b[i-2]+v[i];
		}

	}
	cout << c << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}