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
	ll f;
	ll lv;
	struct nodo *c1;
	struct nodo *c2;
	struct nodo *c3;
	struct nodo *c4;
	struct nodo *p;
	nodo()
	{
		f = 0;
		lv = 0;
		c1 = NULL;
		c2 = NULL;
		c3 = NULL;
		c4 = NULL;
		p = NULL;
	}

};

class Graph
{
	private:
		nodo *ac;
		nodo root;
	public:
	Graph()
	{
		root = nodo();
		ac = &root;

		nodo *n1 = new nodo();
		nodo *n2 = new nodo();
		nodo *n3 = new nodo();
		nodo *n4 = new nodo();
		n1->p = &root;
		n2->p = &root;
		n3->p = &root;
		n4->p = &root;

		root.c1 = n1;
		root.c2 = n2;
		root.c3 = n3;
		root.c4 = n4;
	}
	void getRoot()
	{
		ac = &root;
	}
	void addNode()
	{
		if(ac->c1 == NULL)
		{
			nodo *n1 = new nodo();
			nodo *n2 = new nodo();
			nodo *n3 = new nodo();
			nodo *n4 = new nodo();
			n1->p = ac;
			n2->p = ac;
			n3->p = ac;
			n4->p = ac;

			ac->c1 = n1;
			ac->c2 = n2;
			ac->c3 = n3;
			ac->c4 = n4;
		}
	}

	void goDeep(ll a)
	{
		switch(a)
		{
			case 1:
			if(ac->c1 != NULL)
				ac = ac->c1;
			break;
			case 2:
			if(ac->c2 != NULL)
				ac = ac->c2;
			break;
			case 3:
			if(ac->c3 != NULL)
				ac = ac->c3;
			break;
			case 4:
			if(ac->c4 != NULL)
				ac = ac->c4;
			break; 
		}
	}
	void goUp()
	{
		if(ac->p != NULL)
			ac = ac->p;
	}
	void fill_white()
	{
		if(ac->f != 1)
			ac->f = -1;
	}
	void fill_black()
	{
		ac->f = 1;
	}
	ll count(ll px , nodo *s)
	{
		if(s == NULL)
			return 0;
		if(s->f == 1)
		{
			return px;
		}
		else
			return (count((ll)(px/4) , s->c1) + count((ll)(px/4) , s->c2) + count((ll)(px/4) , s->c3) + count((ll)(px/4) , s->c4));
	}
	ll count()
	{
		return count(1024,&root);
	}
};

void fz(Graph &p , string s , ll &i)
{
	if(i == 0)
	{
		if(s[i] == 'f')
		{
			p.fill_black();
			return;
		}
		else if(s[i] == 'e')
		{
			p.fill_white();
			return;
		}
		i++;
	}
	
	for(int z = 1 ; z <= 4 ;z++)
	{
		if(s[i] == 'p')
		{
			p.goDeep(z);
			p.addNode();
			i++;
			fz(p,s,i);
		}
		else if(s[i] == 'e')
		{
			p.goDeep(z);
			p.fill_white();
			p.goUp();
			i++;
		}else
		{
			p.goDeep(z);
			p.fill_black();
			p.goUp();
			i++;
		}
	}
	p.goUp();
}

int main()
{_C
	ll n;
	cin >> n;
	while(n--)
	{
		Graph p;
		string s1 , s2;
		cin >> s1 >> s2;
		ll i = 0;
		fz(p,s1,i);
		p.getRoot();
		i = 0;
		fz(p,s2,i);
		cout << "There are " << p.count() << " black pixels.\n";
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}