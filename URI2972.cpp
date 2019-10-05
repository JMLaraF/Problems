#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
using namespace std;


int main()
{_C
	long long n;
	cin >> n;
	long long x = 0;
	for(long long i = 0 ; i < 64 ; ++i)
		if(((1LL<<i)&n)!=0)
			++x;
	cout << (1LL<<x) << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}