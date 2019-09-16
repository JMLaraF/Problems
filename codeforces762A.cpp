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

ll pot(ll a , ll b)
{
	ll ans = 1;
	if(b == 0)
		return ans;
	for(int i = 0 ; i < 63 ; i++)
	{
		if(((1LL<<i)&b)!=0)
			ans *= a;
		a *= a;
	}
	return ans;
}

void divisores(vpll &a , vll &ans , ll x , ll z)
{
	if(x == a.size())
	{
		ans.pb(z);
		return;
	}
	for(int i = 0 ; i <= a[x].yy ; i++)
	{
		ll y = z*pot(a[x].xx,i);
		divisores(a,ans,x+1,y);
	}
	return;
}



int main()
{_C
	ll n , k , x = 2 , y = 0;
	cin >> n >> k;
	vpll divs;
	while(x*x <= n)
	{
		y = 0;
		while(n%x == 0)
		{
			y++;
			n /= x;
		}
		if(y)
			divs.pb(pll(x,y));
		x++;
	}
	if(n != 1)
	{
		divs.pb(pll(n,1));
	}

	vll B2;
	divisores(divs,B2,0,1);
	sort(B2.begin(),B2.end());
	if(k <= B2.size())
		cout << B2[k-1] << '\n';
	else
		cout << "-1\n";


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}