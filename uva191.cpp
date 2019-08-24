#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define ERR 0.00000001
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
		return (fabs(x - p2.x) <= ERR && fabs(y - p2.y) <= ERR);
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

	line(){p1 = point() ; p2 = point();}

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
		if(fabs(lx.p2.norm_sq()) <= ERR)
			return sqrt(p.norm_sq());
		ld u = (lx.p2 % p) / (lx.p2.norm_sq());
		point px;
		
		px += lx.p2.scale(u);
		return px.dist(p);
	}
	int interSgSg(line ln)
	{
		point px = p2 , px2 = ln.p1;
		px -= p1;
		px2 -= p1;
		ld sg1 = (px ^ px2);
		px2 = ln.p2;
		px2 -= p1;
		ld sg2 = (px ^ px2);
		px = ln.p2;
		px -= ln.p1;
		px2 = p1;
		px2 -= ln.p1;
		ld sg3 = px ^ px2;
		px2 = p2;
		px2 -= ln.p1;
		ld sg4 = px ^ px2;
	//	cout << sg1 << " , " << sg2 << " , " << sg3 << " , " << sg4 << " SG\n";
		if(((sg1 > 0 && sg2 < 0) && ((sg3 >= 0 && sg4 <= 0) || (sg3 <= 0 && sg4 >= 0))) || ((sg1 < 0 && sg2 > 0) && ((sg3 >= 0 && sg4 <= 0) || (sg3 <= 0 && sg4 >= 0))) || ((sg1 == 0 || sg2 == 0) && ((sg3 > 0 && sg4 < 0) || (sg3 < 0 && sg4 > 0))))
			return 0;
		else if (sg1 < 0 && sg2 < 0)
			return 1;
		else if (sg1 > 0 && sg2 > 0)
			return -1;		
		else
			return -2;
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
	while(t--)
	{
		vector <line> rec(4);
		line ln;
		ld a , b , c , d , e , f , g , h;
		cin >> a >> b >> c >> d >> e >> f >> g >> h;

		ln.p1.x = a;
		ln.p1.y = b;
		ln.p2.x = c;
		ln.p2.y = d;

		if(e != g && f != h)
		{
			rec[0].p1.x = e;
			rec[0].p1.y = f;
			rec[0].p2.x = g;
			rec[0].p2.y = f;
			
			rec[1].p1.x = g;
			rec[1].p1.y = f;
			rec[1].p2.x = g;
			rec[1].p2.y = h;
			
			rec[2].p1.x = g;
			rec[2].p1.y = h;
			rec[2].p2.x = e;
			rec[2].p2.y = h;
			
			rec[3].p1.x = e;
			rec[3].p1.y = h;
			rec[3].p2.x = e;
			rec[3].p2.y = f;
			if(e > g)
				swap(e,g);
			if(f > h)
				swap(f,h);

			bool ans = false;
			for(int i = 0 ; i < 4 ; i++)
				ans |= (rec[i].interSgSg(ln) == 0)? true:false;
			ans |= (a >= e && a <= g && b >= f && b <= h && c >= e && c <= g && d >= f && d <= h);
			cout << ((ans)?"T\n":"F\n");
		}else
		{ 
			if(fabs(ln.dist_pto(point(e,f))) <= 0.0000001)
				cout << "T\n";
			else
				cout << "F\n";
		}
	
	}
	return 0;
}