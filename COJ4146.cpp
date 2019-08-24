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

struct nodo
{
    ll h,hp,r,p;
    bool f;
    set<ll> Fx;
    nodo()
    {
        h = 0;
        hp = 0;
        r = 0;
        p = -1;
        f = false;
    }
};


class Graph
{
    private:
        vector<nodo> v;
    public:
        Graph(ll n)
        {
            v.assign(n,nodo());
        }
        void conect(ll x , ll y)
        {
            v[x].Fx.insert(y);
            v[y].Fx.insert(x);
            v[x].h++;
            v[y].h++;
        }
        void rooted()
        {
            ll aux,i = 0;
            queue<ll> cola;
            while(v[i].h <= 1)
            	i++;
            cola.push(i);

    //        if(v[i].Fx.size() == 1)
    //        	v[i].f = true;
            set<ll>::iterator it;
            v[i].hp = v[i].h;
            while(!cola.empty())
            {
                aux = cola.front();
                cola.pop();
            /*    v[aux].mx = v[aux].h;
                if(v[aux].p != -1)
                {
                    if(v[v[aux].p].mx != -1)
                        if(v[v[v[aux].p].mx].h < v[aux].h)
                            v[v[aux].p].mx = aux;
                    else
                        v[v[aux].p].mx = aux;
                }*/
                for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
                {
                    if(*it == v[aux].p)
                        continue;
                    v[*it].p = aux;
                    v[*it].hp = v[*it].h-1;
                    cola.push(*it);
                }
            }
        }

        ll ans()
        {
        	ll maximo = 0 , maux;
            queue<ll> cola;
            for(int i = 0 ; i < v.size() ; i++)
                if(v[i].hp == 0)
                    cola.push(i);
            ll aux , r1 , r2;
            bool f = false;
            while(!cola.empty())
            {
            	maux = 0;
                aux = cola.front();
                cola.pop();
                if(v[aux].p != -1)
                {
                    v[v[aux].p].hp--;
                    if(v[v[aux].p].hp == 0)
                        cola.push(v[aux].p);
                }
                if(v[aux].h == 1)
                    continue;
               

                set<ll>::iterator it;
                ll r = 0,s , r1 = 0 , r2 = 0;
                f = true;
                for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
                {
                	if(*it == v[aux].p)
                		continue;
                    f &= (v[*it].h == 1);
                    s = v[*it].r;
                //    if(v[*it].f)
                //    	s++;
                    r = max(s,r);
                    r2 = s;
                    if(r2 > r1)
                    	swap(r1,r2);
                }
                if(f)
                	v[aux].r = v[aux].h-((v[aux].p!=-1)?1:0);
                else	
                	v[aux].r = r+v[aux].h-1-((v[aux].p!=-1)?1:0);
                if(v[aux].h-((v[aux].p!=-1)?1:0) > 1)
                	maux = r1+r2+v[aux].h-2;
                maux = max(maux,v[aux].r);
                maximo = max(maximo,maux);

                /*
                if()
                	v[aux].f = true;
                	v[aux].r = max(v[aux].h-1,(ll)0);
                }else
                {
                	v[aux].r = r+v[aux].h-1;
                	if(aux == 0 && v[aux].f)
                		v[aux].r++;
                }
                maximo = max(max(v[aux].r,r1+r2),maximo);
           */
            }
            return maximo;   
        }
};
	
int main()
{
	ll n,a,b;
	cin >> n;
	Graph gp(n);
	n--;
	forn 
	{
		cin >> a >> b;
		gp.conect(--a,--b);
	}
	if(n == 1)
	{
		cout << "0\n";	
	}
	if(n == 2)
	{
		cout << "1\n";
	}else
	{
		gp.rooted();
		cout << gp.ans() << '\n';	
	}


	
	return 0;
}	
	
