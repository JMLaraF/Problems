#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

struct point
{
	ld x , y;
	point(){x=0;y=0;}
	point(ld a , ld b){x=a;y=b;}
	point(const point &p){x = p.x; y = p.y;}
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

	bool operator <(const point &p2) { return ((x < p2.x) || (x == p2.x && y < p2.y));}
	bool operator <=(const point &p2) { return ((x < p2.x) || (x == p2.x && y <= p2.y));}
	bool operator >(const point &p1) { return ((p1.x < x) || (p1.x == x && p1.y < y));}
	bool operator >=(const point &p1) { return ((p1.x < x) || (p1.x == x && p1.y <= y));}
	ld operator %(const point &p1) {return (x*p1.x + y*p1.y);}
	ld operator ^(const point &p1) {return ((x*p1.y) - (y*p1.x));}

	ld dist(const point p){return hypot(p.x - x , p.y - y);}
	struct point &scale(const ld s){x *= s; y *= s; return *this;}
	ld norm_sq() {return x*x + y*y;}
	double mgt(){return sqrt(norm_sq());}

};

struct line
{
	point p1 , p2;

	line(point _p1 , point _p2)
	{
		p1 = (_p1 <= _p2)? _p1 : _p2;
		p2 = (_p1 <= _p2)? _p2 : _p1;
	}

	ld dist_pto(point p)
	{
		line lx(p1,p2);
		lx.p2 -= lx.p1;
		p -= lx.p1;
		lx.p1 -= lx.p1;
		ld u = (lx.p2 % p) / (lx.p2.norm_sq());
		point px;
		
		px += lx.p2.scale(u);
		return px.dist(p);
	}
};

// Overloading operators

point operator +(point p1 , const point &p2) {return p1 += p2;} 
point operator -(point p1 , const point &p2) {return p1 -= p2;}

bool sortpoints(const point &p1 , const point &p2) { return ((p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y));}

int main()
{
	int t , k , q = -1 , w = 0;;
	string inst , ax;
	cin >> t;
	while(t--)
	{
		cin >> k;
		vector<point> v;
		double sx = 0, sy = 0 ,  theta = 0;
		for(int i = 0 ; i < k ; i++)
		{
			cin >> inst >> ax;
			if(ax == "?")
			{
				if(inst == "lt")
				{
					q = 1;
					w = v.size();
				}else if (inst == "rt")
				{
					q = -1;
					w = v.size();	
				}else
				{
					q = 0;
				}
			}else
			{
				double a = atof(ax.c_str());
				if(inst == "fd")
				{
					v.push_back(point(sx,sy));
					sx += a*cos(theta);
					sy += a*sin(theta);
					
				}else if (inst == "bk")
				{
					v.push_back(point(sx,sy));
					sx -= a*cos(theta);
					sy -= a*sin(theta);
					
				}else if(inst == "lt")
				{
					theta += a*PI/180;
					if(theta > 2*PI) {theta -= 2*PI;}
				}else
				{
					theta -= a*PI/180;
					if(theta < 0) {theta += 2*PI;}
				}
		//		cout << "X = " << sx << " , Y = " << sy << " , Theta = " << theta << '\n';
			}	
		}
		v.push_back(point(sx,sy));
		if(q == 0)
		{
			double ans = sqrt(sx*sx+sy*sy);
			cout << (ll)round(ans) << '\n';
		}else
		{
			point a , b;
			a -= v[w];
			b = v[v.size() - 1] - v[w];
			ld pp = b^a;
			ld theta = a%b/(a.mgt()*b.mgt());
			if(abs(theta - 1) <= 0.00000001)
				theta = 0;
			else if (theta == 0)
				theta = 0.5*PI;
			else if (abs(1 + theta) <= 0.00000001)
				theta = PI;
			else
				theta = acos(theta);
			
			theta *= 180/PI;
		//	cout << a.x << " , " << a.y << " <> " << b.x << " , " << b.y << '\n';
		//	cout << a.mgt() << " , " << b.mgt() << '\n';
		//	cout << theta << " Signo = " << pp << '\n';
			if(pp >= 0 && q == 1)
			{
				cout << (ll)round(theta)%360 << '\n';
			}
			else if(pp < 0 && q == 1)
			{
				cout << (360 - (ll)round(theta))%360 << '\n';
			}
			else if(pp >= 0 && q == -1)
			{
				cout << (360 - (ll)round(theta))%360 << '\n';
			}
			else if(pp < 0 && q == -1)	
			{
				cout << (ll)round(theta)%360 << '\n';
			}
		}


	}	
	return 0;
}