#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	ll n , m , a;
	map<ll,vll> ady;
	cin >> n >> m;
	queue<ll> cola;
	vvll v(m,vll(3));
	vll b(n,-1);
	vll::iterator it;
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			cin >> v[i][j];
			v[i][j]--;
			ady[v[i][j]].pb(i);
		}
	}
	for(int i = 0 ; i < v.size(); i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			if(b[v[i][j]] == -1)
			{
				b[v[i][j]] = j;
				cola.push(v[i][j]);
			}
		}
		while(!cola.empty())
		{
			a = cola.front();
			cola.pop();
			for(it = ady[a].begin() ; it != ady[a].end() ; it++)
			{
				ll k = 1;
				for(int j = 0 ; j < 3 ; j++)
				{
					if(b[v[*it][j]] == -1)
					{
						b[v[*it][j]] = ((b[a]+k)%3);
						k++;
						cola.push(v[*it][j]);
					}
				}
			}
		}
	}
	
	for(int i = 0 ; i < b.size() ; i++)
		cout << b[i]+1 << ((i == b.size()-1)?'\n':' ');


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}