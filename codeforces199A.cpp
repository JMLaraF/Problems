#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define For(i,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	vll v(2);
	v[0] = 0;
	v[1] = 1;
	ll n = 50 , z;
	cin >> z;
	For(i,n)
	{
		v.push_back(v[i]+v[i+1]);
	}
	for(int i = 0 ; i < v.size() ; i++)
	{
		for(int j = 0 ; j < v.size() ; j++)
		{
			for(int k = 0 ; k < v.size() ; k++)
			{
				if(v[i]+v[j]+v[k] == z)
				{
					cout << v[i] << ' ' << v[j] << ' ' << v[k] << '\n';
					return 0;
				}
			}
		}
	}
	cout << "I'm too stupid to solve this problem\n";	

	return 0;
}