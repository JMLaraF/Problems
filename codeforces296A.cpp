#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

bool fn(vll &v , ll i)
{
	if(i >= v.size()-1)
	{
		return false;
	}
	if(v[i] == v[i+1])
	{
		return fn(v,i+1);
	}
	else
	{
		swap(v[i],v[i+1]);
	}
	return true;
}

bool fm(vll &v , ll i)
{
	if(i <= 0)
	{
		return false;
	}
	if(v[i] == v[i-1])
	{
		return fm(v,i-1);
	}
	else
	{
		swap(v[i],v[i-1]);
	}
	return true;
}
/*
void pf(vll &v)
{
	for(int j = 0 ; j < v.size() ; j++)
		cout << v[j] << ((j == v.size()-1)?'\n':' ');
}
*/
int main()
{_C
	ll n;
	cin >> n;
	vll v(n);
	For(o,n)
		cin >> v[i];
	ll i = 0; 
	bool flag = true;
	while(i < n-1)
	{
		if(v[i] == v[i+1])
		{
			flag &= fn(v,i+1);
	//		pf(v);
			if(!flag)
				break;
		}else
			i++;
	}
	if(!flag)
	{
		i = v.size()-1;
		flag = true;
		while(i > -1)
		{
			if(v[i] == v[i-1])
			{
				flag &= fm(v,i-1);
//				pf(v);
				if(!flag)
					break;
			}else
			i--;
		}
	}
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}