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
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

struct rt
{
	ll a , b , c;
	rt(ll _a , ll _b , ll _c)
	{
		a = _a;
		b = _b;
		c = _c;
	}
	ll ans()
	{
		if(c > 0)
			return 1;
		else
			return min(a,b);
	}
};

struct rt operator+(const rt &p1 , const rt &p2)
{
	return rt(p1.a+p2.a,p1.b+p2.b,p1.c+p2.c);
}

struct nodo
{
	ll a,b,c,d,f,g;
	nodo()
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		f = 0;
		g = 0;
	}
};

nodo st[3*100000];

ll r1 = 0, r2 = 0;


void push(ll v , ll l , ll r)
{
	if(st[v].c == 0 && st[v].d == 0 && st[v].g == 0)
		return;
	ll m = (l+r)/2;

	st[2*v].c = st[v].c;
	st[2*v].d = st[v].d;
	st[2*v].g = st[v].g;	
	st[2*v].a = st[v].c*(m-l);
	st[2*v].b = st[v].d*(m-l);
	st[2*v].f = st[v].g*(m-l);
	st[2*v+1].c = st[v].c;
	st[2*v+1].d = st[v].d;
	st[2*v+1].g = st[v].g; 
	st[2*v+1].a = st[v].c*(r-m);
	st[2*v+1].b = st[v].d*(r-m);
	st[2*v+1].f = st[v].g*(r-m);
	st[v].c = 0;
	st[v].d = 0;
	st[v].g = 0;
}

void updateR(ll v , ll l , ll r , ll x , ll y , pll z , ll f)
{
	push(v,l,r);
	if(y < l || x >= r)
		return;
	else if(x <= l && r-1 <= y)
	{
		st[v].c = z.xx;
		st[v].d = z.yy;
		st[v].g = f;
		st[v].f = f*(r-l);
		st[v].a = z.xx*(r-l);
		st[v].b = z.yy*(r-l);
	}else
	{
		ll m = (l+r)/2;
		updateR(2*v,l,m,x,y,z,f);
		updateR(2*v+1,m,r,x,y,z,f);
		st[v].a = st[2*v].a+st[2*v+1].a;
		st[v].b = st[2*v].b+st[2*v+1].b;
		st[v].f = st[2*v].f+st[2*v+1].f;
	}
}

rt queryR(ll v , ll l , ll r , ll x , ll y)
{
	push(v,l,r);
	if(y < l || x >= r)
		return rt(0,0,0);
	else if(x <= l && r-1 <= y)
	{
	//	cout << "V = " << v << " a= " << st[v].a << " b= " << st[v].b << " f= " << st[v].f << '\n';
		return rt(st[v].a,st[v].b,st[v].f);
	}
	else
	{
		ll m = (l+r)/2;
		rt p1 = queryR(2*v,l,m,x,y);
		rt p2 = queryR(2*v+1,m,r,x,y);
	/*	cout << "p1 a= " << p1.a << " b= " << p1.b << " f= " << p1.c << '\n';
		cout << "p2 a= " << p2.a << " b= " << p2.b << " f= " << p2.c << '\n';
		cout << "V = " << v << " a= " << (p1+p2).a << " b= " << (p1+p2).b << " f= " << (p1+p2).c << '\n';
	*/	return (p1+p2);
	}
}

int main()
{_C
	ll n,a,b,c,d,q,x,y,z;
	pll ans;
	cin >> n;
	For(o,n)
	{
		x = 0;
		y = 0;
		z = 0;
		cin >> a;
		if(a <= 0)
			z = 1;
		else
		{
			while(a%2==0)
			{
				a/=2;
				x++;
			}
			while(a%5==0)
			{
				a/=5;
				y++;
			}
		}
		
		updateR(1,1,n+1,i+1,i+1,pll(x,y),z);
	}
	cin >> q;
	while(q > 0)
	{
		q--;
		cin >> d >> b >> c;
		if(d == 1)
		{
			cout << queryR(1,1,n+1,b,c).ans() << '\n';
		}else if(d == 0)
		{
			x = 0;
			y = 0;
			z = 0;
			cin >> a;
			if(a <= 0)
				z = 1;
			else
			{
				while(a%2==0)
				{
					a/=2;
					x++;
				}
				while(a%5==0)
				{
					a/=5;
					y++;
				}
			}
	
			updateR(1,1,n+1,b,c,pll(x,y),z);
		}
	}
	
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}