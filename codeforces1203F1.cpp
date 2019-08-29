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

bool cmp1(const pll &p1 , const pll &p2)
{
	return p1.xx < p2.xx || (p1.xx == p2.xx && p1.yy < p2.yy);
}
bool cmp2(const pll &p1 , const pll &p2)
{
	return p1.xx + p1.yy > p2.xx + p2.yy;
}



int main()
{_C
	ll n , r , a , b;
	cin >> n >> r;
	vpll pos , neg;
	forn
	{
		cin >> a >> b;
		if(b > 0)
		{
			pos.pb(pll(a,b));
		}else
		{
			neg.pb(pll(a,b));
		}
	}
	sort(pos.begin() , pos.end() , cmp1);
	for(int i = 0 ; i < neg.size() ; i++)
		neg[i].xx = max(neg[i].xx , -neg[i].yy);
	sort(neg.begin() , neg.end() , cmp2);
	bool ans = true;
	for(int i = 0 ; i < pos.size() && ans ; i++)
	{
		if(pos[i].xx > r)
		{
			ans = false;
			break;
		}
		r += pos[i].yy;
	}
	for(int i = 0 ; i < neg.size() && ans ; i++)
	{
		if(neg[i].xx > r)
		{
			ans = false;
			break;
		}
		r += neg[i].yy;
	}

	if(ans)
		cout << "YES\n";
	else
		cout << "NO\n";


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}