#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

struct point
{
	double x , y;
	point():x(0.0),y(0.0){};
	point(const point &p):x(p.x),y(p.y){};

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
	double operator %(const point &p1) { return (x*p1.x + y*p1.y);}
	bool operator <=(const point &p2){return (x < p2.x) || (x == p2.x && y <= p2.y);}
	double norm_sq(){return x*x + y*y;}
	double dist(const point p){return hypot(p.x - x , p.y - y);}
	struct point &scale(const double s){x *= s; y *= s; return *this;}

};

struct line
{
	point p1,p2;
	line():p1(point()),p2(point()){};
	line(point _p1 , point _p2)
	{
		p1 = (_p1 <= _p2)? _p1 : _p2;
		p2 = (_p1 <= _p2)? _p2 : _p1;
	}

	double dist_pto(point p)
	{
		line lx(p1,p2);
		lx.p2 -= lx.p1;
		p -= lx.p1;
		lx.p1 -= lx.p1;
		if(fabs(lx.p2.norm_sq()) <= ERR)
			return sqrt(p.norm_sq());
		double u = (lx.p2 % p) / (lx.p2.norm_sq());
		point px;

		px += lx.p2.scale(u);
		return px.dist(p);
	}

};


int main()
{_C
	point han;
	ll n;
	cin >> n >> han.x >> han.y;
	vector<point> v(n);
	vll x(n,0);
	ll ans = 0;
	forn
		cin >> v[i].x >> v[i].y;
	forn
	{
		if(x[i] == 1)
			continue;
		line laux(han,v[i]);
		ans++;
		for(int j = i+1 ; j < n ; j++)
		{
	//		cout << laux.dist_pto(v[j]) << '\n';
			if(laux.dist_pto(v[j]) <= ERR)
				x[j] = 1;
		}
	}
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}