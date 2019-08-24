#include <bits/stdc++.h>

using namespace std;

int m , n;
 
int pasos[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

void BFS(vector < string > &mp , int x , int y)
{
//	int ct = 0;
	queue < pair < int , int > > cola;
	cola.push(make_pair(y,x));
	pair < int , int > ac;
	while(!cola.empty())
	{
		ac = cola.front();
		cola.pop();
		mp[ac.first][ac.second] = 'z';
//		ct++;
//		if(ct == 100)
//			return;
		for(int i = 0 ; i < 8 ; i++)
		{
			if(ac.first + pasos[i][1] < 0)
				continue;
			if(ac.second + pasos[i][0] < 0)
				continue;
			if(ac.first + pasos[i][1] >= m)
				continue;
			if(ac.second + pasos[i][0] >= n)
				continue;
			if(mp[ac.first + pasos[i][1]][ac.second + pasos[i][0]] == '@')
				cola.push(make_pair(ac.first + pasos[i][1] , ac.second + pasos[i][0]));
		}
	}
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);

	string s;
	cin >> m >> n;

	while(m > 0)
	{
		getchar();
		int t = 0;
		vector < string > mp(m);
		for(int i = 0 ; i < m ; i++)
		{
			getline(cin,mp[i]);
		}
		for(int i = 0 ; i < m ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				if(mp[i][j] == '@')
				{
					BFS(mp,j,i);
					t++;
				}
			}
		}
		cout << t << "\n";
		cin >> m >> n;
	}
	return 0;
}