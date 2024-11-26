#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair

const double EPS = 1e-9;
const double INF = 1e9; //1e18 tambien suele ir bien
using ll = long long int;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

vector<Point<double>> segInter(Point<double> a, Point<double> b, Point<double> c, Point<double> d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<Point<double>> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

bool resuelveCaso() {
    double a, b, ancho, alto;
    cin >> a >> b >> ancho >> alto;
    if(!cin) return false;
    if(a < b) swap(a, b);
    if(b > ancho || b > alto) {
        cout << "NO\n";
        return true;
    }
    bool ok = true;
    double incremento = 0.005;
    for(double alpha = incremento; ok && alpha < acos(-1) / 2; alpha += incremento) {
        Point<double> pa(b * sin(alpha), a * sin(alpha) + b * cos(alpha));
        Point<double> pb(b * sin(alpha) + a * cos(alpha), b * cos(alpha));
        vector<Point<double>> in_a = segInter(pa, pb, Point<double>(ancho, alto), Point<double>(ancho + a, alto));
        vector<Point<double>> in_b = segInter(pa, pb, Point<double>(ancho, alto), Point<double>(ancho, alto + a));
        Point<double> esquina(ancho, alto);
        if(sz(in_a) == 0 && sz(in_b) == 0) continue;
        set<Point<double>> s;
        if(sz(in_a) > 0) s.insert(in_a[0]);
        if(sz(in_b) > 0) s.insert(in_b[0]);
        s.insert(esquina);
        if(sz(s) > 1) ok = false;
        /*if(sz(in_a) > 0 && sz(in_b) == 0) {
            Point<double> xa = in_a[0];
            if((xa - esquina).dist() > EPS) {
                ok = false;
                continue;
            }
        }
        if(sz(in_b) > 0 && sz(in_a) == 0) {
            Point<double> xb = in_b[0];
            if((xb - esquina).dist() > EPS) {
                ok = false;
                continue;
            }
        }
        if(sz(in_a) > 0 && sz(in_b) > 0) {
            Point<double> xa = in_a[0];
            Point<double> xb = in_b[0];
            if((xa - esquina).dist() > EPS) {
                ok = false;
                continue;
            }
            if((xb - esquina).dist() > EPS) {
                ok = false;
                continue;
            }
            if((xa - xb).dist() > EPS) {
                ok = false;
                break;
            }
        }
        */
    }
    if(ok) cout << "SI\n";
    else cout << "NO\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}