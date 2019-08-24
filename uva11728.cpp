#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 2000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

vll v;
void criba()
{
	bitset<nSize> bs;
	v.push_back(2);
	for(int i = 3 ; i < nSize ; i += 2)
	{
		if(bs[i] == 0)
			v.push_back(i);
		for(int j = i*i ; j < nSize ; j += i)
			bs[j] = 1;
	}
}

ll pot(ll a , ll b)
{
	ll x = 1;
	if(b == 0)
		return x;
	for(int i = 0 ; i < 63 ; i++)
	{
		if((((ll)1<<i)&b)!=0)
			x*=a;
		a*=a;
	}
	return x;
}


ll fsum(ll x)
{
	ll ans = 1 , i = 0 , z;
	while(x > 1 && i < v.size())
	{
		z = 0;
		while(x%v[i]==0)
		{
			z++;
			x /= v[i];
		}
		if(z > 0)
			ans *= (pot(v[i],z+1)-1)/(v[i]-1);
		i++;
	}
	if(x > 1)
		ans *= (pot(x,2)-1)/(x-1);
	return ans;
}

int main()
{_C
	criba();
	vll v(3000 , -1);
	for(int i = 1 ; i <= 1000 ; i++)
		v[fsum(i)] = i;
	ll n , c = 1;
	cin >> n;
	while(n != 0)
	{
		cout << "Case " << c++ << ": ";
		if(v[n] != -1)
			cout << v[n] << '\n';
		else
			cout << "-1\n";
		cin >> n;
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}