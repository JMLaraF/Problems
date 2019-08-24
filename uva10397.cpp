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
	int n , m , x , y;
	while(cin >> n)
	{
		vector <pll> pts(n);
		vector <pair <double , pll> > EdgeList;
		double dist;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> x >> y;
			pts[i] = pll(x,y);
		}
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = i + 1 ; j < n ; j++)
			{
				dist = sqrt((abs(pts[i].first - pts[j].first))*(abs(pts[i].first - pts[j].first)) + (abs(pts[i].second - pts[j].second)) * (abs(pts[i].second - pts[j].second)));
				EdgeList.push_back(pair < double , pll > (dist,pll(i,j)));
			}
		}
		sort(EdgeList.begin() , EdgeList.end());
		Disjoinset ds(n);
		cin >> m;
		for(int i = 0 ; i < m ; i++)
		{
			cin >> x >> y;
			ds.unir(x-1,y-1);
		}
		double s = 0;
		for(int i = 0 ; i < EdgeList.size() ; i++)
		{
			if(ds.unir(EdgeList[i].second.first , EdgeList[i].second.second))
				s += EdgeList[i].first;
		}
		cout << fixed << setprecision(2) << s << '\n';
	}

}