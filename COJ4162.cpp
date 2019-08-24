#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


struct Dpoint
{
	ld x , y , z;
	Dpoint():x(0),y(0),z(0){}
	Dpoint(ld _x , ld _y , ld _z):x(_x),y(_y),z(_z){}

	struct Dpoint cruz(const Dpoint &p2)
	{
		return Dpoint((y*p2.z-z*p2.y),(z*p2.x-x*p2.z),(x*p2.y-y*p2.x)); 
	}
	ld dot(const Dpoint &p2)
	{
		return (x*p2.x)+(y*p2.y)+(z*p2.z);
	} 
	
};



int main()
{_C
	ll n;
	cin >> n;
	vector<Dpoint> v(n);
	forn
		cin >> v[i].x >> v[i].y >> v[i].z;
	if(n < 4)
		cout << "TAK\n";
	else
	{
		for(int i = 1 ; i < v.size() ; i++)
		{
			v[i].x-=v[0].x;
			v[i].y-=v[0].y;
			v[i].z-=v[0].z;
		}
		ll j = -1;
		Dpoint Vaux;
		for(int i = 2 ; i < v.size() && j == -1 ; i++)
		{
			Vaux = v[1].cruz(v[i]);
			if(fabs(Vaux.x+Vaux.y+Vaux.z) > ERR)
			{
				j = i;
			}
		}	
		if(j == -1)
		{
			cout << "TAK\n";
			return 0;
		}	
		Vaux = v[1].cruz(v[j]);
		for(int i = 3 ; i < v.size() ; i++)
		{
			if(fabs(Vaux.dot(v[i])) > ERR)
			{
				cout << "NIE\n";
				return 0;
			}
		}
		cout << "TAK\n";
	}


	return 0;
}