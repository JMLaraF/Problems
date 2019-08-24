#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
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

bool cmp(const pll &p1 , const pll &p2)
{
	return ((p1.xx < p2.xx) || (p1.xx == p2.xx && p1.yy > p2.yy));
}

int main()
{_C
	ll n , m , ans = 0 , a , b;
	cin >> n >> m;
	map<ll,ll> frutas;
	map<ll,ll> quedadas;
	forn
	{
		cin >> a >> b;
		frutas[a] += b;
	}

	for(int i = 0 ; i < 3002 ; i++)
	{
		ll z = 0 , y;
		if(quedadas.count(i-1))
		{
			z += min(m,quedadas[i-1]);
		}
		if(frutas.count(i))
		{
			y = z;
			z += min(frutas[i],m-y);
			quedadas[i] = max((ll)0,(frutas[i]-(m-y)));
		}
		ans += z;
	}
	cout << ans << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}