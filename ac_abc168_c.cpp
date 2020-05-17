//https://atcoder.jp/contests/abc168/tasks/abc168_c
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
double cross(const P& a, const P& b) { return imag(conj(a) * b); }
double dot(const P& a, const P& b) { return real(conj(a) * b); }
struct L : public vector<P> { L() {} L(const P& a, const P& b) { push_back(a); push_back(b); } };
typedef vector<P> G;
struct C { P p; double r; C() {} C(const P& p, double r) : p(p), r(r) {} };
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
bool intersectLL(const L& l, const L& m) {
    return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS || // non-parallel
        abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;   // same line
}
bool intersectLS(const L& l, const L& s) {
    return cross(l[1] - l[0], s[0] - l[0]) *       // s[0] is left of l
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
bool intersectSP(const L& s, const P& p) {
    //return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS; // triangle inequality
    return cmp(abs(s[0] - p), 0.0) == 0 || cmp(abs(s[1] - p), 0.0) == 0 || ccw(s[0], p, s[1]) == -2;
}
/*bool intersectSSwithoutPoint(const L &s, const L &t) { // not verified
    return ccw(s[0], s[1], t[0])*ccw(s[0], s[1], t[1]) < 0 &&
        ccw(t[0], t[1], s[0])*ccw(t[0], t[1], s[1]) < 0;
} danger */
P crosspointLL(const L& l, const L& m) {
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
    if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
}
double argument(const P& a, const P& b) { // argument for A->B[-PI,PI]
    double ax = real(a), ay = imag(a), bx = real(b), by = imag(b);
    return atan2(by - ay, bx - ax);
}
// A->B->C時計回りの時の外角
// argument for A->B->C
double threePointArgumentTokei(const P& a, const P& b, const P& c) {
    P ba = b - a;
    P cb = c - b;

    double r1 = atan2(real(ba), imag(ba)) - PI / 2.0;
    while (r1 < -PI) r1 += 2 * PI;
    while (PI < r1) r1 -= 2 * PI;
    double r2 = atan2(real(cb), imag(cb)) - PI / 2.0;
    while (r2 < -PI) r2 += 2 * PI;
    while (PI < r2) r2 -= 2 * PI;

    //cout << id << "\t" << r1 << "\t" << r2 << endl;

    double range = 0;
    if (r1 >= 0 && r2 > 0) range = r2 - r1;
    else if (r1 < 0 && r2 >= 0) range = -r1 + r2;
    else if (r1 >= 0 && r2 < 0) range = (PI - r1) + (PI + r2);
    else range = r2 - r1;

    return range;
}
// A-B-Cの成す各のうち小さい方
double threePointArgument(const P& a, const P& b, const P& c) {
    double x = argument(b, a);
    double y = argument(b, c);

    double res = x - y;
    while (res < 0) res += PI * 2;
    while (PI * 2 <= res) res -= PI * 2;

    return min(res, 2 * PI - res);
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














int A, B, H, M;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B >> H >> M;

    P hour(0, A);
    P minute(0, B);

    double p;

    p = 1.0 * (H * 60 + M) / (12 * 60);
    hour = rotate(hour, 2 * PI * (1 - p));

    p = 1.0 * M / 60;
    minute = rotate(minute, 2 * PI * (1 - p));

    double ans = abs(hour - minute);
    printf("%.15f\n", ans);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [幾何](https://www.hamayanhamayan.com/entry/2018/02/27/105814)
///////////////////////// writeup2 start
ちょっとした幾何知識が必要。
余弦定理が想定解っぽいが、自分は回転を使って解いた。

固定する定点の座標を(0,0)とおくと、時針の先端は(0,A), 分針の先端は(0,B)のように表現できる。
H時間M分後の座標を考えてみると、
　時針→時計回りに360×(H*60+M)/(12*60)
  分針→時計回りに360×M/60
回転していることになる。
座標の回転はsin,cosで行えるので、適切にradianに変換して、座標を計算できる。
あとは、2つの座標の距離を計算すると答え。
///////////////////////// writeup2 end */
