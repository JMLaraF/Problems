#include <bits/stdc++.h>

using namespace std;

int n;
 
int pasos[8][2] = {{0,-1},{-1,0},{1,0},{0,1}};

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
		for(int i = 0 ; i < 4 ; i++)
		{
			if(ac.first + pasos[i][1] < 0)
				continue;
			if(ac.second + pasos[i][0] < 0)
				continue;
			if(ac.first + pasos[i][1] >= n)
				continue;
			if(ac.second + pasos[i][0] >= n)
				continue;
			if(mp[ac.first + pasos[i][1]][ac.second + pasos[i][0]] == '@' || mp[ac.first + pasos[i][1]][ac.second + pasos[i][0]] == 'x')
				cola.push(make_pair(ac.first + pasos[i][1] , ac.second + pasos[i][0]));
		}
	}
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);

	int casos;
	cin >> casos;

	for(int k = 1 ; k <= casos ; k++)
	{
		cin >> n;
		getchar();
		int t = 0;
		vector < string > mp(n);
		for(int i = 0 ; i < n ; i++)
		{
			getline(cin,mp[i]);
		}
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				if(mp[i][j] == 'x')
				{
					BFS(mp,j,i);
					t++;
				}
			}
		}
		cout << "Case " << k << ": " << t << "\n";
		
	}
	return 0;
}