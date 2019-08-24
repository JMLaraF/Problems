#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll binaria(ll x , vi &v)
{
	ll l = 0 , r = v.size() - 1 , m;
	while(r > l)
	{
		m = (l + r)/2;
		if(v[m] >= x)
			r = m;
		else
			l = m + 1;
	}
	if(v[r] == x)
		return r;
	else
		return -1;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n , q , a , b = 0 , c;;
	cin >> n >> q;
	while(n != 0 && q != 0)
	{
		vi v(n);
		for(ll i = 0 ; i < n ; i++)
			cin >> v[i];
		sort(v.begin() , v.end());
		cout << "CASE# " << ++b << ":\n";
		for(int i = 0 ; i < q ; i++)
		{
			cin >> a;
			c = binaria(a , v);
			if(c >= 0)
				cout << a << " found at " << c+1 << '\n';
			else
				cout << a << " not found\n";
		}
		cin >> n >> q;
	}

	return 0;
}