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

vvll ST(4*100000+5 , vll (30,0));

ll areOn(vll &v)
{
	ll ans = 0;
	for(int i = 0 ; i < v.size() ; i++)
		if(v[i]) ++ans;
	return ans;
}

vll joinVectors(vll &v , vll &b)
{
	vll ans(30);
	for(int i = 0 ; i < v.size() ; i++)
	{
		ans[i] = v[i]+b[i];
	}
	return ans;

}

void update(ll v, ll l , ll r , ll pos , ll x)
{
	if(pos < l || pos >= r)
		return;
	else if(r-l == 1)
	{
		ST[v].assign(30,0);
		ST[v][x] = 1;
	}else
	{
		ll m = (l+r)/2;
		update(2*v,l,m,pos,x);
		update(2*v+1,m,r,pos,x);
		ST[v] = joinVectors(ST[2*v],ST[2*v+1]);
	}
}

vll query(ll v , ll l , ll r , ll x , ll y)
{
	if(y < l || x >= r)
		return vll(30,0);
	else if(l >= x && r-1 <= y)
		return ST[v];
	else
	{
		ll m = (l+r)/2;
		vll a = query(2*v,l,m,x,y);
		vll b = query(2*v+1,m,r,x,y);
		vll ans = joinVectors(a,b);
		return ans;
	}
}


int main()
{_C
	string s;
	ll q , a , b , c, n;
	char ch;
	vll ansQ;
	cin >> s;
	cin >> q;
	n = s.size();
	for(int i = 0 ; i < n ; i++)
		update(1,1,n+1,i+1,(ll)(s[i]-'a'));
	while(q--)
	{
		cin >> a >> b;
		if(a == 1)
		{
			cin >> ch;
			update(1,1,n+1,b,(ll)(ch-'a'));
		}else
		{
			cin >> c;
			ansQ = query(1,1,n+1,b,c);
			cout << areOn(ansQ) << '\n';
		}
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}