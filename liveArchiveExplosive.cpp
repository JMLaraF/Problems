#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < ll , ll > pll;


class Disjoinset
{
		private:
		map < ll , ll > p , c , rank;
		public:
		Disjoinset()
		{
		}
		void insert(ll x)
		{
			if(!p.count(x))
			{
				c[x] = 0;
				rank[x] = 0;
				p[x] = x;
			}
		}

		ll getSet(ll x)
		{
			return ((p[x] == x)? x : (p[x] = getSet(p[x])));
		}
		bool buscar (ll x , ll y)
		{
			return getSet(x) == getSet(y);
		}
		bool unir(ll i , ll j)
		{
			if(!buscar(i,j))
			{
				ll x = getSet(i) , y = getSet(j);
				if(rank[x] > rank[y])
				{
					p[y] = x;
					c[x] += c[y] + 1;
				}else
				{
					p[x] =  y;
					c[y] += c[x] + 1;
					if(rank[x] == rank[y])
						rank[y]++;
				}
				return true;
			}
			return false;
		}
};

int main()
{
	ll a , b;
	cin >> a;
	while(cin >> b)
	{
		Disjoinset ds;
		ll c = 0;
		do
		{
			ds.insert(a);
			ds.insert(b);
			if(!ds.unir(a , b))
				c++;
			cin >> a;
			if(a != -1)
				cin >> b;
		}while(a != -1);
		cout << c << '\n';
		cin >> a;
	}
	return 0;
}