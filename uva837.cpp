#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef pair<double , double> pdl;


int main()
{_C
	ll t , n;
	double x1 , x2 , rr , z;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector< pair < pdl , bool > >v(2*n);
		for(int i = 0 ; i < n ; i++)
		{
			cin >> x1 >> rr >> x2 >> rr >> z;
			if(x1 > x2)
				swap(x1,x2);
			v[2*i].xx.xx = x1;
			v[2*i + 1].xx.xx = x2;
			v[2*i].xx.yy = z;
			v[2*i + 1].xx.yy = z;
			v[2*i].yy = false;
			v[2*i + 1].yy = true;
		}
		sort(v.begin() , v.end());
		cout << v.size() + 1 << '\n' << "-inf ";
		double alpa = 1;
		for(int i = 0 ; i < v.size() ; i++)
		{
			cout << fixed << setprecision(3) << v[i].xx.xx << ' ' << alpa << '\n' << v[i].xx.xx << ' ';
			alpa *= (!v[i].yy)? v[i].xx.yy : 1/v[i].xx.yy;
		}
		cout << "+inf 1.000\n";
		if(t != 0)
			cout << '\n';

	}	

	return 0;
}