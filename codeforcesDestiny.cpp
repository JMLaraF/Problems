#include <bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair < int , int > pii;
typedef pair < int , pii > trii;
struct CMP
{
	bool operator()(const pair < int , trii > lpii , const pair < int , trii > rpii)
	{
		if(lpii == rpii)
			return false;
		return ((lpii.yy.yy.yy < rpii.yy.yy.yy)||((lpii.yy.yy.yy == rpii.yy.yy.yy) && (lpii.xx < rpii.xx))); 
	}
};

typedef set < pair < int , trii >  > setQ;

int mp[500005];

int main()
{
	int n , q , a , b , k;
	cin >> n;
	vector < int > v(n);
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	cin >> q;
	int sq = sqrt(n) , sqq = n/sq;
	vector <setQ> query(sqq + 1);
	vector <int> ans(q);
	for(int i = 0 ; i < q ; i++)
	{
		cin >> a >> b >> k;
		a--;
		b--;
		if(a == 0 && b == 0)
		{
			ans[i] = v[0];
		}else
		{
			if(a > b)
			swap(a,b);
			query[a/sqq].insert(make_pair(i,trii( k ,pii(a,b))));
		}
	}

	int l = 0 , r = 0 , c = 0;
	set < int > pq;

	
	setQ::reverse_iterator rit;
	for(int i = query.size() - 1 ; i >= 0  ; i--)
	{
		for(rit = query[i].rbegin() ; rit != query[i].rend() ; rit++)
		{
	//		cout << rit->yy.xx << " , " << rit->yy.yy << '\n';
			while(r != rit->yy.yy.yy)
			{
				if(r < rit->yy.yy.yy)
				{
					r++;
					cb[v[r]]++;
					if(cb[v[r]] > floor((rit->yy.yy.yy - rit->yy.yy.xx + 1)/rit->yy.xx))
					{
						pq.insert(v[r]);
					}
				}else
				if(r > rit->yy.yy.yy)
				{
					cb[v[r]]--;
					if(cb[v[r]] <= floor((rit->yy.yy.yy - rit->yy.yy.xx + 1)/rit->yy.xx))
					{
						pq.erase(v[r]);
					}
					r--;
				}	
			}
			while(l != rit->yy.xx)
			{
				if(l < rit->yy.xx)
				{
					cb[v[l]]--;
					if(cb[v[l]] <= floor((rit->yy.yy - rit->yy.xx + 1)/rit->yy.xx))
					{
						pq.erase(v[l]);
					}
					l++;
				}else
				if(l > rit->yy.xx)
				{
					l--;
					cb[v[l]]++;
					if(cb[v[l]] > floor((rit->yy.yy - rit->yy.xx + 1)/rit->yy.xx))
					{
						pq.insert(v[l]);
					}
				}
			}
			ans[rit->xx] = *pq.begin();
		}
	}
	for(int i = 0 ; i < q ; i++)
		cout << ans[i] << '\n';

	return 0;
}