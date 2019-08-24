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

class Disjoinset
{
	private:
		vll p , r;
	public:
		Disjoinset(ll n)
		{
			r.assign(n,0);
			for(int i = 0 ; i < n ; i++)
				p.pb(i);
		}
		ll getP(ll x)
		{
			return ((p[x] == x)? x : (p[x] = getP(p[x])));
		}
		bool isSame(ll x , ll y)
		{
			return getP(x) == getP(y);
		}
		bool conect(ll a , ll b)
		{
			ll x = getP(a) , y = getP(b);
			if(x != y)
			{
				if(r[x] > r[y])
				{
					p[y] = x;
				}else
				{
					p[x] = y;
					if(r[x] == r[y])
						r[y]++;
				}
				return true;
			}
			return false;
		}
};

int main()
{_C
	ll n , m , a , b , c = 0;
	cin >> n >> m;
	bool f = false;
	Disjoinset ds(n+m);
	forn
	{
		cin >> a;
		while(a--)
		{
			cin >> b;
			if(b > 0  && b <= m)
				f = true;
			if(b <= m)
				ds.conect(i,n+b-1);
		}
	}
	if(!f)
	{
		cout << n << '\n';
		return 0;
	}
	for(int i = 1 ; i < n ; i++)
	{
		if(!ds.isSame(0,i))
		{
			ds.conect(0,i);
			c++;
		}
	}
	cout << c << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}