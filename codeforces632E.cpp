#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.0001
#define INF (ll)1<<62
#define nSize 1000000
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

void fft(polinomio &a, int sign = +1){
	int n = a.size();

	for (int i = 1, j = 0; i < n - 1; ++i)
	{
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);

		if (i < j) swap(a[i], a[j]);
	}

	double theta = 2 * atan2(0, -1) * sign;

	for (int m, mh = 1; (m = mh << 1) <= n; mh = m)
	{
		cp wm(cos(theta / m), sin(theta / m)), w(1, 0);

		for (int i = 0; i < n; i += m, w = cp(1, 0))
			for (int j = i, k = j + mh; j < i + mh; ++j, ++k, w = w * wm)
			{
				cp x = a[j], y = a[k] * w;
				a[j] = x + y;
				a[k] = x - y;
			}
	}

	if (sign == -1)
		for (cp &p : a) p = p / (1. * n);
}

polinomio &operator *(polinomio &A , polinomio B)
{
	ll a = A.size() , b = B.size() , n = a+b-1 , k = 1;
	while(n > k) k <<= 1;
	A.resize(k);
	B.resize(k);
	fft(A,1);
	fft(B,1);
	for(int i = 0 ; i < k ; i++)
		A[i] *= B[i];
	fft(A,-1);
	A.resize(n);
	forn
		A[i] = (A[i].real() > ERR)? 1 : 0 ;
	return A;
}

polinomio pot(polinomio &A , int b)
{
	polinomio ans(1);
	ans[0] = 1;
	for(int i = 0 ; i < 63 && 1<<i <= b ; i++)
	{
		if(((1<<i)&b)!=0)
			ans = ans*A;
		A = A*A;
	}
	return ans;
}

int main()
{_C
	ll n, k , a;
	cin >> n >> k;
	polinomio A(1005);
	forn
	{
		cin >> a;
		A[a] = 1;
	}
	polinomio B = pot(A,k);
	for(int i = 0 ; i < B.size() ; i++)
		if(B[i].real() > ERR)
			cout << i << ' ';
		cout << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}