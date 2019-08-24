#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
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
typedef complex<double> cp;
typedef vector<cp> polinomio;
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

polinomio& operator *(polinomio &A , polinomio &B)
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
	return A;
}



int main()
{_C
	ll t , a = 0;
	cin >> t;
	string s , z;
	vll v;
	while(t--)
	{
		a = 0;
		cin >> s >> z;
		if(s == "0" || z == "0")
		{
			cout << "0\n";
			continue;
		}
		polinomio A(s.size());
		polinomio B(z.size());
		for(int i = 0 ; i < s.size() ; i++)
			A[i] = s[i]-'0';
		for(int i = 0 ; i < z.size() ; i++)
			B[i] = z[i]-'0';
		A = A*B;
		v.resize(0);
		for(int i = A.size()-1 ; i >= 0 ; i--)
		{
			if(i != 0)
				v.push_back(((ll)round(A[i].real())+a)%10);
			else
				v.push_back(((ll)round(A[i].real())+a));
			a = ((ll)round(A[i].real())+a)/10;
		}
		for(int i = v.size()-1 ; i >= 0 ; i--)
			cout << v[i];
		cout << '\n';
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}