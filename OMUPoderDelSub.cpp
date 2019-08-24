#include <bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

struct CMP
{
	bool operator()(const pair < ll , pll > lpll , const pair < ll , pll > rpll)
	{
		if(lpll == rpll)
			return false;
		else
			return ((lpll.yy.yy < rpll.yy.yy)||((lpll.yy.yy == rpll.yy.yy)&&(lpll.xx < rpll.xx)));	
	}
};

typedef set < pair < ll , pll > , CMP > setMO;


int cb[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n , q , sq , a , b , c = 0;
	pll paux;
	cin >> n >> q;
	sq = sqrt(n);
	ll sqq = n/sq;
	vector <ll> v(n);
	vector <ll> ans(q);
	vector< setMO > query(sqq + 1);
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	for(int i = 0 ; i < q ; i++)
	{
		cin >> a >> b;
		if(a > b)
			swap(a,b);
		paux.xx = --a;
		paux.yy = --b;
		c = a/sqq;
		query[c].insert(make_pair(i,pll(a,b)));
	}
	c = 0;
	ll l = 0 , r = 0 ;
	cb[v[0]]++;
	c += cb[v[0]]*cb[v[0]]*v[0];

	setMO::reverse_iterator it;
	for(int i = query.size() - 1 ; i >= 0 ; i--)
	{
		for(it = query[i].rbegin() ; it != query[i].rend() ; it++)
		{
//			cout << it->yy.xx << " , " << it->yy.yy << '\n';
			while(r != it->yy.yy)
			{
				if(r < it->yy.yy)
				{
					r++;
					c -= cb[v[r]]*cb[v[r]]*v[r];
					cb[v[r]]++;
					c += cb[v[r]]*cb[v[r]]*v[r];
				}if(r > it->yy.yy)
				{
					c -= cb[v[r]]*cb[v[r]]*v[r];
					cb[v[r]]--;
					c += cb[v[r]]*cb[v[r]]*v[r];
					r--;
				}
			}
			while(l != it->yy.xx)
			{
				if(l < it->yy.xx)
				{
					c -= cb[v[l]]*cb[v[l]]*v[l];
					cb[v[l]]--;
					c += cb[v[l]]*cb[v[l]]*v[l];
					l++;
				}
				if(l > it->yy.xx)
				{
					l--;
					c -= cb[v[l]]*cb[v[l]]*v[l];
					cb[v[l]]++;
					c += cb[v[l]]*cb[v[l]]*v[l];
				}
			}
			ans[it->xx] = c;
		}
	}

	for(int i = 0 ; i < q ; i++)
		cout << ans[i] << '\n';
	return 0;
}