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

int main()
{_C
	ll unos = 0 , dos = 0 , tres = 0 , cuatro = 0 , seis = 0 , n = 0 , a = 0;
	cin >> n;
	For(o,n)
	{
		cin >> a;
		switch(a)
		{
			case 1:
				unos++;
			break;
			case 2:
				dos++;
			break;
			case 3:
				tres++;
			break;
			case 4:
				cuatro++;
			break;
			case 6:
				seis++;
			break;
		}
	}
	if(unos != (n/3) || (dos+tres) != (n/3) || (seis < tres) || (seis+cuatro) != (n/3))
	{
		cout << "-1\n";
		return 0;
	}
	while(unos--)
	{
		cout << "1 ";
		if(dos)
		{
			dos--;
			cout << "2 ";
		}
		else
			cout << "3 ";
		if(cuatro)
		{
			cuatro--;
			cout << "4\n";
		}
		else
			cout << "6\n";
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}