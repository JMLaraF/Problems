#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

struct point
{
	double x , y;
	point(){x=0;y=0;}
	point(double a , double b){x=a;y=b;}
	struct point &operator +=(const point &p2) 
	{
		x += p2.x;
		y += p2.y;
		return *this;
	}
	struct point &operator -=(const point &p2) 
	{
		x -= p2.x;
		y -= p2.y;
		return *this;
	}
	bool operator ==(const point &p2)
	{
		return (x == p2.x && y == p2.y);
	}
};

// Overloading operators
point operator +(point p1 , const point &p2) {return p1 += p2;} 
point operator -(point p1 , const point &p2) {return p1 -= p2;}
bool sortpoints(const point &p1 , const point &p2) { return ((p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y));}


int main()
{_C
	point p1 , p2 , p3 , p4;
	double a;
	while(cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y)
	{
		if(p3 == p1)
		{
			p2 -= p1;
			p4 -= p1;
			p2 += p4;
			p2 += p1;
			cout << fixed << setprecision(3) << p2.x << ' ' << p2.y << '\n';
		}else if(p3 == p2)
		{
			p1 -= p2;
			p4 -= p2;
			p1 += p4;
			p1 += p2;
			cout << fixed << setprecision(3) << p1.x << ' ' << p1.y << '\n';
		}else if(p4 == p1)
		{
			p2 -= p1;
			p3 -= p1;
			p2 += p3;
			p2 += p1;
			cout << fixed << setprecision(3) << p2.x << ' ' << p2.y << '\n';
		}else if(p4 == p2)
		{
			p1 -= p2;
			p3 -= p2;
			p1 += p3;
			p1 += p2;
			cout << fixed << setprecision(3) << p1.x << ' ' << p1.y << '\n';
		}
		
	}
	return 0;
}