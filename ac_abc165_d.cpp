//https://atcoder.jp/contests/abc165/tasks/abc165_d
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














ll A, B, N;
//---------------------------------------------------------------------------------------------------
ll f(ll x) { return (A * x) / B - A * (x / B); }
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B >> N;

	ll ans = 0;
	chmax(ans, f(N));
	if (B - 1 <= N) chmax(ans, f(B - 1));
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
D問題にしては難しい問題に見えるし、計算過程に実数も入ってくるので、とりあえず実験コードを書いてみる。
xを[0,N]に動かして何か発見が無いか探してみる。
すると、計算式の値はmod Bで周期性があるみたいだ。
かつ、x = B-1(mod B)のときに最大値を取る。
なので、最大値の候補は、x=B-1かx=Nのどちらかとなる。
B-1≦Nとなっているかに注意しつつ、どちらも計算して大きい方を答えよう。
floorは切り捨てなので、整数計算で割り算をすることで代用できる。
実数を介すのは危険なので、整数計算で乗り切ろう。
///////////////////////// writeup2 end */
