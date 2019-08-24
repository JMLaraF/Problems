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

vpll ST(3*100000+5);

void updateLazy(ll v, ll l , ll r)
{
	ll x = ST[v].yy;
	ST[v].yy = 0;
	if(r-l == 1)
		return;
	ll m = (r+l)/2;
	ST[2*v].yy += x;
	ST[2*v+1].yy += x;
	ST[2*v].xx += x*(m-l);
	ST[2*v+1].xx += x*(r-m);
	
}

void updateE(ll v, ll l , ll r , ll x , ll z)
{
	updateLazy(v,l,r);
	if(x < l || x >= r)
		return;
	else if(r-l == 1)
		ST[v].xx = z;
	else
	{
		ll m = (r+l)/2;
		updateE(2*v,l,m,x,z);
		updateE(2*v+1,m,r,x,z);
	}
}

void updateS(ll v , ll l , ll r , ll x , ll y , ll z)
{
	updateLazy(v,l,r);
	if(y < l || x >= r)
		return;
	else if(x >= l && y < r)
	{
		ST[v].xx += z*(r-l);
		ST[v].yy = z;
	}else
	{
		ll m = (r+l)/2;
		updateS(2*v,l,m,x,y,z);
		updateS(2*v+1,m,r,x,y,z);
	}
}

ll queryE(ll v , ll l , ll r , ll x)
{
	updateLazy(v,l,r);
	if(x < l || x >= r)
		return -5;
	else if(r-l == 1)
		return ST[v].xx;
	else
	{
		ll m = (r+l)/2;
		return max(queryE(2*v,l,m,x),queryE(2*v+1,m,r,x));
	}
}


int main()
{_C
	ll n, q , a , b , c;
	cin >> n >> q;
	forn
	{
		cin >> a;
		updateE(1,1,n+1,i+1,a);
	}
	while(q--)
	{
		cin >> a;
		if(a == 1)
		{
			cin >> b >> c;
			updateE(1,1,n+1,b,c);
		}else if(a == 2)
		{
			cin >> b;
			updateS(1,1,n+1,1,n,b);
		}else
		{
			cin >> b;
			cout << queryE(1,1,n+1,b) << '\n';
		}
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}