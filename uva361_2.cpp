#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

// Definiciones iniciales.
typedef long double Double;
typedef long long ll;
typedef pair<int, int> pii;

const Double INF = 1ll << 60;
const Double ERROR = 1e-9;
const Double M_2PI = 2.0 * M_PI;

// Tolerancia a flotantes
#define EQ(a, b) (fabs((a) - (b)) < ERROR)

struct Punto {
  Double x, y;
  Punto() : x(), y() {}
  Punto(Double X, Double Y) : x(X), y(Y) {}
  // Izquierda a derecha, abajo a arriba.
  bool operator<(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? false: y < q.y;
  }
  bool operator<=(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? true: y < q.y;
  }
  bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
  }
   struct Punto &operator +=(const Punto &p2) 
	{
		x += p2.x;
		y += p2.y;
		return *this;
	}
	struct Punto &operator -=(const Punto &p2) 
	{
		x -= p2.x;
		y -= p2.y;
		return *this;
	}

  //Sumar los vectores actual y q.
  Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
  //Restar los vectores (o trasladarlos), tomando p como el origen.
  Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
  //Obtener el vector opuesto.
  Punto operator -() const { return Punto(-x, -y); }
  //Obtener el vector por un escalar.
  Punto operator*( Double c ) const { return Punto( x*c, y*c ); }
  //Obtener el vector dividido por un escalar.
  Punto operator/( Double c ) const { return Punto( x/c, y/c ); }
  //Magnitud del vector.
  Double Abs() const { return hypot(x, y); }
  //Magnitud elevada al cuadrado del vector.
  Double Norm() const{ return x*x + y*y; }
  //Distancia entre el punto actual y q.
  Double Dist( const Punto& q ) const { return (*this - q ).Abs(); }
  //Distancia elevada al cuadrado entre el punto actual y q.
  Double Dist2(const Punto& q ) const { return ( *this - q).Norm(); }
  //Producto punto entre el punto actual y q.
  Double Dot( const Punto& q ) const { return x*q.x + y*q.y; }
  //Producto cruz entre el punto actual y q.
  Double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }

  //Rotar 90 grados en CCW.
  Punto rot90() const { return Punto(-y, x); }

  //Rotar t radianes en cw respecto al origen.
  Punto RotarCW(const Double& t) const {
    return Punto( x*cos(t) + y*sin(t),
            y*cos(t) - x*sin(t));
  }
  //Rotar t radianes en ccw respecto al origen.
  Punto RotarCCW(const Double& t) const {
    return Punto( x*cos(t) - y*sin(t), 
            y*cos(t) + x*sin(t));
  }
};

int ManoDerecha(const Punto& o, const Punto& p, const Punto& q) {
  Double ccw = (p-o).Cruz(q-o);
  return EQ(ccw, 0)? 0: (ccw < 0)? -1: 1;
}


struct Linea {
  Punto p, q;
  Double a, b, c;
  Linea() : p(), q(), a(), b(), c() {}
  Linea(ll A, ll B, ll C)
    : p(), q(), a(A), b(B), c(C) {
    if (EQ(a, 0)) {
      c /= -b; b = -1;
      p = Punto(0, c);
      q = Punto(1, c);
    } else if (EQ(b, 0)) {
      c /= -a; a = -1;
      p = Punto(c, 0);
      q = Punto(c, 1);
    } else {
      p = Punto(-c/a, 0);
      q = Punto(-(b+c)/a, 0);
    } if (q < p) swap(p, q);
  }
  Linea(const Punto& P, const Punto& Q)
    : p(P), q(Q), a(), b(), c() {
    // Asegura p como punto menor.
    if (q < p) swap(p, q);
    a = q.y - p.y;
    b = p.x - q.x;
    if (!a) c = p.y, b = -1;
    else if (!b) c = p.x, a = -1;
    else c = -a*p.x - b*p.y;
  }
  // PELIGRO! Ordena por ecuacion de recta.
  bool operator<(const Linea& cmp) const {
    if (!EQ(a, cmp.a)) return a < cmp.a;
    if (!EQ(b, cmp.b)) return b < cmp.b;
    return EQ(c, cmp.c)? false: c < cmp.c;
  }
};

bool PuntoEnRecta(const Punto& p, const Linea& r){
  return !ManoDerecha( r.p, r.q, p );
}

bool PuntoEnSegmento(const Punto& p, const Linea& s) {
  return PuntoEnRecta(p, s) && !(p < s.p || s.q < p);
}

int InterseccionSegmentos(const Linea& s, const Linea& t) {
  int t1 = ManoDerecha(s.p, s.q, t.p);
  int t2 = ManoDerecha(s.p, s.q, t.q);

  if (t1 == t2) return t1? 0:
    (PuntoEnSegmento(s.p, t) ||
     PuntoEnSegmento(s.q, t) ||
     PuntoEnSegmento(t.p, s) ||
     PuntoEnSegmento(t.q, s))? -1: 0;

  return (ManoDerecha(t.p, t.q, s.p) !=
      ManoDerecha(t.p, t.q, s.q))? 1: 0;
}

