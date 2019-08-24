#include <bits/stdc++.h>

using namespace std;
 
int pasos[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

void BFS(vector < string > &mp , int x , int y)
{
	queue < pair < int , int > > cola;
	cola.push(make_pair(y,x));
	pair < int , int > ac;
	while(!cola.empty())
	{
		ac = cola.front();
		cola.pop();
		mp[ac.first][ac.second] = 2;
		for(int i = 0 ; i < 8 ; i++)
		{
			if(ac.first + pasos[i][1] < 0)
				continue;
			if(ac.second + pasos[i][0] < 0)
				continue;
			if(ac.first + pasos[i][1] >= mp.size())
				continue;
			if(ac.second + pasos[i][0] >= mp.size())
				continue;
			if(mp[ac.first + pasos[i][1]][ac.second + pasos[i][0]] == '1')
				cola.push(make_pair(ac.first + pasos[i][1] , ac.second + pasos[i][0]));
		}
	}
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n , c = 0 ;
	string s;
	while(cin >> n)
	{
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
				if(mp[i][j] == '1')
				{
					BFS(mp,j,i);
					t++;
				}
			}
		}
		cout << "Image number " << ++c << " contains " << t << " war eagles.\n"; 
	}
	return 0;
}