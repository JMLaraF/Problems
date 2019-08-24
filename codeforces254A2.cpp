#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

struct punto
{
	int x , y;
	punto()
	{
		x = 0;
		y = 0;
	}
	punto(int _x , int _y)
	{
		x = _x;
		y = _y;
	}
};

bool f(const punto &p1 , const punto &p2)
{
	return ((p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y));
}

int main()
{
	ofstream myout;
	fstream myfile;
	myfile.open("input.txt");
	myout.open("output.txt");
	int n;
	myfile >> n;
	vector<punto> v(2*n);
	for(int i = 0 ; i < (2*n) ; i++)
	{
		myfile >> v[i].x;
		v[i].y = i+1;
	}

	sort(v.begin(),v.end(),f);
	vector<punto> ans;
	for(int i = 0 ; i < 2*n ; i+=2)
	{
		if((v[i].x != v[i+1].x))
		{
			myout << "-1\n";
			myout.close();
			myfile.close();
			return 0;
		}
		ans.push_back(punto(v[i].y,v[i+1].y));
	}
	for(int i = 0 ; i < ans.size() ; i++)
		myout << ans[i].x << ' ' << ans[i].y << '\n';
	myfile.close();
	myout.close();
	return 0;
}