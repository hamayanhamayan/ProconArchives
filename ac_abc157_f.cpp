//https://atcoder.jp/contests/abc157/tasks/abc157_f
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
// A->B->C時計回りの時の外角
// argument for A->B->C
double threePointArgumentTokei(const P &a, const P &b, const P &c) {
    P ba = b - a;
    P cb = c - b;

    double r1 = atan2(real(ba), imag(ba)) - PI / 2.0;
    while (r1<-PI) r1 += 2 * PI;
    while (PI<r1) r1 -= 2 * PI;
    double r2 = atan2(real(cb), imag(cb)) - PI / 2.0;
    while (r2<-PI) r2 += 2 * PI;
    while (PI<r2) r2 -= 2 * PI;

    //cout << id << "\t" << r1 << "\t" << r2 << endl;

    double range = 0;
    if (r1 >= 0 && r2>0) range = r2 - r1;
    else if (r1<0 && r2 >= 0) range = -r1 + r2;
    else if (r1 >= 0 && r2<0) range = (PI - r1) + (PI + r2);
    else range = r2 - r1;

    return range;
}
// A-B-Cの成す各のうち小さい方
double threePointArgument(const P &a, const P &b, const P &c) {
    double x = argument(b, a);
    double y = argument(b, c);

    double res = x - y;
    while (res < 0) res += PI * 2;
    while (PI * 2 <= res) res -= PI * 2;

    return min(res, 2 * PI - res);
}
pair<P, P> circle_circle_intersect(
    const P& c1, const double& r1, const P& c2, const double& r2) {
    P A = conj(c2-c1), B = (r2*r2-r1*r1-(c2-c1)*conj(c2-c1)), C = r1*r1*(c2-c1);
    P D = B*B-4.0*A*C;
    P z1 = (-B+sqrt(D))/(2.0*A)+c1, z2 = (-B-sqrt(D))/(2.0*A)+c1;
  return pair<P, P>(z1, z2);
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/















int N, K, X[60], Y[60], C[60];
P points[60];
//---------------------------------------------------------------------------------------------------
bool check(double time) {
    vector<P> cand;
    rep(i, 0, N) cand.push_back(points[i]);
    rep(a, 0, N) rep(b, a + 1, N) {
        auto vp = circle_circle_intersect(points[a], time / C[a], points[b], time / C[b]);
        cand.push_back(vp.first);
        cand.push_back(vp.second);
    }

    fore(c, cand) {
        int cnt = 0;
        rep(i, 0, N) {
            double req = abs(c - points[i]) * C[i];
            if (req <= time + EPS) cnt++;
        }
        if (K <= cnt) return true;
    }
    return false;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> X[i] >> Y[i] >> C[i];
    rep(i, 0, N) points[i] = P(X[i], Y[i]);

    double ng = 0, ok = infl;
    rep(_, 0, 101) {
        double md = (ng + ok) / 2;
        if (check(md)) ok = md;
        else ng = md;
    }
    printf("%.10f\n", ok);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [幾何問題](https://www.hamayanhamayan.com/entry/2018/02/27/105814)
///////////////////////// writeup2 start
まず、答えである最小時間であるが、最小時間を境にしてokとngが分かれているので、
答えとなる必要な最小時間で二分探索をしよう。

時間が固定になると嬉しいことがある。
ci * (ある点と熱源との距離) = 時間
となっているが、これが、
(ある点と熱源との距離) = 時間 / ci
のように変形でき、ある点に対して熱源を置ける場所が円の中に限定される。
よって、あとは、そうして作ったすべての円に対して、共通領域を求め、その面積が0より大きければ、
その最小時間で熱源を配置できるということになる。
…が、円の合成はあきらかに難しそう。

ICPCなどで幾何問題に慣れている人はここから発想の飛躍ができる。
熱源は極端なところに置いておけばいいのではないか？
具体的には円と円の交点に置けばよいのではないか？
幾何問題全般で言える話であるが、実数で座標を扱う場合は、候補が極端に多くなる。
なので、一定の仮定を置かないと解けない場合がほとんど。
その時に使う仮定が、大体交点とか接点とかである。
理屈としては、うまいこと移動させたり、境界ギリギリを狙うと、接点になるとか、そういう理屈。
なので、熱源として以下の候補をチェックして、その熱源を使って焼ける肉がK枚以上あれば、その時間はtrue。

- 肉の座標
- ある2つの肉の円が作る交点

EPSを使わないと誤差で死ぬ。
具体的には、A≦Bと書きたいときは、A≦B+EPSとしてやらないと死ぬ。
自分はEPS=1^(-8)でやってる。
///////////////////////// writeup2 end */
