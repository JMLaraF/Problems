#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector < ll	> vi;


class Disjoinset
{
	private:
		vi p , rank;
	public:
		Disjoinset(ll n)
		{
			rank.assign(n , 0);
			for(ll i = 0 ; i < n ; i++)
			{
				p.push_back(i);
			}
		}

		ll getSet(ll x)
		{
			return (p[x] == x)? x : (p[x] = getSet(p[x]));
		}

		bool buscar (ll x , ll y)
		{
			return getSet(x) == getSet(y);
		}

		bool unir(ll i , ll j)
		{
			ll x = getSet(i) , y = getSet(j);
			if(x != y)
			{
				p[x] = y;
				return true;
			}
			return false;
		}
};

int main()
{
	ll n , m , a , b;
	cin >> n >> m;
	Disjoinset ds(n);
	ll c = 0;
	while(m--)
	{
		cin >> a >> b;
		if(ds.unir(a-1,b-1))
			c++;
	}
	cout << c << '\n';
	return 0;
}