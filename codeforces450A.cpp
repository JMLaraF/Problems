
#include <bits/stdc++.h>
#define xx first
#define yy second
using namespace std;


int main()
{
	
	queue<pair<int , int> > q;
	int n , m , a;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a;
		q.push(make_pair(a,i+1));
	}
	int x = 1;
	while(!q.empty())
	{
		x = q.front().yy;
		if(q.front().xx-m > 0)
			q.push(make_pair(q.front().xx-m,q.front().yy));
		q.pop();	
	}
	cout << x << '\n';

}