#include <bits/stdc++.h>

using namespace std;

#define TAM 3000000

void criba (vector <int> & v)
{
	bitset <TAM> b;
	v.push_back(2);
	for(long long i = 3 ; i < TAM ; i += 2)
	{
		if(b[i] == 0)
		{
			v.push_back(i);

		}
		for(long long j = i*i ; j < TAM ; j += i)
		{
			b[j] = 1;

		}
	}
}

int main (void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <int> v;
	criba(v);
	double a = 1;
	do
	{
		cin >> a;
		if (a > 0)
		{
			
			cout << right << setw(3) << a << "! =";

			for(long long i = 0 ; i < v.size() && v[i] <= a ; i++)
			{
				long long x = 0;
				for(double j = v[i] ; j <= a ; j *= v[i])
				{
					x += (long long)floor(a/j);

				}
				if(i % 15 == 0 && i > 0)
				{
					cout << right << "\n      "<< setw(3) << x;
				}else
				{
					cout << right << setw(3)  << x;
				}
				
			}
			cout << "\n";
		}
	}while(a > 0);
	return 0;
}