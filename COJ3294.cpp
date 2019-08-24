#include <bits/stdc++.h>
#define xx first
#define yy second
#define pb push_back
#define forn(i, a, b) for(int i = a; i < b ; i ++)
#define all(x) (x).begin(), (x).end()
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
#define MAXN 6000005
using namespace std;


typedef long long int ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

vpll ST(400005,pll(0,0));
vll vec;
 bitset<MAXN> bs;
void criba()
{
    bs[0]= 1;
    bs[1]= 1;

    for(ll i = 2; i*i < MAXN;  i++){
        for(ll j = i*i; j < MAXN; j += i)
            bs[j] = 1;        
    }
}



pll update(ll v , ll l , ll r, ll x, ll z)
{
    if(x < l || x >= r)
        return ST[v];
    if(r-l == 1)
    {
        bool f = (bs[z] == 0);
        bool g = (bs[vec[x-1]] == 0);
        vec[x-1] = z;
        if((f && g))
        {
            return ST[v];
        }
        else if(f && !g)
        {
            ST[v].xx = 1;
            ST[v].yy = 0;
            return ST[v];
        }
        else if(!f && g)
        {
            ST[v].xx = 0;
            ST[v].yy = z;
            return ST[v];
        }else
        {
            ST[v].yy = max(ST[v].yy,z);
            return ST[v];
        }

    }else
    {
        ll m = (r+l)/2;
        pll aux1 = update(2*v,l,m,x,z);
        pll aux2 = update(2*v+1,m,r,x,z);
        ST[v].xx = aux1.xx+aux2.xx;
        ST[v].yy = max(aux1.yy,aux2.yy);
        return ST[v];
    }
}

pll query(ll v , ll l , ll r , ll x , ll y)
{
    if(y < l || x >= r)
        return pll(0,0);
    else if(x <= l && r-1 <= y)
    {
        return ST[v];
    }else
    {
         ll m = (r+l)/2;
        pll aux1 = query(2*v,l,m,x,y);
        pll aux2 = query(2*v+1,m,r,x,y);
        return pll(aux1.xx+aux2.xx,max(aux1.yy,aux2.yy));
    }
}

int main(){

    optimizar_io(0);
    criba();
    ll n , d , a , b , c;
    cin >> n >> d;
    vec.assign(n,0);
    forn(i,1,n+1)
    {
        cin >> a;
        update(1,1,n+1,i,a);
        vec[i-1]=a;
    }
    pll aux;
    while(d--)
    {
        cin >> a >> b >> c;
        if(a != 1)
        {   
            aux = query(1,1,n+1,b,c);
            if(a == 2)
            {   
                cout << aux.xx << '\n';
            }
            else
            {
                if(aux.yy != 0)
                    cout << aux.yy << '\n';
                else
                   cout << "NO ANSWER\n";
            }
        }else
            update(1,1,n+1,b,c);
    }

    return 0;
}