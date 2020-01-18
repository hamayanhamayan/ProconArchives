//https://yukicoder.me/problems/no/971
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














int H, W;
string A[2020];
int dp[2020][2020];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) cin >> A[y];

	rep(y, 0, H) rep(x, 0, W) dp[y][x] = inf;
	dp[0][0] = 0;

	rep(y, 0, H) rep(x, 0, W) {
		int d = A[y][x] == 'k' ? x + y : 0;
		if (x) chmin(dp[y][x], dp[y][x - 1] + 1 + d);
		if (y) chmin(dp[y][x], dp[y - 1][x] + 1 + d);
	}

	cout << dp[H - 1][W - 1] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、重要な性質に気づく必要がある。
「いたずらっ子によって最初の場所に戻されたとしても、始点から終点まで通るパスは、毎回同じである。」
戻されたときに違うルートを通った方が最適な場合は最初からそのルートを通るのが最適であるためである。

あとは、DPで計算していく。
dp[y][x] := 区間(y, x)に移動するのにかかる最短時間
移動はy++かx++しかないので、グラフはDAGとなる。
よって、ダイクストラまでは必要なく、DPで計算すればいい。
いたずらっ子によるロスタイムは、区間(y,x)で捕まったら、(x+y)である(x,yは0-indexed)。
///////////////////////// writeup2 end */
