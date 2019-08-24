#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;


ll pot(ll a , ll b)
{
	if(b == 0)
		return 1;
	ll ans = 1;
	for(int i = 0 ; i < 63 ; i++)
	{
		if((((ll)1<<i)&b)!= 0)
			ans = ((ans*a)+MOD)%MOD;
		a = ((a*a)+MOD)%MOD;
	}
	return ans; 
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a , n;
	cin >> a;
	while(a--)
	{
		cin >> n;
		ll k = (ll)floor((n-1)/2);
		ll ans = ((pot(2,k+2)-2)+MOD)%MOD;
		if(n%2==0)
			ans = ((ans+pot(2,k+1))+MOD)%MOD;
		cout << ans << '\n';
	}
}