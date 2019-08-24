#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 3500
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

vpll factorizacion(ll x)
{
	ll i = 0 , z;
	vpll ans;
	while(x > 1 && i < v.size())
	{
		z = 0;
		while(x%v[i] == 0)
		{
			z++;
			x /= v[i];
		}
		if(z > 0)
			ans.push_back(pll(v[i],z));
		i++;
	}
	if(x > 1)
		ans.push_back(pll(x,1));
	return ans;
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

int main()
{_C
	criba();
	ll n , a , c;
	cin >> n;
	bool d = false;
	while(n--)
	{
		d = true;
		cin >> a >> c;
		vpll v1 = factorizacion(a);
		vector<bool> ap(v1.size() , false);
		vpll v2 = factorizacion(c);
		ll j = 0;
		ll ans = 1;
		for(int i = 0 ; i < v2.size() ; i++)
		{
			if(j < v1.size())
			{
				if(v1[j].xx < v2[i].xx)
				{
					i--;
					j++;
				}else if(v1[j].xx == v2[i].xx)
				{
					ap[j] = true;
					if(v1[j].yy > v2[i].yy)
						d = false;
					else if(v1[j].yy < v2[i].yy)
						ans *= pot(v2[i].xx,v2[i].yy);
				}else
					ans *= pot(v2[i].xx,v2[i].yy);
			}else
				ans *= pot(v2[i].xx,v2[i].yy);
		}
		for(int i = 0 ; i < ap.size() ; i++)
			d &= ap[i];
		if(d == true)
			cout << ans << '\n';
		else
			cout << "NO SOLUTION\n";
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}