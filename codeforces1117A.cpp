#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main()
{
	ll n , mx = 0 , c = 0 , ans = 0;
	cin >> n;
	vll v(n);
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i];
		mx = max(v[i],mx);
	}
	for(int i = 0 ; i < n ; i++)
	{
		if(v[i] == mx)
			c++;
		else
		{
			ans = max(c,ans);
			c = 0;
		}
	}
	cout << max(c,ans) << '\n';
	return 0;
}