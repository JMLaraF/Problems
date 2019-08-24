#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vector<string> v;
bitset<100005> bs;

void criba()
{
	v.push_back("2");
	for(ll i = 3 ; i < 100000 ; i += 2)
	{
		if(bs[i] == 0)
			v.push_back(to_string(i));
		for(ll j = i*i ; j < 100000 ; j += i)
			bs[j] = 1;		
	}
}

int main()
{
	criba();
	string s;
	cin >> s;
	bool f = false;
	while(s != "0")
	{
		f = false;
		for(int x = v.size() - 1 ; x >= 0  && f == false  ; x--)
		{
			for(int i = 0 ; i + v[i].size() <= s.size() && f == false ; i++)
			{
				if(s.substr(i,v[x].size()) == v[x])
				{
					cout << v[x] << '\n';
					f = true;
				}
			}
		}
		cin >> s;
	}
	return 0;
}