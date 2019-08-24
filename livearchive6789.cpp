#include <bits/stdc++.h>


using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

ll days(vector<ll> &v , ll m , ll &x , ll &y)
{
	x = 0;
	y = 0;
//	cout << "M = " << m << '\n';
	ll i = 0 , j = 1 , c = 0;
	for(int i = 0 ; i < v.size() && i <= j ; i++)
	{
	//	cout << "QQ " << (v[j]-v[i]) << '\n';
		while((v[j]-v[i]) <= m)
		{
			if(v[j]-v[i] >= v[y]-v[x])
			{
				x = i;
				y = j;
			}
			j++;
			if(j == v.size())
				break;
		}
		j--;
//		cout << "dif>  " << j << " . " << i << '\n';
		c += j-i;
	}
	return c;
}

bool sortpoints(const pll &p1 , const pll &p2) { return (((p1.second-p1.first) < (p2.second - p2.first)) || (((p1.second-p1.first) == (p2.second - p2.first)) && p1.first < p2.first));}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n , k , x=0 , xx , y=0 , yy;
	cin >> n >> k;
	while(!( n == 0 && k == 0))
	{
		vector<ll> v(n);
		for(int i = 0 ;i < n; i++)
			cin >> v[i];
		sort(v.begin() , v.end());
//		for(int i = 0 ;i < n; i++)
//			cout << v[i] << ' ';
		ll l = 0 , r = 5000000000 , m , d;
		while(l < r)
		{
			m = (l+r)/2;
			d = days(v,m,x,y);
	//		cout << d << " <D " << l << " <l" << " , " << r << "\n";
			if(d >= k)
			{
				xx = m;
				yy = d;
				r = m;
			}
			else
				l = m+1;
		}

	vpll ans;
//	cout << "xx = " << xx << " ,yy = " << yy <<  '\n';
	ll i = 0 , j = 1 , c = 0;
	for(int i = 0 ; i < v.size() && c < yy ; i++)
	{
		j = i + 1;
		while(j < v.size() && (v[j]-v[i]) <= xx)
		{
			ans.push_back(pll(v[i] , v[j]));
			j++;
		}
		j--;
		c += j-i;
	}
	sort(ans.begin() , ans.end() , sortpoints);
//	for(int i = 0 ; i < ans.size() ; i++)
//		cout << ans[i].first << " , " << ans[i].second << '\n'; 
		cout << ans[k-1].first << ' ' << ans[k-1].second << '\n';
		cin >> n >> k;
	}
	return 0;
}