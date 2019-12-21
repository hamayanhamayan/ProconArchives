//https://www.hackerrank.com/contests/eeic-programming-contest-0/challenges/barrier-protection
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
const double EPS = 1e-8, INF = 1e12, PI = 2 * acos(0.0);
typedef complex<double> P;
namespace std {
    bool operator < (const P& a, const P& b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); } 
    bool operator == (const P& a, const P& b) { return abs(real(a) - real(b)) < EPS && abs(imag(a) - imag(b)) < EPS; }
    P operator / (const P& a, const double& b) { return P(real(a) / b, imag(a) / b); }
    P operator * (const P& a, const double& b) { return P(real(a) * b, imag(a) * b); }
}
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
struct L : public vector<P> { L() {} L(const P &a, const P &b) { push_back(a); push_back(b); } };
typedef vector<P> G;
struct C { P p; double r; C() {} C(const P &p, double r) : p(p), r(r) {} };
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return 0;       // counter clockwise
    if (cross(b, c) < 0)   return 1;       // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;
}
P rotate(P vec, double ang) {
    double x = real(vec), y = imag(vec);
    return P(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));
}
bool intersectLL(const L &l, const L &m) {
    return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS || // non-parallel
        abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;   // same line
}
bool intersectLS(const L &l, const L &s) {
    return cross(l[1] - l[0], s[0] - l[0])*       // s[0] is left of l
        cross(l[1] - l[0], s[1] - l[0]) < EPS; // s[1] is right of l
}
/*bool intersectLP(const L &l, const P &p) {
    return abs(cross(l[1] - p, l[0] - p)) < EPS;
} danger!*/
/*bool intersectSS(const L &s, const L &t) {
    return ccw(s[0], s[1], t[0])*ccw(s[0], s[1], t[1]) <= 0 &&
        ccw(t[0], t[1], s[0])*ccw(t[0], t[1], s[1]) <= 0;
} !!danger!! intersectLL -> crosspoint -> intersectSP  */
inline int sgn(double x) {
    if (x < -EPS) return -1;
    if (EPS < x) return 1;
    return 0;
}
inline int cmp(double x, double y) {
    return sgn(x - y);
}
bool intersectSP(const L &s, const P &p) {
    //return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS; // triangle inequality
    return cmp(abs(s[0] - p), 0.0) == 0 || cmp(abs(s[1] - p), 0.0) == 0 || ccw(s[0], p, s[1]) == -2;
}
/*bool intersectSSwithoutPoint(const L &s, const L &t) { // not verified
    return ccw(s[0], s[1], t[0])*ccw(s[0], s[1], t[1]) < 0 &&
        ccw(t[0], t[1], s[0])*ccw(t[0], t[1], s[1]) < 0;
} danger */
P crosspointLL(const L &l, const L &m) {
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
    if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
}
double argument(const P &a, const P &b) { // argument for A->B[-PI,PI]
    double ax = real(a), ay = imag(a), bx = real(b), by = imag(b);
    return atan2(by - ay, bx - ax);
}
// assumption : 3 <= ps.size()
G convex_hull(vector<P> ps) {
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	G ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) // upper-hull
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}


#define curr(PP, i) PP[i]
#define next(PP, i) PP[(i+1)%PP.size()]
G convex_cut(const G& g, const L& l) {
	G Q;
	for (int i = 0; i < g.size(); ++i) {
		P A = curr(g, i), B = next(g, i);
		if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
		if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0)
			Q.push_back(crosspointLL(L(A, B), l));
	}
	return Q;
}

enum { OUT, ON, IN };
int contains(const G& g, const P& p) {
	bool in = false;
	for (int i = 0; i < g.size(); ++i) {
		P a = curr(g, i) - p, b = next(g, i) - p;
		if (imag(a) > imag(b)) swap(a, b);
		if (imag(a) <= 0 && 0 < imag(b))
			if (cross(a, b) < 0) in = !in;
		if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
	}
	return in ? IN : OUT;
}
/*---------------------------------------------------------------------------------------------------
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












//---------------------------------------------------------------------------------------------------
void _main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1 << endl;
		return;
	}
	else if (N == 2) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

		if (intersectSP(L(P(x1, y1), P(x2, y2)), P(0, 0))) {
			cout << 2 << endl;
		}
		else {
			cout << 1 << endl;
		}
		return;
	}

	G convex;
	rep(i, 0, N) {
		int x, y; cin >> x >> y;
		convex.push_back(P(x, y));
	}

	convex = convex_hull(convex);

	if (contains(convex, P(0, 0)) == OUT) {
		cout << 1 << endl;
	}
	else {
		cout << 2 << endl;
	}
}





/* ///////////////////////// writeup1 start
# 前提知識
- [幾何の知識](https://www.hamayanhamayan.com/entry/2018/02/27/105814)
///////////////////////// writeup2 start
かなり自由に直線が引けるので、頂点を囲う三角形を作ればよさそう。
よって、3つあれば、必ず守れる。
いや、直線2つでもいけるな。
いける。
よって、あとは直線1つで身を守れるかを判定すればいい。
これは、2通りの方法がある。

1つ目は、凸包と多角形と点の包含関係を使う方法。
敵で凸法を作成したときに、その凸包に原点が含まれるかを判定する。
含まれないのであれば、直線を1つ引くことで原点を全ての敵を分離させることができる。
2つの機能のライブラリが必要となるが、既に持っている場合は。こちらで通すのが早い。

2つ目は、偏角を利用する方法。
原点から各敵について偏角を求める。
全ての偏角がある、180°の範囲に収まっていれば、直線で分離可能である。
偏角を求める部分はライブラリで持っておけばいいが、180°に収まるかの判定が少し大変。
ソートして尺取りとか、いろいろな工夫が必要になると思う。
///////////////////////// writeup2 end */
