#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 2000000
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
	for(ll i = 3 ; i < nSize ; i += 2)
	{
		if(bs[i] == 0)
			v.push_back(i);
		for(ll j = i*i ; j < nSize ; j += i)
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

int main()
{_C
	criba();
	ll a , b , x;
	while(cin >> a >> b)
	{
		vll z(a+1);
		map<ll,ll> f;
		for(int i = 1 ; i <= a ; i++)
			z[i] = i;
	//	cout << "ZZ\n";
		for(int i = 0 ; v[i] <= a ; i++)
		{
			x = 0;
			for(int j = v[i] ; j <= a ; j += v[i])
			{
				while(z[j]%v[i] == 0)
				{
					x++;
					z[j]/=v[i];
				}
			}
			f[v[i]] = x;
		}
	//	cout << "ZZ\n";
		vpll f2 = factorizacion(b);
		ll mn = 0;
		ll k = 0;
		bool flag = true;
		while(flag == true)
		{
			for(int i = 0 ; i < f2.size() ; i++)
			{
				if(f[f2[i].xx] - f2[i].yy >= 0)
				{
					f[f2[i].xx] -= f2[i].yy;	
				}else
					flag = false;
			}
			if(flag == true)
				mn++;
		}
		ld dg = 0;
		for(int i = 1 ; i <= a ; i++)
		{
			dg += (log10((ld)i));
		}
		dg /= log10((ld)b);
		//cout << (ll)floor(dg) << " Z\n";

		cout << mn << ' ' << ((ll)floor(dg))+1 << '\n';

	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}