#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

ll GCD(ll a , ll b){return (b == 0)? a:GCD(b , a%b);}

ll ft(ll x , ll y , vll &v , ll i)
{

}

int main()
{_C
	ll n , a ,b , c , d , e , f;
	cin >> n;
	if(n < 2)
	{
		cin >> a >> b;;
			cout << a << '\n';
	}else
	{
		vpll v;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> a >> b;
			v.push_back(pll(a,b));
		}
		set<ll> ft;
		a = v[0].xx;
		b = v[0].yy;
		ll x = 2;
		while(a > 1 && x < 100000)
		{
			if(a%x == 0)
			{
				a /= x;
				ft.insert(x);
			}
			else
				x++;
		}
		if(a > 1)
			ft.insert(a);
		x = 2;
		while(b > 1 && x < 100000)
		{
			if(b%x == 0)
			{
				b /= x;
				ft.insert(x);
			}
			else
				x++;
		}
		if(b > 1)
			ft.insert(b);
		set<ll>::iterator it;
		for(it = ft.begin() ; it != ft.end() ; it++)
		{
			bool ans = true;
			for(int i = 1 ; i < n ; i++)
			{
				ans &= (v[i].xx%(*it) == 0 || v[i].yy%(*it) == 0);
			}
			if(ans == true)
			{
				cout << (*it) << '\n';
				return 0;
			}
		}
		cout << "-1\n";
	}
	return 0;
}