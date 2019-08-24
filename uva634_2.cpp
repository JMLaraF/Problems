#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

// Definiciones iniciales.
typedef long double Double;
typedef long long Long;
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
  bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
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
  Linea(Long A, Long B, Long C)
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
  for (int i = 1; i < P.size(); ++i) {
    if( PuntoEnSegmento( p, Linea( P[i-1], P[i] ) ) ) return true;
  }
  return false;
}


int RayCasting(const Punto& p, const Poligono& P) {
  if (PuntoEnPerimetro(p, P)) return -1;
  Punto o = *min_element(P.begin(), P.end());
  Linea rayo(p, Punto(o.x - M_PI, o.y - M_E));
  int cruces = 0;
  for (int i = 1; i <= P.size(); ++i)
    if (InterseccionSegmentos(rayo,
      Linea(P[i - 1], P[i%P.size()]))) ++cruces;	
  return cruces & 1;
}


int main()
{
	Long n;
	cin >> n;
	while(n != 0)
	{
		Poligono p(n);
		Punto px;
		for(int i = 0 ;i < n ; i++)
			cin >> p[i].x >> p[i].y;
		cin >> px.x >> px.y;
		if(n < 2)
			cout << "F\n";
		else
		{
			bool ans = (RayCasting(px , p) > 0)? true : false;
			cout << ((ans)? "T\n": "F\n");
		}
		cin >> n;
	}


	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}
