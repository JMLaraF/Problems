#include <bits/stdc++.h>

using namespace std;


int xs , ys , xa , ya;
int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int DFS(vector<string> &mp , char t , int x , int y)
{
	int a = 1;
	mp[y][x] = 5;
	for(int i = 0 ; i < 4 ; i++)
	{
		int xi = x + mov[i][1];
		int yi = y + mov[i][0];
		if(xi < 0)
			xi = xs-1;
		if(xi == xs)
			xi = 0;
		if(yi < 0 || yi >= ys)
			continue;
		if(mp[yi][xi] == t)
			a += DFS(mp,t,xi,yi);	
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(0);
	while(cin >> ys >> xs)
	{
//		cout << xs << " , " << ys << '\n';
		vector<string> mp(ys);
		for(int i = 0 ; i < ys ; i++)
		{
			cin >> mp[i];
		}
		cin >> ya >> xa;
//		cout << xa << " , " << ya << '\n';
		char t = mp[ya][xa];
		int ans = 0;
		DFS(mp,t,xa,ya);
		for(int i = 0 ; i < ys ; i++)
		{
			for(int j = 0 ; j < xs ; j++)
			{
				if(mp[i][j] == t)
				{
					ans = max(ans,DFS(mp,t,j,i));
				}
			}
		}
		cout << ans << '\n';
	}
}