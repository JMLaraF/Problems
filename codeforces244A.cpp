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
const ld PI = acos(-1);


int main()
{_C
	ll n , k , a;
	cin >> k >> n;
	vll v(n*k);
	forn
	{
		cin >> a;
		v[a-1] = i+1;
	}
	ll j = 0;
	for(int i = 0 ; i < v.size() ; i++)
	{
		if(v[i] == 0)
		{
			v[i] = j+1;
			j = (j+1)%n;
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j < v.size() ; j++)
		{
			if(v[j] == i)
				cout << j+1 << ' ';
		}
		cout << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}