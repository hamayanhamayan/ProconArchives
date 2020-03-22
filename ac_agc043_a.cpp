//https://atcoder.jp/contests/agc043/tasks/agc043_a
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















int H, W; string S[101];
int dp[101][101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) cin >> S[y];

	rep(y, 0, H) rep(x, 0, W) dp[y][x] = inf;
	dp[0][0] = 0;
	if (S[0][0] == '#') dp[0][0] = 1;

	rep(y, 0, H) rep(x, 0, W) {
		if (y + 1 < H) {
			if (S[y][x] == '.' && S[y + 1][x] == '#') chmin(dp[y + 1][x], dp[y][x] + 1);
			else chmin(dp[y + 1][x], dp[y][x]);
		}
		if (x + 1 < W) {
			if (S[y][x] == '.' && S[y][x + 1] == '#') chmin(dp[y][x + 1], dp[y][x] + 1);
			else chmin(dp[y][x + 1], dp[y][x]);
		}
	}

	cout << dp[H - 1][W - 1] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
左上から右下へのとある経路を考える。
この経路で移動しようと考えたときの必要な最小操作回数は「白→黒」となった回数である。
（スタートが黒なら+1する必要がある）
これに気づけるかが最も重要。

なぜ、これが最小回数かというと、黒に入って黒から出るパスを見てみると、
どれも長方形に収まるようになっている。

TODO:図

なので、この長方形に対して操作を行ってやると、このパス上はすべて白にできる。
よって、白→黒となった回数だけカウントすれば、それが操作回数になっている。
なぜ最小か？という部分については、ある長方形で操作を行うと、長方形内部では色の違いが起こらない。
なので、境界線の2箇所が色の違いを起こせる最大数となり、黒に入って黒から出るパスに対して行うと、
その最大数を毎回達成できるので、最小回数となる。

くどくど説明したが、以下のDPを作れば解ける。
dp[y][x] := 座標(x,y)にいるときの操作の最小回数
dp[y][x]からdp[y][x + 1]とdp[y + 1][x]を更新する。
この時、白→黒に移動するときのみ、操作回数を+1する。
dp[H-1][W-1]が答え。
///////////////////////// writeup2 end */
