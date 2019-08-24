#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define forn for(int i = 0 ; i < n ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

ll dp(ll n , ll x , vll &v)
{
    if(n == v.size())
    {
        if(x == 0)
            return 1;
        else
            return 0;
    }
    return max(dp(n+1,(x+v[n])%360,v),dp(n+1,(x+360-v[n])%360,v));
}

int main()
{_C
    ll n;
    cin >> n;
    vll v(n);
    forn
        cin >> v[i];
    cout << ((dp(0,0,v))?"YES":"NO") << '\n';
    #ifdef LOCAL
    //  cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}