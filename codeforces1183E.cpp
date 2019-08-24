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



ll fun(string s , set<string> &st , ll k)
{
	ll mx = 1;
	string sub;
	pair<string,ll> aux;
	ll ans = 0;
	queue<pair<string,ll> > cola;
	cola.push(pair<string,ll>(s,0));
	st.insert(s);
	while(st.size() < k && !cola.empty())
	{
		aux = cola.front();
		cola.pop();
		for(int i = 0 ; i < aux.xx.size() && st.size() < k; i++)
		{
			sub = aux.xx.substr(0,i)+aux.xx.substr(i+1,s.size()-i-1);
			if(!st.count(sub))
			{	
				st.insert(sub);
				ans += aux.yy+1;
				cola.push(pair<string,ll>(sub,aux.yy+1));
			}
		}
	}
	return ((st.size() >= k)?ans:(-1));
}


int main()
{_C
	ll n , k , ans = 0;
	cin >> n >> k;
	set<string> st;
	string s;

	cin >> s;
	
	cout << fun(s,st,k) << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}