#include <bits/stdc++.h>
#define INF (int)10e8
using namespace std;

typedef pair < int , int > pll;

int q[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int m , n;

void Dijkstra (vector < vector < int > > &v , vector < vector < int > > &d)
{
	int x , y , xi , yi;
	priority_queue <pair < int , pll > > pq;
	pq.push(make_pair(d[0][0] , pll (0,0)));
	while(!pq.empty())
	{
		x = pq.top().second.first;
		y = pq.top().second.second;
		pq.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			xi = x + q[i][0];
			yi = y + q[i][1]; 
			if(xi < 0 || yi < 0 || xi >= m || yi >= n)
				continue;
			if(d[yi][xi] > d[y][x] + v[yi][xi])
			{
				d[yi][xi] = d[y][x] + v[yi][xi];
				pq.push(make_pair(-d[yi][xi] , pll (xi,yi)));	
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		vector < vector < int > > v(n , vector < int > (m));
		vector < vector < int > > d(n , vector < int > (m,INF));
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				cin >> v[i][j];
			}
		}
		d[0][0] = v[0][0];
		Dijkstra(v , d);
			cout << d[n-1][m-1] << '\n';
	}

	return 0;
}