#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ld A[3] , a , b , c;
	cin >> A[0] >> A[1] >> A[2];
	b = sqrt(A[0]*A[2]/A[1]);
	a = A[2]/b;
	c = A[0]/b;
	if(fabs(a-floor(a)) <= ERR && fabs(b-floor(b)) <= ERR && fabs(b-floor(b)) <= ERR)
	{
		cout << 4*a+4*b+4*c << '\n';
		return 0;
	}
	b = sqrt(A[0]*A[1]/A[2]);
	a = A[1]/b;
	c = A[0]/b;
	if(fabs(a-floor(a)) <= ERR && fabs(b-floor(b)) <= ERR && fabs(b-floor(b)) <= ERR)
	{
		cout << 4*a+4*b+4*c << '\n';
		return 0;
	}
	b = sqrt(A[2]*A[0]/A[1]);
	a = A[0]/b;
	c = A[2]/b;
	if(fabs(a-floor(a)) <= ERR && fabs(b-floor(b)) <= ERR && fabs(b-floor(b)) <= ERR)
	{
		cout << 4*a+4*b+4*c << '\n';
		return 0;
	}
	b = sqrt(A[2]*A[1]/A[0]);
	a = A[1]/b;
	c = A[2]/b;
	if(fabs(a-floor(a)) <= ERR && fabs(b-floor(b)) <= ERR && fabs(b-floor(b)) <= ERR)
	{
		cout << 4*a+4*b+4*c << '\n';
		return 0;
	}
	b = sqrt(A[1]*A[2]/A[0]);
	a = A[2]/b;
	c = A[1]/b;
	if(fabs(a-floor(a)) <= ERR && fabs(b-floor(b)) <= ERR && fabs(b-floor(b)) <= ERR)
	{
		cout << 4*a+4*b+4*c << '\n';
		return 0;
	}
	b = sqrt(A[1]*A[0]/A[2]);
	a = A[0]/b;
	c = A[1]/b;
	if(fabs(a-floor(a)) <= ERR && fabs(b-floor(b)) <= ERR && fabs(b-floor(b)) <= ERR)
	{
		cout << 4*a+4*b+4*c << '\n';
	}
	return 0;
}

/*	Weakened Commond Divisor	*/