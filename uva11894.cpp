#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

struct point
{
	ll x , y;
	point(){x=0;y=0;}
	point(ll a , ll b){x=a;y=b;}
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
	ll t , n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<point> male(n);
		vector<point> female(n);
		for(int i = 0 ; i < n ; i++)
		{
			cin >> male[i].x >> male[i].y;
		}
		for(int i = 0 ; i < n ; i++)
		{
			cin >> female[i].x >> female[i].y;
		}


		sort(male.begin() , male.end() , sortpoints);
		sort(female.begin() , female.end() , sortpoints);
		bool ans = true;
		for(int i = n-1 ; i >= 0 ; i--)
		{
			male[i] -= male[0];
			female[i] -= female[0];
			ans &= male[i] == female[i];

		}
		int k = 3;
		while(k-- && ans == false)
		{
			ans = true;
			ll aux;
			for(int i = 0 ; i < n ; i++)
			{
				aux = male[i].x;
				male[i].x = -male[i].y;
				male[i].y = aux;
			}
			sort(male.begin() , male.end() , sortpoints);
			for(int i = n-1 ; i >= 0 ; i--)
			{
				male[i] -= male[0];
				ans &= male[i] == female[i];
//				cout << "M1 = " << male[i].x << " , " << male[i].y << "\tM2 = " << female[i].x << " , " << female[i].y << '\n';
			}
		}
		cout << ((ans)?"MATCHED\n" : "NOT MATCHED\n");

	}
	return 0;
}