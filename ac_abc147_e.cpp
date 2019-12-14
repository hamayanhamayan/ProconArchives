//https://atcoder.jp/contests/abc147/tasks/abc147_e
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















int H, W, A[80][80], B[80][80];
bitset<30101> dp[80][80];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) rep(x, 0, W) cin >> A[y][x];
	rep(y, 0, H) rep(x, 0, W) cin >> B[y][x];

	int base = 15000;
	dp[0][0].set(base + A[0][0] - B[0][0]);
	dp[0][0].set(base - A[0][0] + B[0][0]);

	rep(y, 0, H) rep(x, 0, W) {
		int d = abs(A[y][x] - B[y][x]);
		if (y) {
			dp[y][x] |= dp[y - 1][x] >> d;
			dp[y][x] |= dp[y - 1][x] << d;
		}
		if (x) {
			dp[y][x] |= dp[y][x - 1] >> d;
			dp[y][x] |= dp[y][x - 1] << d;
		}
	}

	int ans = inf;
	rep(d, 0, 30101) if (dp[H - 1][W - 1][d]) {
		chmin(ans, abs(d - base));
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- bitset
///////////////////////// writeup2 start
差の最小値を求めたい。
DPで「DP[y][x] := マス(x,y)までの経路での差の絶対値の最小値」みたいにしたいところだが、
その時点での途中で最小にすることが全体の最小に寄与するかは分からない。
制約も結構小さいので、網羅的に探索するのだろうと想像がつく。

制約に今までの差も入れてしまえば良さそう。
dp[y][x][d] := マス(x,y)までの経路で差d(=赤-青)の経路が存在するか
あえて偏りではなく、差を保存することにする。
絶対値は扱いにくくなることが多いので、できることなら絶対値が必要ない方で考えていくのが良い。
これを求めて、存在する絶対値の最小値を求めると答えなのだが、普通に作るとTLEするかもしれない。
なのでbitsetを使って高速化しよう。
あと、添字に負の数が含まれるかもしれないので、中心をずらしておこう。
///////////////////////// writeup2 end */
