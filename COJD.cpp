#include <bits/stdc++.h>
#define NOP 20		//Number Of Fathers
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
struct nodo
{
	int lv;
	set<int>Fx;
	vector<pair<int,int>>Pb;
	nodo()
	{
		lv = 0;
		Pb.assign(NOP,0);
	}
};

class tree
{
	private:
		vector<nodo> v;
		int root;
	public:	
	tree(int n)
	{
		v.assign(n,nodo());
		root = 0;
	}
	tree(int n , int r)
	{
		v.assign(n,nodo());
		root = r;
		v[r].Pb[0] = r;
	}
	void conect(int x , int y)
	{
		v[x].Fx.insert(y);
		v[y].Fx.insert(x);
		v[y].Pb[0] = x;
	}
	void LV(int x , int l , int p)
	{
//		cout << x << " , " << l << '\n';
		v[x].lv = l;
		set<int>::iterator it;
		for(it = v[x].Fx.begin() ; it != v[x].Fx.end() ; it++)
			if(*it != p)
				LV(*it , l + 1 , x);
	}
	void BinaryP()
	{
		for(int i = 1 ; i < NOP ; i++)
			for(int j = 0 ; j < v.size() ; j++)
				v[j].Pb[i] = v[v[j].Pb[i-1]].Pb[i-1];
	}
	int LCA(int x , int y)
	{
		int dif = abs(v[x].lv - v[y].lv);
		int p1 , p2;
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
			for(int i = 0 ; (1<<i) <= dif ; i++)
			{
				if(((1<<i)&dif) != 0)
					p1 = v[p1].Pb[i];
			}
		}
//		cout << p1 << " , " << p2 << " PS\n";
		if(p1 == p2)
			return p1;
		else
		{
			for(int i = NOP - 1 ; i >= 0 ; i--)
			{
		//		cout << v[p1].Pb[i] << " , " << v[p2].Pb[i] << " FIND\n";
				if(v[p1].Pb[i] != v[p2].Pb[i])
				{
					p1 = v[p1].Pb[i];
					p2 = v[p2].Pb[i];
				}
			}
			return v[p1].Pb[0];
		}
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n , q , a , b;
	cin >> n;
	tree tr(n);
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a;
		for(int j = 0 ; j < a ; j++)
		{
			cin >> b;
			tr.conect(i,b);
		}
	}
	tr.LV(0,0,0);
	tr.BinaryP();
	cin >> q;
	for(int i = 0 ; i < q ; i++)
	{
		cin >> a >> b;
		cout << tr.LCA(a,b) << '\n';
	}
	return 0;
}