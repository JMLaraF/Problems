#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
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

bool op(const pll &p1 , const pll &p2)
{
	return ((p1.xx > p2.xx) || (p1.xx == p2.xx && p1.yy < p2.yy)); 
}

bool operator >(const pll &p1 , const pll &p2)
{
	return ((p1.xx > p2.xx) || (p1.xx == p2.xx && p1.yy < p2.yy));
}
bool operator >=(const pll &p1 , const pll &p2)
{
	return ((p1.xx > p2.xx) || (p1.xx == p2.xx && p1.yy <= p2.yy));
}

ll binary(bool f , pll p , vpll &v)
{
	ll l = 0 , r = v.size()-1 , m;
	while(l < r)
	{
		m = (l+r)/2;
		if(f)
		{
			if(v[m] > p)
			{
				l = m+1;
			}else
			{
				r = m;
			}
		}else
		{
			if(m == l)
				m++;
			if(v[m] >= p)
			{
				l = m;
			}else
			{
				r = m-1;
			}
		}	
	}
	return l; 
}


int main()
{_C
	ll n , k , a, b;
	cin >> n >> k;

	vpll v(n);
	forn
		cin >> v[i].xx >> v[i].yy;


	sort(v.begin() , v.end() , op);
	ll low = binary(true , v[k-1] , v);
	ll high = binary(false , v[k-1] , v);
	cout << high-low+1 << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}

/*
display m
display l
display r
*/