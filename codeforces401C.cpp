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
	ll n , m;
	cin >> n >> m;
	if(n-1 > m || m-2 > 2*n)
		cout << "-1\n";
	else if(m >= n)
	{
		while(m > n && m > 1 && n > 0)
		{
			cout << "110";
			m -= 2;
			n--;
		}
		if(m == n)
		{
			while(m > 0)
			{
				cout << "10";
				m--;
			}
		}else if(m > 0)
		{
			for(int i = 0 ; i < m ; i++)
				cout << "1";
		}
		cout << '\n';
	}else
	{
		for(int i = 0 ; i < m ; i++)
			cout << "01";
		cout << "0\n";
	}


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}