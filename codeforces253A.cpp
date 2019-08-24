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
typedef int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int main()
{_C
	ll n , m;
		FILE *file;
	file = fopen("input.txt","r");
	fscanf(file,"%d %d",&n,&m);
	fclose(file);
	file = fopen("output.txt","w");
	bool ff = true;

	if(m > n)
	{
		ff = false;
		swap(n,m);
	}
	while(n > 0)
	{
		if(ff)
		{
			if(n > 0)
			{
				n--;
				fprintf(file,"B");
			}
			if(m > 0)
			{
				m--;
				fprintf(file,"G");
			}
		}else
		{
			if(n > 0)
			{
				n--;
				fprintf(file,"G");
			}
			if(m > 0)
			{
				m--;
				fprintf(file,"B");
			}
		}
	}
	fprintf(file,"\n");
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}