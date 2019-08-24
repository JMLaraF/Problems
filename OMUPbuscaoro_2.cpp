#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF 1<<30
#define nSize 1000000
#define For(o,n) for(int i = 0 ; i < n ; i++)
using namespace std;
typedef int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef long double ld;

int getL(vector<vll> &v , int i , int j , int k , int c)
{
	int l = 0 , r = j-1, m, a = INF;
	int z = v[i][j] - v[k][j];
//	cout << "\tZ = " << z << " i = " << i << " j = " << j << " k = " << k <<	 '\n';
	while(l < r)
	{
		m = (l+r)/2;
//		cout << "\tm = " << m << " a = " << (z - v[i][m] + v[k][m]) << " ZZ\n";
		if((z - v[i][m] + v[k][m]) <= c)
		{
			a = m;
			r = m;
		}else
		{
			l = m+1;
		}
//		cout << "\tl = " << l << " r = " << r << '\n';
	}
	if(a == INF && l == r)
	{
		m = (l+r)/2;
//		cout << z - v[i][m] + v[k][m] << "ZZ " << c << "\n"; 
		if((z - v[i][m] + v[k][m]) <= c)
		{
//			cout << "ENT\n";
			a = m;
			r = m;
		}else
		{
			l = m+1;
		}
	}
	return a;
}

int getL2(vector<vll> &v , int i , int j , int k , int ll , int c)
{
	int l = ll , r = j-1, m, a = INF;
	int z = v[i][j] - v[k][j];
	while(l < r)
	{
		m = (l+r)/2;
	//	cout << "\t\t\tl = " << l << " r = " << r << " m = " << m << '\n';
		if((z - v[i][m] + v[k][m]) == c)
		{
			a = m;
			l = m+1;
		}else
		{
			r = m;
		}
	}
	if(l == r)
	{
		m = (l+r)/2;
		if((z - v[i][m] + v[k][m]) == c)
		{
			a = m;
			l = m+1;
		}else
		{
			r = m;
		}
	}
	return a;
}

int getK(vector<vll> &v , int i , int j, int &L , int &a , int c)
{
//	cout << "ENT F1\n";
	L = INF;
	int mx = 0 , cmp , ar = INF;
	int l = 0 , r = i-1 , m , z;
	a = INF;
	while(l < r)
	{
		m = (l+r)/2;
		if((z = getL(v,i,j,m,c)) != INF)
		{
			cmp = v[i][j] - v[m][j] - v[i][z] + v[m][z];
			if(cmp > mx)
			{
				a = m;
				L = z;
				ar = (i-m)*(j-z);
				mx = cmp;

			}
			r = m;
			
		}else
		{
			l = m+1;
		}
	}
	if(a == INF && l == r)
	{
		m = (l+r)/2;
		if((z = getL(v,i,j,m,c)) != INF)
		{
			cmp = v[i][j] - v[m][j] - v[i][z] + v[m][z];
	//		cout << cmp << " CMP\n";
			if(cmp > mx)
			{
				a = m;
				L = z;
				ar = (i-m)*(j-z);
				mx = cmp;

			}
			r = m;
			
		}else
		{
			l = m+1;
		}
	}
	if(ar == INF)
		return ar;

//	cout << "ENT F2\n";

	ar = INF;
	l = a;
	r = i-1;
	while(l < r)
	{
	//	cout << "\t\tL = " << l << " R = " << r << '\n';
		m = (l+r)/2;
	//	cout << "\t\tm = " << m << '\n';
		if((z = getL2(v,i,j,m,L,mx)) != INF)
		{
			cmp = v[i][j] - v[m][j] - v[i][z] + v[m][z];
			if(cmp >= mx)
			{
				a = m;
				L = z;
				ar = (i-m)*(j-z);
	//			cout << "\t\ta = " << a << " lg = " << L << " area = " << ar << "\n";

			}
			l = m+1;
			
		}else
		{
			r = m;
		}
	}
	if(l == r)
	{
		m = (l+r)/2;
		if((z = getL2(v,i,j,m,L,mx)) != INF)
		{
			cmp = v[i][j] - v[m][j] - v[i][z] + v[m][z];
			if(cmp >= mx)
			{
				a = m;
				L = z;
				ar = (i-m)*(j-z);
				mx = cmp;

			}
			l = m+1;
			
		}else
		{
			r = m;
		}
	}
	return ar;
}


int main()
{
	int n , m , z , a = INF , b = 0 , c;
	cin >> n >> m >> z;
	vector<vll> v(n+1,vll(m+1));
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			cin >> v[i][j];
			if(i > 1)
				v[i][j] += v[i-1][j];
			if(j > 1)
				v[i][j] += v[i][j-1];
			if(i > 1 && j > 1)
				v[i][j] -= v[i-1][j-1];
		}
	}
/*	cout << "\n\n";
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
			cout << v[i][j] << ((j == m)?'\n':' ');
*/

	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			int l;
			int k;
		//	cout << "i = " << i << " j = " << j << '\n';
			int q = getK(v,i,j,l,k,z);
		//	cout << "q = " << q << " i = " << i << " j = " << j << " y = " << k << " x = " << l << '\n'; 
			if(k != INF)
			{

						c = v[i][j] - v[k][j] - v[i][l] + v[k][l];
						if(c > b || (c == b && q < a))
						{
							b = c;
							a = q;
						}

			}
		}
	}
	if(a != INF)
		cout << b << ' ' << a << '\n';
	else
		cout << "0 1\n";

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}