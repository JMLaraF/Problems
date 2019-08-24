#include <bits/stdc++.h>

using namespace std;

typedef vector < long long > vi;
typedef pair < long long , long long > pii;

class Disjoinset
{
	private:
		vi p , c , rank;
	public:
		Disjoinset(long long n)
		{
			rank.assign(n , 0);
			c.assign(n , 0);
			for(long long i = 0 ; i < n ; i++)
			{
				p.push_back(i);
			}
		}
		long long findset(long long x)
		{
			return (p[x] == x)? x : (p[x] = findset(p[x]));
		}
		bool buscar(long long x , long long y)
		{
			return findset(x) == findset(y);
		}
		bool conect (long long i , long long j)
		{
			if(!buscar(i , j))
			{
				long long x = findset(i) , y = findset(j);
				if(rank[x] > rank[y])
				{
					p[y] = x;
					c[x] += c[y] + 1;
				}
				else
				{
					p[x] = y;
					c[y] += c[x] + 1;
					if(rank[x] == rank[y])
						rank[y]++;
				}
				return true;	
			}
			return false;
		}
		long long alcance (long long n)
		{
			long long x = findset(n);
			return c[x];
		}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t , n , m , c;
	string a , b;
	cin >> t;
	while(t--)
	{
		long long nd = 0 , mst_c = 0;
		map<string , long long > mp;
		pair < long long , pii > paux;
		vector < pair < long long , pii > > EdgeList;  
		cin >> n >> m;
		for(long long i = 0 ; i < m ; i++)
		{
			cin >> a >> b >> c;
			if(!mp.count(a))
			{
				mp[a] = nd++;
			}
			if(!mp.count(b))
			{
				mp[b] = nd++;
			}
			EdgeList.push_back(make_pair ( c , pii (mp[a] , mp[b])));
		}
		Disjoinset ds(n);
		sort(EdgeList.begin() , EdgeList.end() );

		for(long long i = 0 ; i < m ; i++)
		{
			paux = EdgeList[i];
			if(ds.conect(paux.second.first , paux.second.second))
			{
				mst_c += paux.first;
			}
		}
		cout << mst_c << '\n';
		if(t != 0)
			cout << '\n';
	}
	return 0;
}