#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);


using namespace std;

typedef long long ll;


struct nodo
{
    ll h,hp,r,mx,p;
    bool f;
    set<ll> Fx;
    nodo()
    {
        h = 0;
        hp = 0;
        r1 = 0;
        r2 = 0;
        r3 = 0;
        mx = -1;
        p = -1;
    }
};


class Graph
{
    private:
        vector<nodo> v;
    public:
        Graph(ll n)
        {
            v(n,nodo());
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
            ll aux;
            queue cola;
            cola.push(0);
            set<ll>::iterator it;
            while(!cola.empty())
            {
                aux = cola.front();
                cola.pop();
                v[aux].mx = v[aux].h;
                if(v[aux].p != -1)
                {
                    if(v[v[aux].p].mx != -1)
                        if(v[v[v[aux].p].mx].h < v[aux].h)
                            v[v[aux].p].mx = aux;
                    else
                        v[v[aux].p].mx = aux;
                }
                for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
                {
                    if(*it == v[aux].p)
                        continue;
                    v[*it].p = aux;
                    v[*it].h--;
                    v[*it].hp = v[*it].h;
                }
            }
        }

        ll ans()
        {
        	ll maximo = 0;
            queue cola;
            for(int i = 0 ; i < v.size() ; i++)
                if(v[i].hp == 0)
                    cola.push(i);
            ll aux , r1 , r2;
            bool f = false;
            while(!cola.empty())
            {
                aux = cola.front();
                cola.pop();
                if(v[aux].h == 0)
                    continue;
                if(v[aux].p != -1)
                {
                    v[v[aux].p].hp--;
                    if(!v[v[aux].p].hp)
                        cola.push(v[aux].p)
                }

                set<ll>::iterator it;
                ll r = 0,s , r1 = 0 , r2 = 0;
                f = true;
                for(it = v[aux].Fx.begin() ; it != v[aux].Fx.end() ; it++)
                {
                    f &= v[*it].Fx.empty();
                    s = v[*it].r;
                    if(v[*it].f)
                    	s++;
                    r = max(s,r);
                    r2 = r;
                    if(r2 > r1)
                    	swap(r1,r2);
                }
                if(f)
                {
                	v[aux].f = true;
                	v[aux].r = max(v[aux].h-1,0);
                }else
                {
                	v[aux].r = r+v[aux].h-1;
                }
                maximo = max(r1+r2,maximo);
            }
            return maximo;   
        }
};
	
int main()
{
	ll n,a,b;
	Graph gp(n);
	n--;
	forn 
	{
		cin >> a >> b;
		gp.conect(--a,--b);
	}
	gp.rooted();
	cout gp.ans() << '\n';
	return 0;
}	
	
