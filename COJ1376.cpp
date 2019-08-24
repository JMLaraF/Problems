#include <bits/stdc++.h>



using namespace std;
typedef long long ll;


int main()
{
	ll x , n , y = 0;
	vector<ll> v;
	cin >> x;
	ll cx = x;
	while(cx > 0)
	{
		v.insert(v.begin() , cx%10);
		cx /= 10;
	}
	next_permutation(v.begin() , v.end());
	ll py = 0 , pd = 1;
	for(int i = v.size() - 1 ; i >= 0  ; i--)
	{
		py += pd*v[i];
		pd *= 10;
	}
	if(py > x)
		y = py;

	cout << y << '\n';
}