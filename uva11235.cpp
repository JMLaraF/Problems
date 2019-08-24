#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 100000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

ll st[4*nSize];

void init(ll v , ll l, ll r , vll &vs)
{
	if(r-l == 1)
	{
		st[v] = 1;
	}else
	{
		ll m = (l+r)/2;
		init(2*v,l,m,vs);
		init(2*v+1,m,r,vs);
		if(vs[m-2] == vs[m-1])
			st[v] = st[2*v]+st[2*v+1];
		else
			st[v] = max(st[2*v],st[2*v+1]);
		cout << l << " , " << r << " , " << m-2 << " , " << m-1 << '\n';
	}
}

ll query(ll v , ll l , ll r , ll i , ll j , vll &vs)
{
	if(j < l || i >= r)
	{
		return 0;
	}else if(i <= l && r-1 <= j)
	{
		return st[v];
	}else
	{
		ll m = (l+r)/2;
		if(vs[m-2] == vs[m-1])
			return query(2*v,l,m,i,j,vs) + query(2*v+1,m,r,i,j,vs);
		else
			return max(query(2*v,l,m,i,j,vs),query(2*v+1,m,r,i,j,vs));
	}
}

int main()
{_C
	ll n , q,a,b;
	cin >> n >> q;
	vll v(n);
	For(o,n)
		cin >> v[i];
	init(1,1,n+1,v);
	while(q--)
	{
		cin >> a >> b;
		cout << query(1,1,n+1,a,b,v) << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}