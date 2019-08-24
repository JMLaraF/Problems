#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
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
{_C
	ll t;
	cin >> t;
	cout << "INTERSECTING LINES OUTPUT\n";
	while(t--)
	{
		point p1 , p2 , p3 , p4;
		ld a , b , c , d , e , f , g , x , y;
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
		line l1(p1-p1,p2-p1) , l2(p3-p1,p4-p1);
	//	cout << l1.p1.x << " , " << l1.p1.y << " , " << l1.p2.x << " , " << l1.p2.y << " l2 " << l2.p1.x << " , " << l2.p1.y << " , " << l2.p2.x << " , " << l2.p2.y << '\n';
		if(((l1.p2 - l1.p1)^(l2.p2 - l2.p1)) == 0)
		{
//			cout << "DS " << l1.dist_pto(l2.p2);
			if(!l1.dist_pto(l2.p2))
				cout << "LINE\n";
			else
				cout << "NONE\n";
		}else
		{
			a = p1.x*p2.y-p1.y*p2.x;
			b = p3.x*p4.y-p3.y*p4.x;
			c =	(p1.x-p2.x)*(p3.y-p4.y)-(p3.x-p4.x)*(p1.y-p2.y);
			d = (p1.x-p2.x);
			e = (p3.x-p4.x);
			f = (p1.y-p2.y);
			g = (p3.y-p4.y);
			x = (a*e-b*d)/c;
			y = (a*g-b*f)/c;
			if(x == -0)
				x = 0;
			if(y == -0)
				y = 0;
			cout << fixed << setprecision(2) << "POINT " << x << ' ' << y << '\n';
		}
	}
	cout << "END OF OUTPUT\n";	
	return 0;
}
