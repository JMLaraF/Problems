#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 10000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

vll v;
bitset<nSize> bs;
void criba()
{
	bs[1] = 1;
	bs[0] = 1;
	for(int i = 2 ; i < nSize ; i++)
	{
		if(bs[i] == 0)
			v.push_back(i);
		for(int j = i*i ; j < nSize ; j += i)
		{
			bs[j] = 1;
		}
	}
}

ll numDiv(ll N)
{
		ll PF_idx = 0, PF = v[PF_idx], ans=1;
		
		while(PF*PF <= N)
		{
			ll power=0;
			while(N%PF==0)
			{
				N/=PF;
				power++;
			}
			ans*=(power+1);
			PF=v[++PF_idx];
		}
		if(N!=1)
		{
			ans*=2;
		}
		return ans;
}

int main()
{_C
	criba();
	ll t ,a , b , c;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		c = 0;
		bool z = false;
		for(ll i = a ; i <= b ; i++)
		{
			if(bs[numDiv(i)]==0)
			{
				c++;
				if(z == true)
					cout << " ";
				else
					z = true;
				cout << i;
			}
		}
		if(c == 0)
			cout << "-1";
		cout << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}