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

int main()
{_C
	vll v(255,0);
	string a , b , c;
	cin >> a >> b >> c;
	if(a.size() + b.size() != c.size())
	{
		cout << "NO\n";
		return 0;
	}
	for(int i = 0 ; i < c.size() ; i++) 
		v[c[i]]++;
	for(int i = 0 ; i < b.size() ; i++)
	{
		v[b[i]]--;
		if(v[b[i]] < 0)
		{
			cout << "NO\n";
			return 0;
		}
	}
	for(int i = 0 ; i < a.size() ; i++)
	{
		v[a[i]]--;
		if(v[a[i]] < 0)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}