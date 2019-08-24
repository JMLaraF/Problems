#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 986444689
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

vll FAC(300005,1);

void calFAc()
{
	for(int i = 1 ; i < FAC.size() ; i++)
		FAC[i]	= ((FAC[i-1]*i)+MOD)%MOD;
}

ll pot(ll a , ll b)
{
	ll ans = 1;

	for(int i = 0 ; i < 31 ; i++)
	{
		if((((ll)1<<i)&b)!=0)
			ans = ((ans*a)+MOD)%MOD;
		a = ((a*a)+MOD)%MOD;
	}
	return ans;
}

ll combinatoria(ll n , ll k)
{
	return ((FAC[n]*pot(((FAC[k]*FAC[n-k])+MOD)%MOD,MOD-2))+MOD)%MOD;
}


int main()
{
	calFAc();
	ll t , n , k , x , q;
	string s1 , s2;
	stringstream ss;
	cin >> t;
	vector<bool> d;
	while(t--)
	{ 	
		q = 0;
		cin >> n >> k;
		getchar();
		getline(cin,s1);
		getline(cin,s2);
		d.assign(n+5,false);
		ss.clear();
		ss.str(s2);
		while(ss >> x)
		{
			if(x == 0)
				continue;
			d[x] = true;
			q++;
		}
		k -= 2*q;
		ss.clear();
		ss.str(s1);
		q = 0;
		while(ss >> x)
		{
			if(x == 0)
				continue;
			if(d[x] == false)
				q++;
		}
		k -= q;
		if(k >= 0)
			cout << combinatoria(k+n-1,n-1) << '\n';
		else
			cout << "0\n";
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}