//https://atcoder.jp/contests/abc144/tasks/abc144_d
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














double A, B, X;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B >> X;

	double half = A * A * B / 2;
	double ans;

	if (X < half) ans = atan(A * B * B / (2.0 * X));
	else ans = atan((2.0 * B - 2.0 * X / (A * A)) / A);

	ans = ans / PI * 180;

	printf("%.10f\n", ans);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
数学的な問題のようだ。
0°の状態から傾けていくと、水の形は最初長方形だが、台形の柱となり、三角柱となりと遷移する。
三角柱になる前に溢れる可能性もあるが、この境目は体積の半分になる。
溢れる寸前の角度をθとする。

水が体積の半分より少ない場合は、三角柱となってから、ある角度でこぼれる。
溢れる寸前の時の底面の長方形がy×aになっているとすると、aby/2=xとなるので、y=2x/abである。
すると、tanθ=b/yなので、tanθ=ab^2/(2x)である。よって、θ=atan(ab^2/(2x))が答え。

水が体積の半分より多い場合は、台形の柱の状態で、ある角度でこぼれる。
作られる台形の切り取られている部分の長さbの辺の残りの部分をyとすると、
y=2b-2x/a^2となる。tanθ=y/aとなるので、θ=atan((2b-2x/a^2)/a)が答え。

atanは弧度法になってるので、/π*180で度数法に変換して答える。
///////////////////////// writeup2 end */
