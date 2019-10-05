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
typedef double ld;
typedef pair<ld,ld> pld;
const ld PI = acos(-1);

struct line
{
	ld x0 , x1 , y0 , y1;
	line():x0(0.0),x1(0.0),y0(0.0),y1(0.0){}
	line(pld &p1 , pld &p2)
	{
		x0 = p1.xx;
		y0 = p1.yy;
		x1 = p2.xx;
		y1 = p2.yy;
	}
	line(ld _x0 , ld _y0 , ld _x1 , ld _y1)
	{
		x0 = _x0;
		y0 = _y0;
		x1 = _x1;
		y1 = _y1;
	}
	ld Pendiente()
	{
		return ((max(y0,y1)-min(y0,y1))/(max(x0,x1)-min(x0,x1)));
	}
};
struct circle
{
	ld x , y , r;
	circle():x(0.0),y(0.0),r(0.0){};
	circle(ld _x , ld _y , ld _r):x(_x),y(_y),r(_r){}
};

bool intersectionCircleLine(line &ln, circle &cl)
{
	ld dx = ln.x1-ln.x0;
	ld dy = ln.y1-ln.y0;
	ld x = ln.x0 - cl.x;
	ld y = ln.y0 - cl.y;
	ld ans = (cl.r*cl.r)*(dy*dy+dx*dx) - (dy*x-dx*y)*(dy*x-dx*y);
	return (ans < 0.0)? false : true;
}

bool intersectionCircleCircle(circle &a , circle &b)
{
	ld dis = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	if(dis > a.r+b.r || dis+min(a.r,b.r) < max(a.r,b.r))
		return false;
	return true;
}

struct Grafo
{
	vvll Fx;
	vll vis;
	Grafo(ll n)
	{
		Fx.assign(n,vll());
		vis.assign(n,0);
	}
	void join(ll x, ll y)
	{
		Fx[x].pb(y);
		Fx[y].pb(x);
	}
	bool DFS(ll x , ll p, ll y)
	{
		vis[x] = 1;
		if(x == y)
			return true;
		vll::iterator it;
		bool ans = false;
		for(it = Fx[x].begin() ; it != Fx[x].end() ; it++)
		{
			if(*it == p || vis[*it] > 0)
				continue;
			ans |= DFS(*it,x,y);
		}
		return ans;
	}
};


int main()
{_C
	ld n , m;
	ll k;
	cin >> n >> m >> k;
	vector<circle> v;
	Grafo g(k+2);
	while(k--)
	{
		ld x , y , r;
		cin >> x >> y >> r;
		v.pb(circle(x,y,r));
	}
	line l1(0.0 , 0.0 , n , 0.0);
	line l2(n , 0.0 , n , m);
	line l3(n , m , 0.0 , m);
	line l4(0.0 , m , 0.0 , 0.0);
	for(int i = 0 ; i < v.size() ; ++i)
	{
		if(intersectionCircleLine(l1,v[i]) || intersectionCircleLine(l2,v[i]))
			g.join(0,i+2);
		if(intersectionCircleLine(l3,v[i]) || intersectionCircleLine(l4,v[i]))
			g.join(1,i+2);
	}
	for(int i = 0 ; i < v.size() ; ++i)
	{
		for(int j = i+1 ; j < v.size(); ++j)
		{
			if(intersectionCircleCircle(v[i],v[j]))
				g.join(i+2,j+2);
		}
	}
	if(g.DFS(0,-1,1))
		cout << "N\n";
	else
		cout << "S\n";

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}