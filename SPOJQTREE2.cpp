#include <bits/stdc++.h>
#define NOP 25		//Number Of Fathers
#define xx first
#define yy second
using namespace std;
typedef pair<long long,long long> pii;
struct nodo
{
	long long lv;
	long long ch;
	set<pii>Fx;
	vector<pii>Pb;
	nodo()
	{
		lv = 0;
		ch = 0;
		Pb.assign(NOP,pii(0,0));
	}
};

		long long root , n;

class tree
{
	private:
		vector<nodo> v;

	public:	
	tree(long long n)
	{
		v.assign(n,nodo());
		root = 0;
	}
	tree(long long n , long long r)
	{
		v.assign(n,nodo());
		root = r;
		v[r].Pb[0].xx = r;
	}
	void conect(long long x , long long y , long long z)
	{
		v[x].Fx.insert(pii(y,z));
		v[y].Fx.insert(pii(x,z));
	}
	void Centroide(long long x , long long p)
	{
		bool c = true;
		set<pii>::iterator it;
		for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
		{
			if(it->xx != p)
			{
				Centroide(it->xx , x);
				v[x].ch += v[it->xx].ch + 1;
				if(v[it->xx].ch > n/2)
					c = false;
			}
		}
		if(c)
			root = x;
	}
	void LV(long long x , long long l , long long p)
	{
//		cout << x << " , " << l << '\n';
		v[x].lv = l;
		set<pii>::iterator it;
		for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
		{
			if(it->xx != p)
			{
				v[it->xx].Pb[0].xx = x;
				v[it->xx].Pb[0].yy = it->yy;
				LV(it->xx , l + 1 , x);
			}
		}
	}
	void BinaryP()
	{
		for(long long i = 1 ; i < NOP ; i++)
		{
			for(long long j = 0 ; j < v.size() ; j++)
			{
				v[j].Pb[i].xx = v[v[j].Pb[i-1].xx].Pb[i-1].xx;
				v[j].Pb[i].yy = v[j].Pb[i-1].yy + v[v[j].Pb[i-1].xx].Pb[i-1].yy;
			}
		}
	}
	long long LCA(long long x , long long y)
	{
		long long dif = abs(v[x].lv - v[y].lv);
		long long p1 , p2;
		long long s = 0;
		if(v[x].lv > v[y].lv)
		{
			p1 = x;
			p2 = y;
		}
		else
		{
			p1 = y;
			p2 = x;
		}
//		cout<< '\n' << dif << " , " << p1 << " , " << p2 << " DIF\n";
		if(dif > 0)
		{
			for(long long i = 0 ; ((long long)1<<i) <= dif ; i++)
			{
				if(((1<<i)&dif) != 0)
				{
					s += v[p1].Pb[i].yy;
					p1 = v[p1].Pb[i].xx;
				}
			}
		}
//		cout << p1 << " , " << p2 << " , " << s << " PS\n";
		if(p1 == p2)
			return s;
		else
		{
			for(long long i = NOP - 1 ; i >= 0 ; i--)
			{
//				cout << v[p1].Pb[i].xx << " , " << v[p2].Pb[i].xx << " , " << s <<  " FIND\n";
				if(v[p1].Pb[i].xx != v[p2].Pb[i].xx)
				{
					s += v[p1].Pb[i].yy;
					s += v[p2].Pb[i].yy;
					p1 = v[p1].Pb[i].xx;
					p2 = v[p2].Pb[i].xx; 
				}
			}
			s += v[p1].Pb[0].yy;
			s += v[p2].Pb[0].yy;
			return s;
		}
	}
	long long LCAP(long long x , long long y , long long z)
	{
		if(z == 0)
			return x;
		long long dif = abs(v[x].lv - v[y].lv);
		long long p1 , p2;
		long long s = 0;
		if(v[x].lv > v[y].lv)
		{
			p1 = x;
			p2 = y;
		}
		else
		{
			p1 = y;
			p2 = x;
		}
//		cout<< '\n' << dif << " , " << p1 << " , " << p2 << " DIF\n";
		if(dif > 0)
		{
			for(long long i = 0 ; ((long long)1<<i) <= dif ; i++)
			{
				if(((1<<i)&dif) != 0)
				{
					s += pow(2,i);
					p1 = v[p1].Pb[i].xx;
				}
			}
		}
//		cout << p1 << " , " << p2 << " , " << s << " PS\n";
		if(p1 != p2)
		{
			for(long long i = NOP - 1 ; i >= 0 ; i--)
			{
//				cout << v[p1].Pb[i].xx << " , " << v[p2].Pb[i].xx << " , " << s <<  " FIND\n";
				if(v[p1].Pb[i].xx != v[p2].Pb[i].xx)
				{
					s += 2*pow(2,i);
					p1 = v[p1].Pb[i].xx;
					p2 = v[p2].Pb[i].xx; 
				}
			}
			p1 = v[p1].Pb[0].xx;
			s += 2;		
		}
//		cout << s << " <S\n";
		if(z >= s)
			return y;
		if(z > v[x].lv-v[p1].lv)
		{
			s -= v[x].lv-v[p1].lv;
			z -= v[x].lv-v[p1].lv;
			x = y;
			for(long long i = 0 ; ((long long)1<<i) <= s ; i++)
			{
				if(((1<<i)&(s-z)) != 0)
				{
					x = v[x].Pb[i].xx;
				}
			}
		}else
		{
			for(long long i = 0 ; (1<<i) <= s ; i++)
			{
				if(((1<<i)&z) != 0)
				{
					x = v[x].Pb[i].xx;
				}
			}
		}
		
		return x;	
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t , q , a , b , c;
	string s;
	cin >> t;
	while(t--)
	{
		root = 0;
		cin >> n;
		if(n > 0)
		{
			tree tr(n);
			for(long long i = 1 ; i < n ; i++)
			{
				cin >> a >> b >> c;
				tr.conect(--a,--b,c);
			}
			tr.Centroide(0,0);
			tr.LV(root,0,root);
			tr.BinaryP();
			cin >> s;
			while(s != "DONE")
			{
				if(s == "DIST")
				{
					cin >> a >> b;
					cout << tr.LCA(--a,--b) << '\n';
				}else
				{
					cin >> a >> b >> c;
					cout << tr.LCAP(--a,--b,--c) + 1 << '\n';
				}
				cin >> s;
			}
			if(t > 0)
				cout << '\n';
		}
	}
	return 0;
}