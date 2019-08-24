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
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef unsigned long double ld;

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

ll Eulerphi(ll  N)
{
	ll PF_dix = 0 ;
	ll PF = v[PF_dix];
	ll ans = N;
	
	while(PF * PF <= N)
	{
		if(N % PF == 0) ans -= ans/ PF;
		while( N % PF == 0) N /= PF;
		PF = v[++PF_dix];
	}
	if(N!=1) ans -= ans/N;
	return ans;
}

int main()
{_C
	criba();
	ll n;
	cin >> n;
	while(n != 0)
	{
		cout << Eulerphi(n) << '\n';
		cin >> n;
	}
	#ifdef LOCAL
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}
