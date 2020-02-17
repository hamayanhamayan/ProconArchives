//https://atcoder.jp/contests/abc155/tasks/abc155_e
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














string N;
int dp[1010101][2];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	reverse(all(N));

	int n = N.length();
	rep(i, 0, n + 1) rep(d, 0, 2) dp[i][d] = inf;
	dp[0][0] = 0;
	rep(i, 0, n) rep(d, 0, 2) if (dp[i][d] != inf) {
		int c = N[i] - '0';

		if (c == 9 and d == 1) chmin(dp[i + 1][1], dp[i][d]);
		else {
			if (d == 1) c++;

			chmin(dp[i + 1][0], dp[i][d] + c);
			chmin(dp[i + 1][1], dp[i][d] + 10 - c);
		}
	}

	int ans = min(dp[n][0], dp[n][1] + 1);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [桁DP](https://www.hamayanhamayan.com/entry/2017/04/23/212728)
///////////////////////// writeup2 start
制約を見ると、桁DPでよくみる制約となっている。
桁DPで考えてみると、解ける。
だが、珍しい形で下の桁から更新していくタイプである。

dp[i][d] := 下i桁目まで確定（支払い終えて）いて、次の桁に追加でd円払う必要があるときの使った紙幣の最小枚数
dがよくわからないと思うが、9円を払うときは10円で払うほうが効率がいい。
この例で言うと、下1桁目を確定させるときに9円払うか、より上位で1多く払ってもらって10-9円もらうかの二択になる。
このときに上位に払ってもらう金額を状態として持っている。
なので、dは0か1かしかない。

更新としてはさっきの条件を実装すればいい。
dは確定させたい桁に足してやればいい。
足した結果10だった場合は、特になにもできず上に任せるしかないので、場合分けしておこう。
最後の答えはd=1のときはまだツケを払い終えてないので、答えに+1して考える。
///////////////////////// writeup2 end */
