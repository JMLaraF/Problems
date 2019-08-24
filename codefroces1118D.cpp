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

bool srt(const ll &p1 , const ll &p2)
{
	return p1 > p2;
}


int main()
{_C
	ll n , k;
	cin >> n >> k;
	vll v(n);
	forn
		cin >> v[i];
	sort(v.begin(),v.end(),srt)
	ll a = 0 , b = 1;
	for(int i = 0 ; i < n-1 && k > 0 ; i++)
	{
		if(v[i] >= v[i+1])
		{
			k -= v[i]-a;
			a++;
		}else
		{
			b++;
			a = 0;
			k -= v[i];
		}
	}
	if(k > 0)
	{
		if(k - v[n-1]-a <= 0)
			cout << b << '\n';
		else if(k - v[n-1] <= 0)
			cout << b+1 << '\n';
		else
			cout << "-1\n";
	}else
	{
		cout << b << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}