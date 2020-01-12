//https://atcoder.jp/contests/abc151/tasks/abc151_f
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
bool onSameLine(const P& a, const P& b, const P& c) {
	return !intersectLL(L(a, b), L(b, c));
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
// 三点より中心導出
P three_P_circle(const P& a, const P& b, const P& c) {
	P x = 1.0 / conj(b - a), y = 1.0 / conj(c - a);
	return (y - x) / (conj(x) * y - x * conj(y)) + a;
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














int N;
P ps[50];
//---------------------------------------------------------------------------------------------------
bool check(P cent, double rad) {
	rep(i, 0, N) {
		double d = abs(ps[i] - cent);
		if (rad < d - EPS) return false;
	}
	return true;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) {
		int x, y; cin >> x >> y;
		ps[i] = P(x, y);
	}

	double ans = inf;
	rep(a, 0, N) rep(b, a + 1, N) {
		P cent = (ps[a] + ps[b]) / 2;
		double rad = abs(ps[a] - cent);
		if (check(cent, rad)) chmin(ans, rad);
	}
	rep(a, 0, N) rep(b, a + 1, N) rep(c, b + 1, N) if (!onSameLine(ps[a], ps[b], ps[c])) {
		P cent = three_P_circle(ps[a], ps[b], ps[c]);
		double rad = abs(ps[a] - cent);
		if (check(cent, rad)) chmin(ans, rad);
	}
	printf("%.18f\n", ans);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [幾何](https://www.hamayanhamayan.com/entry/2018/02/27/105814)
///////////////////////// writeup2 start
「最小包含円」という有名問題がある。
これと同義の問題であるが、これのよく知られている解法はガチ解法なので、もっと分かりやすい方を説明する。

自分は、[ここ](http://www.deqnotes.net/acmicpc/)でICPCの対策をしていたので、解法はすぐに思いついた（幾何特集の1番目の問題）。
これがない場合はどうやって思いつくかであるが、こういう選択肢が膨大にあるような問題ではある程度の仮定がないと話が進まないことがある。
今回でいうと、最適解は3点以上の点の上にあるとか、そういう仮定。

今回の問題の解法は「ある2点を結んだ線分を直径として持つ円、もしくは、ある3点を通る円のいずれかが半径最小の円となるので、全列挙」である。
解法自体は簡単だが、幾何ライブラリを持っている必要がある。
もし大学生以下でICPCに出る予定があるなら、整備しておく価値はあるだろう。

必要な要素としては、
- 2点間の距離
- 2点間の中点
- 3点を通る円の中心
があれば、解くことができる。
3番目が一番難しいと思うが、これは3点をつないでできる三角形の外心である。
2点ずつで垂直二等分線を求めて、交点を求めてもいいし、まあ、色々頑張る。
自分は、実装まで覚えていない（というかわかってないやつもあるかも）
頑張ってとしか…

あと、大小関係を比較するときにEPSを使った誤差軽減をする必要もある。
「幾何 誤差 EPS」みたいな感じにググると情報が出てくるが、自分は以下のように運用している。
小数の比較をするときに以下のように変換して使う誤差軽減法である。

const double EPS = 1e-8;
if(a <= b + EPS)		// a <= b
if(a < b - EPS)			// a < b
if(abs(a - b) < EPS)	// a == b

EPSを調整しないと通らない問題もあったりするが、最近は見かけていないので、もう無くなったのかな？
///////////////////////// writeup2 end */
