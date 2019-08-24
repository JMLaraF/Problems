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

struct nodo
{
	ll v;
	map<char,ll> Fx;
	nodo():v(0){}
};

struct trie
{
	vector<nodo> v;
	trie()
	{
		v.assign(1,nodo());
	}
	void add(string s)
	{
		ll x = 0;
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(v[x].Fx.count(s[i]))
			{
				x = v[x].Fx[s[i]];
				if(i == s.size()-1)
				{
					if(v[x].v > 0)
						cout << s+to_string(v[x].v) << '\n';
					else
						cout << "OK\n";
					v[x].v++;
				}
			}else
			{
				v[x].Fx[s[i]] = v.size();
				x = v.size();
				v.pb(nodo());
				if(i == s.size()-1)
				{
					v[x].v = 1;
					cout << "OK\n";
				}
			}
		}
	}
};

int main()
{_C
	ll n;
	string s;
	trie t;
	cin >> n;
	forn
	{
		cin >> s;
		t.add(s);
	}
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}