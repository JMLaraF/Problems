#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

vpll st;

void push(ll v , ll l , ll r)
{
	if(l-r == 1)
		return;
	ll m = (l+r)/2;
	st[2*v].yy += st[v].yy;
	st[2*v].xx += st[v].yy*(m-l);
	st[2*v+1].yy += st[v].yy;
	st[2*v+1].xx += st[v].yy*(r-m);
	st[v].yy = 0;
}

void updateR(ll v , ll l , ll r , ll x , ll y , ll z)
{
	push(v,l,r);
	if(y < l || x >= r)
		return;
	else if(x <= l && r-1 <= y)
	{
		st[v].yy += z;
		st[v].xx += z*(r-l);
	}else
	{
		ll m = (l+r)/2;
		updateR(2*v,l,m,x,y,z);
		updateR(2*v+1,m,r,x,y,z);
		st[v].xx = st[2*v].xx+st[2*v+1].xx;
	}
	return;
}

ll queryR(ll v , ll l , ll r , ll x , ll y)
{
	if(r-l > 1)
		push(v,l,r);
	if(y < l || x >= r)
		return 0;
	else if(x <= l && r-1 <= y)
		return st[v].xx;
	else
		{
			ll m = (l+r)/2;
			return (queryR(2*v,l,m,x,y) + queryR(2*v+1,m,r,x,y));
		}
}

int main()
{_C

	ll t , n , q , a , b , c , d;
	cin >> t;
	while(t > 0)
	{
		t--;
		cin >> n >> q;
		st.assign(8*100000,pll(0,0));
		while(q > 0)
		{
			q--;
			cin >> a;
			if(a == 0)
			{
				cin >> b >> c >> d;
				updateR(1,1,n+1,b,c,d);
			}else if(a == 1)
			{
				cin >> b >> c;
				cout << queryR(1,1,n+1,b,c) << '\n';
			}
		}
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}