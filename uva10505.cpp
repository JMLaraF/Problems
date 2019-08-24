#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair < int , int > pll;
struct nodo
{
	int color;
	set<int> Fx;
	nodo()
	{
		color = -1;
	}
};


pll BFS(vector<nodo> &v , int x)
{
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t , n , a , b;
	cin >> t;
	while(t--)
	{
		int ans = 0;
		cin >> n;
		vector<nodo> v(n,nodo());
		for(int i = 0 ; i < n ; i++)
		{
			cin >> a;
			for(int j = 0 ; j < a ; j++)
			{
				cin >> b;
				if(b <= n)
				{
					v[i].Fx.insert((b-1));
					v[b-1].Fx.insert(i);
				}
			}
		}

		for(int i = 0 ; i < n ; i++)
		{
			if(v[i].color == -1)
			{
				bool bip = true;
				int cont[2] = {0,0};

				queue< int > cola;
				cola.push(i);
				v[i].color = 0;
				cont[0]++;

				set<int>::iterator it;
				while(!cola.empty())
				{
					int aux = cola.front();
					cola.pop();
					for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
					{
						if(v[(*it)].color == -1)
						{
							v[(*it)].color = 1 - v[aux].color;
							cola.push((*it));
							cont[v[(*it)].color]++;
						}else if (v[(*it)].color == v[aux].color)
						{
							bip = false;
						}
					}
				}
				if(bip)
					ans += max(cont[0],cont[1]);
			}
			
		}
		cout << ans << '\n';
	}
	return 0;
}