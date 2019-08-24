#include <bits/stdc++.h>
using namespace std;

struct q
{
	int a , b , c ;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n , m , a , b , l , r , cont = 0;
	q aux;
	cin >> n;
	vector < int > v(n);
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i];
	}
	cin >> m;
	vector<int> ans(m);
	vector < q > query;
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a >> b;
		aux.a = a-1;
		aux.b = b-1;
		aux.c = i;
//		if(a > b)
//			swap(a,b);
		query.push_back(aux);
	}
	sort(query.begin() , query.end() , [](auto &left , auto &right)
	{
		return ((left.a < right.a) || (left.a == right.a && left.b < right.b));
	});


	map < int , int > ct;
	l = query[0].a;
	r = query[0].b;
	for(int	i = l ; i <= r ; i++)
	{
		if(ct.count(v[i]) == 1)
		{
			ct[v[i]]++;
		}
		else
		{
			ct[v[i]] = 1;
			cont++;
		}
	}
	a = l;
	b = r;
	ans[query[0].c] = cont;
	for(int i = 1 ; i < m ; i++)
	{

		l = query[i].a;
		r = query[i].b;
		
		if(b < r)
		{
			for(int	j = b+1 ; j <= r ; j++)
			{
				if(ct.count(v[j]) != 0)
				{
					ct[v[j]]++;
				}
				else
				{
					ct[v[j]] = 1;
					cont++;
				}
			}
		}else
		if(b > r)
		{
			for(int j = b ; j > r ; j--)
			{
				if(ct[v[j]] == 1)
				{
					ct.erase(v[j]);
					cont--;
				}
				else
				{
					ct[v[j]]--;
				}
			}
		}
		if(l > a)
		{
			for(int j = a ; j < l ; j++)
			{
				if(ct[v[j]] == 1)
				{
					ct.erase(v[j]);
					cont--;
				}
				else
				{
					ct[v[j]]--;
				}
			}
		}


		ans[query[i].c] = cont;
		a = l;
		b = r;
	}
	for(int i = 0 ; i < m ; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}