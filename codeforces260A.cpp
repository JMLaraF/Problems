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
	ll a , b , c , i = 0;
	bool f = false;
	cin >> a >> b >> c;
	while(i < 10)
	{
		if((a*10+i)%b==0)
		{
			f = true;
			a = a*10+i;
			break;
		}
		i++;
	}
	if(f)
	{
		cout << a;
		for(int i = 1 ; i < c ; i++)
			cout << '0';
		cout << '\n';
	}else
	{
		cout << "-1\n";
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}