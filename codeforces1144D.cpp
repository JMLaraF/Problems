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
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	ll n , mx = 0 , k;
	map<ll,ll> mp;
	cin >> n;
	vll v(n);
	forn
	{
		cin >> v[i];
		mp[v[i]]++;
		if(mp[v[i]] > mx)
		{
			mx = mp[v[i]];
			k = v[i];
		}
	}
	cout << n-mx << '\n';
	for(int i = 0 ; i < n ; i++)
	{
		if(v[i] == k)
		{
			for(int j = i-1 ; j >= 0 && v[j] != k ; j--)
			{
				if(v[j] > k)
					cout << "2 ";
				else
					cout << "1 ";
				cout << j+1 << ' ' << j+2 << '\n';
				v[j] = k;
			}
		}
	}
	for(int i = n-1 ; i >= 0 ; i--)
	{
		if(v[i] == k)
		{
			for(int j = i+1 ; j < n && v[j] != k ; j++)
			{
				if(v[j] > k)
					cout << "2 ";
				else
					cout << "1 ";
				cout << j+1 << ' ' << j << '\n';
				v[j] = k;
			}
		}
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}