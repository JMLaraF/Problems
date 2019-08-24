#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define For(o,n) for(int i = 0 ; i < n ; i++)
#define nSize 
using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;



int main()
{_C
	vll p(32 , 0);
	p[2] = 1;
	p[3] = 1;
	p[5] = 1;
	p[7] = 1;
	p[13] = 1;
	p[17] = 1;
	p[19] = 1;
	p[31] = 1;
	ll n;
	cin >> n;
	while(n != 0)
	{
		if(p[n] == 1)
			cout << "Perfect: " << ((ll)1<<(n-1))*(((ll)1<<n)-1) << "!\n";
		else
			if(n == 11 || n == 23 || n == 29)
				cout << "Given number is prime. But, NO perfect number is available.\n";
			else
				cout << "Given number is NOT prime! NO perfect number is available.\n";
		cin >> n;
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}