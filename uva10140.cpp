#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 50000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

vll v;
vector<short> bs(nSize , 0);

void criba()
{
	ll z = INF;
	for(ll i = 2 ; i < nSize ; i++ , z++)
	{
		if(bs[i] == 0)
		{
			v.push_back(i);
			z = 0;
		}
		for(ll j = i*i ; j < nSize ; j += i)
			bs[j] = 1;		
	}
}

int main()
{_C
	criba();
	ll x , y , z , w  , q , mx = 0 , mn = INF;
	bool d = false;
	while(cin >> x >> y)
	{
		if(x == 1)
			x++;
		mx = 0;
		mn = INF;
		vpll p;
		z = -1;
		while(x <= y)
		{
			z++;
			d = false;
			for(int i = 0 ; v[i]*v[i] <= x && d == false  ; i++)
			{
				if(x%v[i] == 0)
				{
					d = true;
				}
			}
			if(d == false)
			{
				p.push_back(pll(x,z));
				if(p.size() > 1)
				{
					if(z > mx)
					{
						mx = z;
						w = p.size() - 1;
					}
					if(z < mn)
					{
						mn = z;
						q = p.size() - 1;
					}
				}
				z = 0;
			}
			x++;
		}		
			



	if(p.size() < 2)
		cout << "There are no adjacent primes.\n";
	else
		cout << p[q-1].xx <<"," << p[q].xx <<" are closest, " << p[w-1].xx << "," << p[w].xx << " are most distant.\n";


	}
//	cout << v.size() << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}