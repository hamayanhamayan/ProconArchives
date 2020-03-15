//https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b
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














ll H, W;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;

	if (H == 1 or W == 1) {
		cout << 1 << endl;
		return;
	}

	ll ans = H * W / 2;
	if ((H * W) % 2 == 1) ans++;

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
問題文をみると、半分くらいのマスは移動できそうな感じがある。
なので、HW/2をベースに考えていこう。
小さいケースで見てみると、HWが奇数なら答えが1つ増える。
切り捨て分が答えになるためである。

…で出すとWA。
さすが、rngさん問題。ただでは通さない。
HかWが1の場合は全く動かすことができないので、答えは1になる。
これに気づくのは難しいと感じるかもしれないが、コーナーケースを探すときの初手は最も小さいパターンである。
まずは、小さいケースで考えてみよう。
///////////////////////// writeup2 end */
