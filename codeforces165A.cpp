#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

struct flags
{
	vector<bool> f;
	flags(){f.assign(4,false);}
};

int main()
{_C
	ll n , a , b;
	cin >> n;
	vector< pair<pll,flags> > v; 
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a >> b;
		v.push_back(pair<pll,flags>(pll(a,b) , flags()));
	}
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i+1 ; j < n ; j++)
		{
			if(v[j].xx.xx > v[i].xx.xx && v[i].xx.yy == v[j].xx.yy)
			{
				v[i].yy.f[0] = true;
				v[j].yy.f[1] = true;
			}
			if(v[j].xx.xx < v[i].xx.xx && v[i].xx.yy == v[j].xx.yy)
			{
				v[i].yy.f[1] = true;
				v[j].yy.f[0] = true;
			}
			if(v[j].xx.yy > v[i].xx.yy && v[i].xx.xx == v[j].xx.xx)
			{
				v[i].yy.f[2] = true;
				v[j].yy.f[3] = true;
			}
			if(v[j].xx.yy < v[i].xx.yy && v[i].xx.xx == v[j].xx.xx)
			{
				v[i].yy.f[3] = true;
				v[j].yy.f[2] = true;
			}
		}
	}
	int c = 0;
	for(int i = 0 ; i < n ; i++)
	{
		bool obj = true; 
		for(int j = 0 ; j < 4 ; j++)
		{ 
			obj &= v[i].yy.f[j];
		}
		c += (obj)? 1 : 0;
	}
	cout << c << '\n';
	return 0;
}