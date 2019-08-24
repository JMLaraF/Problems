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

struct nodo
{
	ll v , vv;
	struct nodo *l , *r;
	nodo()
	{
		v = 0;
		vv = 0;
		l = NULL;
		r = NULL;
	}
	nodo(const struct nodo *n)
	{
		if(n!= NULL)
		{
			vv = n->vv;
			v = n->v;
			l = n->l;
			r = n->r;
		}else
		{
			nodo();
		}
	}
};



class STP
{
	private:
		vector<nodo> v;

		void update(nodo *a , nodo *b , ll l , ll r , ll x , ll z)
		{
			if((r-l) == 1 && l == x)
			{
				a->v = z;
			}else
			{
				ll m = (l+r)/2;
				if(x < l || x >= m)
				{
					if(b != NULL)
						a->l = b->l;
					else
						a->l = NULL;
				}else
				{
					nodo * n = new nodo();
					a->l = n;
					if(b != NULL)
						update(n,b->l,l,m,x,z);
					else
						update(n,b,l,m,x,z);
				}


				if(x < m || x >= r)
				{
					if(b != NULL)
						a->r = b->r;
					else
						a->r = NULL;
				}else
				{
					nodo * n = new nodo();
					a->r = n;
					if(b != NULL)
						update(n,b->r,m,r,x,z);
					else
						update(n,b,m,r,x,z);
				}
				ll x = 0 , x2 = 0 , y = 0 , y2 = 0;
				if(a->l != NULL)
				{
					x = a->l->v;
					x2 = a->l->vv;
				}
				if(a->r != NULL)
				{
					y = a->r->v;
					y2 = a->r->vv;
				}
				if(x < x2)
					swap(x,x2);
				if(x < y)
					swap(x,y);
				if(x < y2)
					swap(x,y);
				if(y < x2)
					swap(y,x2);
				if(y < y2)
					swap(y,y2);
				a->v = x;
				a->vv = y;
			}
		}
	public:
		STP()
		{
			v.push_back(nodo());
		}
	/*	ll op(nodo *a , ll z)
		{
			a->v += z;
		}
	*/	void updateV(ll l , ll r , ll x , ll z)
		{
			v.push_back(nodo(&v[v.size()-1]));
			update(&v[v.size()-1] , &v[v.size()-2],l,r,x,z);
			
		}
		pll query(ll ver , nodo *a , ll l , ll r , ll i , ll j)
		{
			if(ver > -1 && ver < v.size())
			a = &v[ver];
			if(a == NULL)
			{
				return pll(0,0);
			}
			if(j < l || i >= r)
			{
				return pll(0,0);
			}
			else if(i <= l && r-1 <= j)
			{
				return pll(a->v,a->vv);
			}
			else
			{
				ll m = (l+r)/2;
				pll x , y;
				if(a->l != NULL)
					x = query(-1,a->l,l,m,i,j);
				if(a->r != NULL)
					y = query(-1,a->r,m,r,i,j);
				if(x.xx < x.yy)
					swap(x.xx,x.yy);
				if(x.xx < y.xx)
					swap(x.xx,y.xx);
				if(x.xx < y.yy)
					swap(x.xx,y.yy);
				if(x.yy < y.xx)
					swap(x.yy,y.xx);
				if(x.yy < y.yy)
					swap(x.yy,y.yy);
				return pll(x.xx,x.yy);
			}
		}
		ll vr()
		{
			return v.size()-1;
		}
};

int main()
{_C
	ll n , q , a, b;
	char c;
	cin >> n;
	vll v(n);
	STP stp;
	For(o,n)
	{
		cin >> v[i];
		stp.updateV(1,n+1,i+1,v[i]);
	}
	cin >> q;
	pll ans;
	while(q--)
	{
		cin >> c >> a >> b;
		if(c == 'Q')
		{
			ans = stp.query(stp.vr(),NULL,1,n+1,a,b);
			cout << ans.xx + ans.yy << '\n';
		}
		else
			stp.updateV(1,n+1,a,b);
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}



