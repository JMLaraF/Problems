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

ll mod;

struct matriz
{
	vector<vll> v;
	matriz()
	{
		v.assign(0,vll(0,0));
	}
	matriz(ll a ,ll b)
	{
		v.assign(a , vll(b,0));
	}
};

matriz operator *(const matriz &m1 , const matriz &m2)
{
	if(m1.v.size() == 0 || m2.v.size() == 0)
	{
		return matriz();
	}
	else if(m1.v[0].size() != m2.v.size() )
	{
		return matriz();
	}
	else
	{
		matriz r(m1.v[0].size() , m2.v.size());
		for(int i = 0 ; i < m1.v.size() ; i++)
		{
			for(int j = 0 ; j < m2.v[0].size() ; j++)
			{
				ll z = 0;
				for(int k = 0 ; k < m2.v.size() ; k++)
				{
					z += (m1.v[i][k] * m2.v[k][j])%mod;
				}
				z = z%mod;
				r.v[i][j] = z;
			}
		}
		return r;		
	}
}

matriz pot(matriz &a , ll b)
{
	if(b == 0)
		return matriz();
	if(a.v.size() == 0)
		return matriz();
	matriz ans(a.v.size(),a.v[0].size());
	for(int i = 0 ; i < a.v.size() ; i++)
		ans.v[i][i] = 1;
	for(int i = 0 ; i < 63 ; i++)
	{
		if((((ll)1<<i)&b)!=0)
			ans = ans*a;
		a = a*a;
	}
	return ans;
}

int main()
{_C
	ll a , b;
	while(cin >> a >> b)
	{
		mod = (ll)1<<b;
		matriz m(2,2);
		m.v[0][0] = 1;
		m.v[0][1] = 1;
		m.v[1][0] = 1;
		m.v[1][1] = 0;
		if(a > 1)
		{
			m = pot(m,a);
			cout << m.v[0][1] << '\n';
		}else if(a == 1)
			cout << 1%mod << '\n';
		else
			cout << "0\n";

	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}