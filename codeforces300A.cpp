#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);


int main()
{_C
	ll n , a , ceros = 0;
	vll pos,neg;
	set<ll> p,ng,cr;
	cin >> n;
	forn
	{
		cin >> a;
		if(a > 0)
			pos.push_back(a);
		else if(a < 0)
			neg.push_back(a);
		else
			ceros++;
	}
	for(int i = 0 ; i < neg.size() ; i++)
	{
		if(!ng.count(neg[i]))
			ng.insert(neg[i]);
		else if(!p.count(neg[i]))
			p.insert(neg[i]);
		else
			cr.insert(neg[i]);
	}
	set<ll>::iterator it;
	if(p.size() %2 != 0)
	{
		for(it = p.begin() ; it != p.end() ; it++)
			if(!cr.count(*it))
			{
				cr.insert(*it);
				p.erase(it);
				break;
			}
	}
	if(ng.size() %2 == 0)
	{
		for(it = ng.begin() ; it != ng.end() ; it++)
			if(!cr.count(*it))
			{
				cr.insert(*it);
				ng.erase(it);
				break;
			}
	}
	for(int i = 0 ; i < pos.size() ; i++)
	{
		if(!p.count(pos[i]))
			p.insert(pos[i]);
		else if(!ng.count(pos[i]))
			ng.insert(pos[i]);
		else
			cr.insert(pos[i]);
	}

	if(p.size() == 0)
	{
		p.insert(*ng.begin());
		ng.erase(ng.begin());
		p.insert(*ng.begin());
		ng.erase(ng.begin());
	}

	cout << ng.size() << ' ';
	int z;
	for(it = ng.begin() , z = 0 ; it != ng.end() ; it++ , z++)
		cout << *it << ((z == ng.size()-1)?'\n':' ');
	cout << p.size() << ' ';
	for(it = p.begin() , z = 0 ; it != p.end() ; it++ , z++)
		cout << *it << ((z == p.size()-1)?'\n':' ');
	cout << cr.size()+ceros << ' ';
	for(it = cr.begin(); it != cr.end() ; it++)
		cout << *it << ' ';
	while(ceros--)
		cout << "0" << ((ceros == 0)?'\n':' ');
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}