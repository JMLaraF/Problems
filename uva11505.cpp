#include <bits/stdc++.h>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
using namespace std;
typedef long long ll;

struct punto
{
	double x , y , z;
	punto(){x = 0 ; y = 0;}
	punto(double a , double b , double c){x = a; y = b; z = c;}
};



int main()
{
	int t , k , q = -1 , w = 0;;
	string inst , a;
	cin >> t;
	while(t--)
	{
		cin >> k;
		vector<punto> v;
		double sx = 0, sy = 0, ssx , ssy ,  theta = 0 
		for(int i = 0 ; i < k ; k++)
		{
			cin >> inst >> a;
			if(a == '?')
			{
				if(inst == "lt" || inst == "rt")
				{
					q = 1
					w = i;
				}else
				{
					q = 0;
				}
			}else
			{
				if(inst == "fd")
				{
					sx += a*cos(theta);
					sy += a*sin(theta);
					v.push_back(punto(sx,sy,theta));
				}else if (inst == "bk")
				{
					sx -= a*cos(theta);
					sy -= a*sin(theta);
					v.push_back(punto(sx,sy,theta));
				}else if(inst == "lt")
				{
					theta += a*PI/180;
				}else
				{
					theta += (2*PI-a*PI/180);
				}
	//			cout << "X = " << sx << " , Y = " << sy << " , Theta = " << theta << '\n';
			}	
		}
		if(q == 0)
		{
			double ans = sqrt(sx*sx+sy*sy);
			cout << (ll)round(ans) << '\n';
		}else
		{
			int i = -1;
			double dist;
			while(abs(v[v.size() - 1].x) >= 0.000001 && abs(v[v.size() - 1].y) >= 0.000001 )
			{
				i++;
				for(int j = w ; j < v.size() - 1 ; j++)
				{
					dist = round(sqrt( (v[j+1].x-v[j].x) * (v[j+1].x-v[j].x) + (v[j+1].x-v[j].y) * (v[j+1].x-v[j].y) ));
					v[j].z += i*PI/180;
					v[j+1].x = v[j].x + dist*cos(v[j].z);
					v[j+1].y = v[j].y + dist*sin(v[j].z);
					v[j+1].z += (j-w+1)*i*PI/180;
				}
			}
			cout << i << '\n';
		}


	}	
	return 0;
}