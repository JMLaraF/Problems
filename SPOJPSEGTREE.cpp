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
	ll v;
	struct nodo *l , *r;
	nodo()
	{
		v = 0;
		l = NULL;
		r = NULL;
	}
	nodo(const struct nodo *n)
	{
		if(n!= NULL)
		{
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
				if(b == NULL)
					a->v = z;
				else
					a->v = b->v+z;
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
				ll x = 0 , y = 0;
				if(a->l != NULL)
					x = a->l->v;
				if(a->r != NULL)
					y = a->r->v;
				a->v = x+y;
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
	*/	void updateV(ll vv , ll l , ll r , ll x , ll z)
		{
			v.push_back(nodo(&v[vv]));
			update(&v[v.size()-1] , &v[vv],l,r,x,z);
			
		}
		ll query(ll ver , nodo *a , ll l , ll r , ll i , ll j)
		{
			if(ver > -1 && ver < v.size())
			a = &v[ver];
			if(a == NULL)
			{
				return 0;
			}
			if(j < l || i >= r)
			{
				return 0;
			}
			else if(i <= l && r-1 <= j)
			{
				return a->v;
			}
			else
			{
				ll m = (l+r)/2 , x = 0 , y = 0;
				if(a->l != NULL)
					x = query(-1,a->l,l,m,i,j);
				if(a->r != NULL)
					y = query(-1,a->r,m,r,i,j);
				return x+y;
			}
		}
		ll vr()
		{
			return v.size()-1;
		}
};


int main()
{_C
	ll n , q , a , b, c , d;
	cin >> n;
	STP stp;
	For(o,n)
	{
		cin >> a;
		stp.updateV(stp.vr() , 1,n+1,i+1,a);
	}
	cin >> q;
	while(q--)
	{
		cin >> a >> b >> c >> d;
		if(a == 1)
		{
			stp.updateV(n+b,1,n+1,c,d);
		}else
			cout << stp.query(n+b,NULL,1,n+1,c,d) << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}