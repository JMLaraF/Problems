#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

vector<vll> v(5,vll(5,0));

ll t(vector<bool> mask, vll ans)
{
	ll mx = 0;
	if(ans.size() < 5)
	{
		for(int i = 0 ; i < 5 ; i++)
		{	
			if(!mask[i])
			{
				ans.push_back(i);
				mask[i]=true;
				mx = max(mx,t(mask,ans));
				ans.pop_back();
				mask[i]=false;
			}
		}
	}else
	{
	//	for(int i = 0 ; i < 5 ; i++)
	//		cout << ans[i] << ((i == 4)?'\n':' ');
		return 2*(v[ans[0]][ans[1]]+v[ans[1]][ans[0]]) + 2*(v[ans[1]][ans[2]]+v[ans[2]][ans[1]])+(v[ans[2]][ans[3]]+v[ans[3]][ans[2]])+(v[ans[3]][ans[4]]+v[ans[4]][ans[3]]);
	}
	return mx;

}
int main()
{_C
	for(int i = 0 ; i < 5 ; i++)
		for(int j = 0 ; j < 5 ; j++)
			cin >> v[i][j];
	cout << t(vector<bool>(5,false),vll()) << '\n';
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}