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
	ll n , a , mx = INF;
	cin >> n;
	vll ap(6);
	forn
	{
		cin >> a;
		switch(a)
		{
			case 4:
				ap[0]++;
			break;
			case 8:
				if(ap[0] > 0)
				{
					ap[0]--;
					ap[1]++;
				}
			break;
			case 15:
				if(ap[1] > 0)
				{
					ap[1]--;
					ap[2]++;
				}
			break;
			case 16:
				if(ap[2] > 0)
				{
					ap[2]--;
					ap[3]++;
				}
			break;
			case 23:
				if(ap[3] > 0)
				{
					ap[3]--;
					ap[4]++;
				}
			break;
			case 42:
				if(ap[4] > 0)
				{
					ap[4]--;
					ap[5]++;
				}
			break;
		}
	}
	cout << n - ap[5]*6 << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}