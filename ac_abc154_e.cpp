//https://atcoder.jp/contests/abc154/tasks/abc154_e
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














string N; int K;
ll dp[101][2][5];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;

	int n = N.length();

	dp[0][0][0] = 1;
	rep(dgt, 0, n) rep(isless, 0, 2) rep(k, 0, K + 1) {
		int c = N[dgt] - '0';
		rep(nxt, 0, 10) {
			if (c < nxt && isless == 0) continue;

			int dgt2 = dgt + 1;
			int isless2 = isless;
			if (nxt < c) isless2 = 1;
			int k2 = k;
			if (nxt != 0) k2++;
			
			dp[dgt + 1][isless2][k2] += dp[dgt][isless][k];
		}
	}
	ll ans = dp[n][0][K] + dp[n][1][K];
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [桁DP](https://www.hamayanhamayan.com/entry/2017/04/23/212728
///////////////////////// writeup2 start
数がとても大きい上に、個数計算とのことなので桁DPをしよう。
数学的な解法がありそうな気もするが、自分は桁DPを実装した方が早いのでそっちでやった。

dp[dgt][isless][k] := dgt桁目まで確定していて、現時点でN以下であるかがislessであって、0でない数字がk個ある数の個数
これを一般的な桁DPの手法で計算する。
0と1～9の二通りで遷移を考えてもいいが、0～9の10通りで遷移するようにした方が実装が簡単になるので、
いつものように桁DPしよう。
///////////////////////// writeup2 end */
