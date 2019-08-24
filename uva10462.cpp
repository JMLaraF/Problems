#include <bits/stdc++.h>
#define INF 999999999999
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector <ll> vll;


class Disjoinset
{
	private:
		vll p , r;
	public:
		Disjoinset(ll n)
		{
			r.assign(n , 0);
			for(int i = 0 ; i < n ; i++)
				p.push_back(i);
		}

		ll getSet(ll x)
		{
			return (p[x] == x)? x : (p[x] = getSet(p[x]));
		}

		bool buscar (ll x , ll y)
		{
			return getSet(x) == getSet(y);
		}

		bool unir (ll i , ll j)
		{
			ll x = getSet(i) , y = getSet(j);
			if(x == y)
				return false;
			else
			{
				if(r[x] > r[y])
					p[y] = x;
				else
				{
					p[x] = y;
					if(r[x] == r[y])
						r[y]++;
				}
			}
			return true;
		}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t , n , m , a , b , c;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		cin >> n >> m;
		vector < pair <ll , pll> > EdgesList;
		for(int i = 0 ; i < m ; i++)
		{
			cin >> a >> b >> c;
			EdgesList.push_back(make_pair(c,pll(a-1,b-1)));
		}
		sort(EdgesList.begin() , EdgesList.end());
		ll s1 = 0;
		set<ll>sset;
		ll dd1 = n;
		Disjoinset ds1(n);
		for(int i = 0 ; i < m ; i++)
		{
			if(ds1.unir(EdgesList[i].second.first , EdgesList[i].second.second))
			{
				s1 +=  EdgesList[i].first;
				sset.insert(i);
				dd1--;
			}
		}
		ll s2 = INF; 
		for(int i = 0 ; i < m ; i++)
		{
			Disjoinset ds(n);
			ll s = 0;
			ll dd = n;
			set<ll>sst;
			for(int j = 0 ; j < m ; j++)
			{
				if(j != i)
				{
					if(ds.unir(EdgesList[j].second.first , EdgesList[j].second.second))
					{
						s +=  EdgesList[j].first;
						sst.insert(j);
						dd--;
					}
				}
			}
			if(dd == 1 && sset != sst)
				s2 = min(s2,s);
		}
		cout << "Case #" << k << " : ";
		if(dd1 != 1)
			cout << "No way\n";
		else
		{
			if(s2 == INF)
				cout << "No second way\n";
			else
				cout << s2 << '\n';
		}	 
	}
	return 0;
}