#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll cont = 0;

struct nodo
{
	ll val , pt;
	set < ll > Fx;
	nodo()
	{
		val = -1;
		pt = -1;
	}
};

bool BFS (vector < nodo > &nodos , ll x , vector < ll > &v)
{
	queue < ll > cola;
	cola.push(x);
	ll ac = -1 , p = -1;
	bool bi = true;
	set< ll >::iterator it;
	nodos[x].val = 0;
	v[0]++;
	while(!cola.empty())
	{
		p = ac;
		ac = cola.front();
		cola.pop();
		for(it = nodos[ac].Fx.begin() ; it != nodos[ac].Fx.end() ; it++)
		{
//			cout << ac << " , " << *it << " , " << p << '\n';
			if(nodos[*it].val == -1)
			{
				cola.push(*it);
				nodos[*it].val = (nodos[ac].val + 1)%2;
				nodos[*it].pt = ac;
				v[(nodos[ac].val + 1)%2]++;
			}else
			if(nodos[*it].val != -1 && (*it) != nodos[ac].pt && nodos[ac].val == nodos[*it].val)
			{
				bi = false;
				break;
			}
		}
		if(bi == false)
			break;

	}
	return bi;
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n , m ,  a , b;
	cin >> m;
	while(m--)
	{
		cin >> n;
		vector<nodo> arbol(n);
		vector<ll> v(2,0);
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			while((a--) > 0)
			{
				cin >> b;
				if(b > n)
					arbol.resize(b);
				arbol[i].Fx.insert(b-1);
				arbol[b-1].Fx.insert(i);
//				cout << a << '\n';
			}
		}
		ll ac = 0;
		for(int i = 0 ; i < n ; i++)
		{
			if(arbol[i].val == -1)
			{
				bool bi = BFS(arbol,i,v);
//				cout << bi << " , " << v[0] << " , " << v[1] << '\n'; 
				if(bi)
				ac += max(v[0],v[1]);
				v[0] = 0;
				v[1] = 0;

			}	
		}
		ac = min(ac,(long long)n);
		cout << ac << '\n';
	}
	return 0;
}

