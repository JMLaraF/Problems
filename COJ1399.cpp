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

ll DP[105][105][105];

void SET()
{
	for(int i = 0 ; i < 104 ; i++)
		for(int j = 0 ; j < 104 ; j++)
			for(int k = 0 ; k < 104 ; k++)
				DP[i][j][k] = -1;
	DP[0][0][0] = 1;

}

ll dp(ll a , ll b , ll c)
{
	if(a < 0 || b < 0 || c < 0)
		return 0;
	if(DP[a][b][c] != -1)
		return DP[a][b][c];
	ll x = max(dp(a-1,b,c),dp(a,b-1,c));
	x = max(x,dp(a,b-2,c));
	x = max(x,dp(a,b,c-1));
	x = max(x,dp(a,b,c-2));
	x = max(x,dp(a,b,c-3));
	x = max(x,dp(max(a-1,0LL),max(b-1,0LL),max(c-1,0LL)));
	if(x)
		DP[a][b][c] = 0;
	else
		DP[a][b][c] = 1;
	return DP[a][b][c];
}


int main()
{_C
	SET();
	ll a , b , c;
	cin >> a >> b >> c;
	while(a || b || c)
	{
		cout << a << ' ' << b << ' ' << c << ' ';
		if(!dp(a,b,c))
			cout << "Bilbo wins\n";
		else
			cout << "Frodo wins\n";
		cin >> a >> b >> c;
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}