typedef vector<Punto> Poligono;

bool PuntoEnPerimetro(const Punto& p, const Poligono& P) {
  for (int i = 1; i <= P.size(); ++i) {
    if( PuntoEnSegmento( p, Linea( P[i-1], P[i%P.size()] ) ) || p == P[i-1] ) return true;
  }
  return false;
}


int PuntoEnConvexo(const Punto& p, const Poligono& P) {
  if (PuntoEnPerimetro(p, P)) return -1;
  int dir = ManoDerecha(P[0], P[1], p);
  for (int i = 2; i <= P.size(); ++i)
    if (ManoDerecha(P[i - 1], P[i%P.size()], p)
      != dir) return 0; // Fuera.
  return 1; // Dentro.
}

bool grahamSort(Punto &p1 , Punto &p2)
{
	Punto px(500,0);
	return ((acos((px.Dot(p1))/(sqrt(p1.Norm())*500)) < acos((px.Dot(p2))/(sqrt(p2.Norm())*500))) || ((acos((px.Dot(p1))/(sqrt(p1.Norm())*500)) == acos((px.Dot(p2))/(sqrt(p2.Norm())*500))) && sqrt(p1.Norm()) > sqrt(p2.Norm())));
}

Poligono grahamScan (Poligono v)
{
	if(v.size() < 3)
		return Poligono();
	Punto px , pxx = v[0];
	for(int i = 1 ; i < v.size() ; i++)
	{
		if(v[i].y < pxx.y || (v[i].y == pxx.y && v[i].x < pxx.x))
		{
			pxx = v[i];
			v[i] = v[0];
			v[0] = pxx;
		}
	}
	for(int i = 1 ; i < v.size() ; i++)
			v[i] -= pxx;
	v[0] -= pxx;
	sort(v.begin() + 1 , v.end() , grahamSort);
	Poligono ans;
	ans.push_back(v[0] + pxx);
	ans.push_back(v[1] + pxx);
	px = v[0];
	Punto py = v[1] , pz;
	for(int i = 2 ; i < v.size() ; i++)
	{
		pz = v[i];
		if(((pz - py).Cruz(px - py)) > 0)
		{
			ans.push_back(pz + pxx);
			px = py;
			py = pz;
		}
		else if(((pz - py).Cruz(px - py)) < 0)
		{
			ans.pop_back();
			px = ans[ans.size() - 2] - pxx;
			py = ans[ans.size() - 1] - pxx;
			i--;
		}else
		{
			if(ans[ans.size() - 1].Norm() < (pz + pxx).Norm())
			{
				ans.pop_back();
				ans.push_back(pz + pxx);
			}
		}
	}
	if(ans.size() == 2)
	{
		if(ans[0] == ans[1])
			ans.pop_back();
	}
	return ans;
}


int main()
{
	ll p , l , c , d = 1 , a , b;
	Punto pc;
	cin >> p >> l >> c;
	while(!(p == 0 && l == 0 && c == 0))
	{
		a = false;
		b = false;
		cout << "Data set " << d++ << ":\n";
		Poligono pp(p);
		Poligono pl(l);
		for(int i = 0 ; i < p ; i++)
			cin >> pp[i].x >> pp[i].y;
		for(int i = 0 ; i < l ; i++)
			cin >> pl[i].x >> pl[i].y;
		if(p > 2)
			pp = grahamScan(pp);
		if(l > 2)
			pl = grahamScan(pl);

/*		for(int i = 0 ; i < pp.size() ; i++)
			cout << pp[i].x << " , " << pp[i].y << '\n';
		for(int i = 0 ; i < pp.size() ; i++)	
			cout << pl[i].x << " . " << pl[i].y << '\n';
*/		while(c--)
		{
			cin >> pc.x >> pc.y;
			if(p > 2 && pp.size() > 2)
				a = (PuntoEnConvexo(pc , pp) != 0);
			else if(p > 2 && pp.size() == 2)
			{
				a = PuntoEnSegmento(pc , Linea(pp[0] , pp[pp.size() - 1]));
			}else if(p > 2 && pp.size() == 1)
				a = (pc == pp[0]);

			if(l > 2 && pp.size() > 2)
				b = (PuntoEnConvexo(pc , pl) != 0);
			else if (p > 2 && pl.size() == 2)
			{
				b = PuntoEnSegmento(pc , Linea(pl[0] , pl[pp.size() - 1]));
			}else if (p > 2 && pl.size() == 1)
				b = (pc == pl[0]);
	//		cout << PuntoEnConvexo(pc , pp)  << '\n';
	//		cout << PuntoEnConvexo(pc , pl)  << '\n';	
			cout << "     Citizen at (" << (ll)pc.x << "," << (ll)pc.y << ") is ";
		if(a != 0 && p > 2)
			cout << "safe.\n";
		else if(b != 0 && l > 2)
			cout << "robbed.\n";
		else
			cout << "neither.\n";			
		}	
		cout << '\n';
		cin >> p >> l >> c;
	}

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}
