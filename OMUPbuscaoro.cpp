#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<30
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
	int l = 0 , r = j-1 , m , z , ans = INF;
	if(l == r)
	{
		if(k >= 0)
			z = v[i][j] - v[k][j] - v[i][l] + v[k][l];
		else
			z = v[i][j] - v[i][l];
		if(z <= c)
			ans = l;
	}
	while(l <= r)
	{
		m = (l+r)/2;
//		cout << "L = " << l << " R = " << r << " Lm = " << m << '\n';
		if(k >= 0)
			z = v[i][j] - v[k][j] - v[i][m] + v[k][m];
		else
			z = v[i][j] - v[i][m];
//		cout << "Z = " << z << '\n';
		if(z <= c)
		{
			ans = m;
			r = m-1;
		}
		else
			l = m+1;
	}
//	cout << "SALIO " << ans << '\n';
	return ans;
}

int getK(vector<vll> &v , int i , int j , int c)
{
//	cout << "ENTRO\n";
	int l = 0 , r = i , m , z , ans = INF;
	while(l <= r)
	{
		m = (l+r)/2;
//		cout << "Km = " << m << '\n';
		if(getL(v,i,j,m-1,c) != INF)
		{
			r = m-1;
			ans = m;
		}else
			l = m+1;
	}
	if(r == 0)
		ans = getL(v,i,j,-1,c);
	return ans-1;
}

int main()
{_C
	int a , b, c;
	cin >> a >> b >> c;
	vector<vll> v(a,vll(b));
	for(int i = 0 ; i < a ; i++)
	{
		for(int j = 0 ; j < b ; j++)
		{
			cin >> v[i][j];
			if(j > 0)
				v[i][j]+=v[i][j-1];
			if(i > 0)
				v[i][j]+=v[i-1][j];
			if(i > 0 && j > 0)
				v[i][j]-=v[i-1][j-1];
		}
	}

	int mx = 0 ,ar = INF , z;
	for(int i = 0 ; i < a ; i++)
	{
		for(int j = 0 ; j < b ; j++)
		{
			if(v[i][j] <= c)
			{
				if(v[i][j] > mx)
				{
					mx = v[i][j];
					ar = (j+1)*(i+1);
				}else if(v[i][j] == mx && (j+1)*(i+1) < ar)
				{
					ar = (j+1)*(i+1);
				}
			}
			
			for(int k = getK(v,i,j,c) ; k < i ; k++)
			{
				if(k >= 0)
				{
					z = v[i][j] - v[k][j];
					if(z <= c)
					{
						if(z > mx)
						{
							mx = z;
							ar = (i-k)*(j+1);
						}else if(mx == z && (i-k)*(j+1) < ar)
						{
							ar = (i-k)*(j+1);
						}
					}
				}
				for(int l = getL(v , i , j , k , c) ; l < j ; l++)
				{
					if(k >= 0)
					{
						z = v[i][j] - v[k][j] - v[i][l] + v[k][l];
						if(z <= c)
						{
							if(z > mx)
							{
								mx = z;
								ar = (i-k)*(j-l);
							}else if(mx == z && (i-k)*(j-l) < ar)
							{
								ar = (i-k)*(j-l);
							}
						}//else
					//		break;	
					}
					else
					{
						z = v[i][j] - v[i][l];
						if(z <= c)
						{
							if(z > mx)
							{
								mx = z;
								ar = (i+1)*(j-l);
							}else if(mx == z && (i+1)*(j-l) < ar)
							{
								ar = (i+1)*(j-l);
							}
						}//else
					//		break;
					}
				}
			}
		}
	}
	cout << mx << ' ' << ar << '\n';

	
	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}