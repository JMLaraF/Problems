#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

vll Grundy(10005 , -1);
/*
ll dp(ll x)
{
	if(x <= 0)
		return 0;
	if(Grundy[x] != -1)
		return Grundy[x];
	vll SPG(10005,0);
	for(int i = 1 ; i <= (x/2)+1 ; i++)
	{
		for(int j = 1 ; j <=3 ; j++)
		{
			SPG[dp(i-j)] = 1;
			SPG[dp(max(0LL,x-(i+j-1)))] = 1;
		}
	}
	ll mex = -1;
	while(SPG[++mex]);
	Grundy[x] = mex;
	return mex;
}
*/

void PUTGRUNDY()
{
	Grundy[0] = 0;
	vll SPG;
	for(ll x = 1 ; x <= 10000 ; x++)
	{
		SPG.assign(10005,0);
		for(int i = 1 ; i <= (x/2)+1 ; i++)
		{
			for(int j = 0 ; j < 3 ; j++)
			{
				SPG[Grundy[max(0,(i-1))]^Grundy[max(0LL,x-i-j)]] = 1;
			}
		}
		ll mex = -1;
		while(SPG[++mex]);
		Grundy[x] = mex;
	}
}

int main()
{_C
	ll n , t , b = 0 , a , c;
	cin >> t;
	PUTGRUNDY();
	while(t--)
	{
		b = 0;	
		cin >> n;
		forn
		{
			cin >> a;
			a = Grundy[a];
			b ^= a;
		}
		if(!b)
			cout << "SLAVKO\n";
		else
			cout << "MIRKO\n";
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}