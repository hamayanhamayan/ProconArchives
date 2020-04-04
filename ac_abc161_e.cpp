//https://atcoder.jp/contests/abc161/tasks/abc161_e
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














int N, K, C; string S;
int dp[201010];
vector<int> pre[201010];
bool vis[201010];
vector<int> dpt[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K >> C >> S;

	rep(i, 0, N + 1) dp[i] = -inf;
	dp[0] = 0;
	rep(i, 0, N) {
		if (chmax(dp[i + 1], dp[i])) pre[i + 1].clear();
		if (dp[i + 1] == dp[i]) pre[i + 1].push_back(i);

		if (S[i] == 'o') {
			if (chmax(dp[min(N, i + 1 + C)], dp[i] + 1)) pre[min(N, i + 1 + C)].clear();
			if (dp[min(N, i + 1 + C)] == dp[i] + 1) pre[min(N, i + 1 + C)].push_back(i);
		}
	}
	
	if (K < dp[N]) return;

	queue<int> que;

	vis[N] = true;
	que.push(N);

	while (!que.empty()) {
		int cu = que.front(); que.pop();
		fore(to, pre[cu]) {
			if (!vis[to]) {
				vis[to] = true;
				que.push(to);
			}

			if (dp[cu] == dp[to] + 1) {
				dpt[dp[to]].push_back(to + 1);
			}
		}
	}

	vector<int> ans;
	rep(i, 0, K) if (dpt[i].size() == 1) ans.push_back(dpt[i][0]);
	sort(all(ans));
	fore(a, ans) printf("%d\n", a);
}





/* ///////////////////////// writeup1 start
# 前提知識
- DPの復元
///////////////////////// writeup2 start
※ 本解説は、DPの復元が理解できてないとちょっと厳しいかもしれない

色々な方針が見える。
ある日で必ず働くということを考えるのは、少し難しいように思う。
もう少し見通しがよさそうな方向で考えると、ある日が働けないときにK日以上働けるかを判定する。
K日以上働けないなら、その日は必ずはたらかないと行けない。

ここまではいいのだが、ここから少し飛躍がある。
DPで最大で何日間働けるかを計算してみよう。

dp[i] := i日目を終えたときの最大の働いた日数
dp[i+1] <= dp[i]
dp[i+1+C] <= dp[i] + 1

このDPを計算すると、dp[N]が最大の働ける日数となる。
これが既にKよりも大きかった場合は、ある1日働かなくてもK日以上働けるので、答えはない。
dp[N]=Kの時の最適なパスを考えてみる。
つまり、dp[0]からdp[N]までの遷移の中で、dp[N]=Kとなる遷移のパスのことである。
このパスは一般にはDPから「復元」をする場合に使われる。
自分の実装では、dpの遷移元を記録しておくことで対応している。

今回の問題に置き換えて考えてみると、ある頂点を取り除くと、最適なパスが1つもなくなると
その頂点（＝その日）は絶対働く必要がある。

図

これを何とか見つけ出す必要があるが、dpテーブルを見ると、各頂点に対して最適に動いたときに
何日目の労働日になるかが書いてあるような感じになる。
（正確には労働した遷移の遷移先がそれにあたる）
最適パスの労働について見たときに、ある最適労働日が1つの頂点だけだった場合は、
それを削除すると、その労働日の労働がなくなるので、条件を満たさなくなる。
よって、最適労働日を集計して、1日だけならその日は必ず働く日となる。
///////////////////////// writeup2 end */
