#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF 16777215
#define MOD 1000000
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

int toInt(const unsigned short int &a , const unsigned char &b)
	{
		ll x;
		x = b;
		x = x<<16;
		x += a;
		return x;
	}
	void toTern(unsigned short int &a , unsigned char &b ,int z)
	{
		a = z;
		b = (z>>16);
	}


unsigned short int DP1[4][4][39][39][39][39];
unsigned char DP2[4][4][39][39][39][39];

//x1 = A1, x2 = B1, x3 = A2, x4 = A3;
ll dp(ll a , ll b , ll y , ll x1 , ll x2 , ll x3 , ll x4)
{
	if(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0)
		return 1;
	if(x1 < 0 || x2 < 0 || x3 < 0 || x4 < 0)
		return 0;
	unsigned short int & res1 = DP1[a][b][x1][x2][x3][x4];
	unsigned char & res2 = DP2[a][b][x1][x2][x3][x4];
	if(toInt(res1,res2) != INF)
		return toInt(res1,res2);
	if(y < 2)
		toTern(res1,res2,(dp(b,0,y+1,x1-1,x2,x3,x4)+dp(b,1,y+1,x1,x2-1,x3,x4)+dp(b,2,y+1,x1,x2,x3-1,x4)+dp(b,3,y+1,x1,x2,x3,x4-1))%MOD);
	else
	{
		if(a == 0 && b == 0)
			toTern(res1,res2,(dp(b,3,y+1,x1,x2,x3,x4-1)%MOD));	
		else if((a == 0 && b == 1) || (a == 1 && b == 0))
			toTern(res1,res2,(dp(b,2,y+1,x1,x2,x3-1,x4)+dp(b,3,y+1,x1,x2,x3,x4-1))%MOD);
		else if((a == 0 && b == 2) || (a == 2 && b == 0))
			toTern(res1,res2,(dp(b,1,y+1,x1,x2-1,x3,x4)+dp(b,3,y+1,x1,x2,x3,x4-1))%MOD);
		else if(a == 1 && b == 1)
			toTern(res1,res2,(dp(b,2,y+1,x1,x2,x3-1,x4))%MOD);
		else if((a == 1 && b == 3) || (a == 3 && b == 1))
			toTern(res1,res2,(dp(b,0,y+1,x1-1,x2,x3,x4)+dp(b,2,y+1,x1,x2,x3-1,x4))%MOD);
		else if(a == 2 && b == 2)
			toTern(res1,res2,(dp(b,1,y+1,x1,x2-1,x3,x4))%MOD);
		else if((a == 2 && b == 3) || (a == 3 && b == 2))
			toTern(res1,res2,(dp(b,0,y+1,x1-1,x2,x3,x4)+dp(b,1,y+1,x1,x2-1,x3,x4))%MOD);
		else if(a == 3 && b == 3)
			toTern(res1,res2,(dp(b,0,y+1,x1-1,x2,x3,x4))%MOD);
		else
			toTern(res1,res2,(dp(b,0,y+1,x1-1,x2,x3,x4)+dp(b,1,y+1,x1,x2-1,x3,x4)+dp(b,2,y+1,x1,x2,x3-1,x4)+dp(b,3,y+1,x1,x2,x3,x4-1))%MOD);
	}
	return toInt(res1,res2);
}

int main()
{_C


	ll a , b, c , d;
	cin >> a >> b >> c >> d;
	memset(DP1,USHRT_MAX,sizeof DP1 );
	memset(DP2,UCHAR_MAX,sizeof DP2 );

	cout << dp(0,0,0,a,b,c,d) << '\n';


	#ifdef LOCAL
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}