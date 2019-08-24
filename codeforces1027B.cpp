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


int main()
{_C
	ll n , q , x , y , ans;
	cin >> n >> q;
	while(q--)
	{
		cin >> x >> y;
		x--;
		y--;
		ans = 0;
		if(x%2==0)
		{
			ans += (n*n)/2+1;
			x = x/2;
		}else
		{
			x = x/2+1;
		}
		ans += 
		
	}

//	si n es par n/2 de los primeros
//	si es impar (n/2)+1 de los primeros
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}