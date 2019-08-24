#include <bits/stdc++.h>

using namespace std;

vector <int> resueltos(100005,0);

struct nodo
{
	int val;
	set <int > Fx;
	nodo()
	{
		val = 0;
	}
};

bool topo(vector <nodo> &grafo , vector < int > &orden , int x , set<int> &mt)
{
	if(grafo[x].val == 1)
	{
		return true;
	}
	grafo[x].val = 1;
	bool bd = false;
	if(grafo[x].Fx.empty())
	{
		orden.push_back(x);
	}
	else
	{
		set < int >::iterator it;
		while(!grafo[x].Fx.empty())
		{
			it = grafo[x].Fx.begin();
			if(resueltos[*it] == 0)
			{
				bd |= topo(grafo,orden,*it, mt);
			}
			grafo[x].Fx.erase(*it);
		}
		orden.push_back(x);
	}
	if(mt.count(x))
			mt.erase(x);
	resueltos[x] = 1;
	grafo[x].val = 0;
	return bd;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n , k , a , b;
	cin >> n >> k;
	vector<nodo> grafo(n);
	vector < int > orden;
	set < int > materias;
	for(int i = 0 ; i < k ; i++)
	{
		cin >> a;
		materias.insert(a-1);
	}
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a;
		for(int j = 0 ; j < a ; j++)
		{
			cin >> b;
			grafo[i].Fx.insert(b-1);
		}
	}
	bool bd = false;
	set<int>::iterator it;
	while(!materias.empty() && bd == false)
	{
		it = materias.begin();
		bd |= topo(grafo,orden,*it,materias);
	}

	if(orden.size() > 0 && bd == false)
	{
	cout << orden.size() << '\n';
		for(int i = 0 ; i < orden.size() ; i++)
		{
			cout << orden[i] + 1;
			if(i < orden.size() - 1)
				cout << ' ';
			else
				cout << '\n';
		}
	}else
		cout << "-1\n";
	return 0;
}