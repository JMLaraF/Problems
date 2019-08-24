#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
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

bool srt(const ll &a , const ll &b)
{
	return a > b;
}

int main()
{_C
	ll n , k;
	cin >> n >> k;
	vll v(n);
	forn
		cin >> v[i];
	sort(v.begin(),v.end(),srt);
	ll l = 0 , r = 0 , i = 0 , j = 0 , mx = 1 , s = 0;
	while(k >0 && v.size() > 0)
	{
		k--;
		mx = 1;
		l = 0;
		r = 0;
		i = 0;
		j = 1;
		while(r < v.size())
		{
			if(v[l]-v[r] > 5)
				l++;
			else
			{
				if(r-l+1 > mx)
				{
					mx = r-l+1;
					i = l;
					j = r+1;
				}
				r++;
			}
		}
		s += mx;
		v.erase(v.begin()+i,v.begin()+j);
	}
	

	cout << s << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}