#include <bits/stdc++.h>

using namespace std;

int n , m , x , y;
char c2;

int pasos[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};

void DFS(vector < string > &mp , int x , int y , int &t)
{

	t++;
	mp[y][x] = 253;

	int xa , ya ;
	for(int i = 0 ; i < 4 ; i++)
	{
		xa = (x + pasos[i][0]) % n;
		ya = (y + pasos[i][1]) % m;

		if(xa < 0)
			xa = n-1;
		if(ya < 0)
			ya = m-1;
		if(mp[ya][xa] == c2)
			DFS(mp,xa,ya,t);
	}
	return;
}

void DFS2(vector < string > &mp , int x , int y )
{
	int xa , ya ;
	mp[y][x] = 253;
	for(int i = 0 ; i < 4 ; i++)
	{
		xa = (x + pasos[i][0]) % n;
		ya = (y + pasos[i][1]) % m;
		if(xa < 0)
			xa = n-1;
		if(ya < 0)
			ya = m-1;
		if(mp[ya][xa] == c2)
			DFS2(mp,xa,ya);
	}
	return;
}

int main()
{
	
	while(cin >> m >> n)
	{
		getchar();
		vector < string > mp(m);
		for(int i = 0 ; i < m ; i++)
		{
			cin >> mp[i];
		}

		cin >> y >> x;
		c2 = mp[y][x];

		DFS2(mp,x,y);
/*
		for(int i = 0 ; i < m ; i++)
		{
			cout << mp[i] << " C\n";
		}
*/
		int ans = 0;
		for(int i = 0 ; i < m ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				int a = 0;
				if(mp[i][j] == c2)
				{
//					cout << "ent\n";
					DFS(mp,j,i,a);
				}
				ans = max(ans , a);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}