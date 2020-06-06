//https://atcoder.jp/contests/past202005-open/tasks/past202005_h
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














int N, L;
bool existHurdle[101010];
int T1, T2, T3;
int dp[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> L;
	rep(i, 0, N) {
		int x; cin >> x;
		existHurdle[x] = true;
	}
	cin >> T1 >> T2 >> T3;

	rep(i, 0, L + 101) dp[i] = inf;
	dp[0] = 0;

	rep(i, 0, L) {
		// 行動1
		chmin(dp[i + 1], dp[i] + T1 + (existHurdle[i + 1] ? T3 : 0));

		// 行動2
		chmin(dp[i + 2], dp[i] + T1 + T2 + (existHurdle[i + 2] ? T3 : 0));

		// 行動3
		chmin(dp[i + 4], dp[i] + T1 + T2 * 3 + (existHurdle[i + 4] ? T3 : 0));
	}

	int ans = dp[L];
	if (0 <= L - 1) chmin(ans, dp[L - 1] + (T1 + T2) / 2);
	if (0 <= L - 2) chmin(ans, dp[L - 2] + (T1 + T2) / 2 + T2);
	if (0 <= L - 3) chmin(ans, dp[L - 3] + (T1 + T2) / 2 + T2 * 2);
	cout << ans << endl;
}




/* ///////////////////////// writeup1 start
# 前提知識
- [DP](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
DPで解く。
なんでDPって分かるんだ！という話であるが、
- N≦10^5で最小値、DPかな？
- 行動によって単一方向にしか進まない（DAG性）
みたいな所から、DPを作ってみて考えると、解けるねとなりました。

dp[i] := 座標iにいるときのかかった秒数最小値（ハードルがあるときは越えているものとする）
かっこに書いてある条件が重要でこの辺をうやむやにするとバグりまくる。

基本的な遷移はコードを見てもらった方が早いと思う。
行動1ではT1秒かかり、行動2ではT1+T2秒かかり、行動3ではT1+3×T2秒かかる。
だが、移動先にハードルがある場合は超えないといけないので、追加でT3秒かかる。
みたいなコードを書く。
で、最後にdp[L]が答え…といきたいが、コーナーケースがある。
問題文にも書かれているが、ジャンプ中の通過時間も答えになりうるようだ。
なので、L-1地点から行動2をしたとき、L-2,L-3地点から行動3をしたときはジャンプ中に座標Lを越えるので、
その場合について最小値確認をして、答えとする。
///////////////////////// writeup2 end */
