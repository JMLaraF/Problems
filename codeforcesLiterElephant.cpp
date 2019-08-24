#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long long,long long> pii;
struct CPM
{
	bool operator()(const pair < long long ,pii >& lhs, const pair < long long ,pii >& rhs)
	{
		if(lhs == rhs)
			return false;
		else
        	return (lhs.second.second < rhs.second.second)||((lhs.second.second == rhs.second.second)&&(lhs.first < rhs.first)); 
    }
};

unordered_map<long long , long long >cb; 


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<long long , bool> uso;
	long long n , sqn , nn , q , a , b;
	cin >> n >> q;
	vector<long long> v(n);
	for(long long i = 0 ; i < n ; i++)
	{
		cin >> a;
		v[i] = a;
	}
	double sqq = sqrt(n);
	double qn = ceil((double)n/sqq);

	vector<long long> ans(q);
	vector< set<pair < long long ,pii>,CPM> > qs(qn + 1);
	for(long long i = 0 ; i < q ; i++)
	{
		cin >> a >> b;
		if(a > b)
			swap(a,b);
		pii paux (a-1,b-1);
	//	cout << paux.first << " |,| " << qn << '\n';
	//	cout << (long long)((double)paux.first/qn) << '\n';
		qs[(long long)floor((double)paux.first/qn)].insert(make_pair(i,paux));
	}
	set<pair < long long ,pii > ,CPM>::iterator it;
	long long l = 0 , r = 0 , c = 0;

	cb[v[0]]++;

	if(v[0] == 1)
	{
		uso[1] = true;
		c++;
	}

	for(long long i = qs.size() - 1 ; i >= 0 ; i--)
	{
		for(it = qs[i].begin() ; it != qs[i].end() ; it++)
		{
	//		cout << it->second.first << " , " << it->second.second << '\n';
			while(r != it->second.second)
			{
				if(r < it->second.second)
				{
					r++;
					cb[v[r]]++;
					if(cb[v[r]] == v[r] && !uso[v[r]])
					{
						uso[v[r]] = true;
						c++;
					}
					if(cb[v[r]] != v[r] && uso[v[r]])
					{
						uso[v[r]] = false;
						c--;
					}
					
				}
				if(r > it->second.second)
				{
					cb[v[r]]--;
					if(cb[v[r]] != v[r] && uso[v[r]])
					{
						uso[v[r]] = false;
						c--;
					}
					if(cb[v[r]] == v[r] && !uso[v[r]])
					{
						uso[v[r]] = true;
						c++;
					}
					r--;
				}
				
			}while(l != it->second.first)
			{
				if(l > it->second.first)
				{
					l--;
					cb[v[l]]++;
					if(cb[v[l]] == v[l] && !uso[v[l]])
					{
						uso[v[l]] = true;
						c++;
					}
					if(cb[v[l]] != v[l] && uso[v[l]])
					{
						uso[v[l]] = false;
						c--;
					}
				}
				if(l < it->second.first)
				{
					cb[v[l]]--;
					if(cb[v[l]] != v[l] && uso[v[l]])
					{
						uso[v[l]] = false;
						c--;
					}
					if(cb[v[l]] == v[l] && !uso[v[l]])
					{
						uso[v[l]] = true;
						c++;
					}
					l++;	
				}
			}
			ans[it->first] = c;
		}	
	}
	for(long long i = 0 ; i < ans.size() ; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}