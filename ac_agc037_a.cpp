//https://atcoder.jp/contests/agc037/tasks/agc037_a
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













string S;
int N;
int dp[201010][3];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;
	N = S.length();
	S += "####";

	rep(i, 0, N + 1) rep(pre, 0, 3) dp[i][pre] = -inf;
	dp[0][0] = 0;

	rep(i, 0, N) rep(pre, 0, 3) rep(d, 1, 3) if (0 <= dp[i][pre]) {
		if (pre == d) {
			if (d == 1) {
				if (S[i - 1] == S[i]) continue;
			}
			else {
				if (S[i - 2] == S[i] and S[i - 1] == S[i + 1]) continue;
			}
		}
		chmax(dp[i + d][d], dp[i][pre] + 1);
	}

	cout << max(dp[N][1], dp[N][2]) << endl;
}






/* ///////////////////////// writeup1 start
# 前提知識
- [DP](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
AGCの頭ということで貪欲で解きたい気持ちをこらえて解法を考える。
順位賞を見ると爆速で解いている人もいるが、結構落ちている人もいる。
こういう場合は、貪欲で落ちている人が多そうなので、ちゃんと考える。

今回は性質を見抜くのが本質であるが、ひらめきとしか言いようがない。
分割していくが、1文字か2文字で分割するのが最善手である。
よって、dp[i][pre] := i文字目まで使っていて、以前にpre文字分使用している。
これで1つ前の文字列が特定できるので、それと被るのを避けて遷移させればいい。
///////////////////////// writeup2 end */
