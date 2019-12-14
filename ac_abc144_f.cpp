//https://atcoder.jp/contests/abc144/tasks/abc144_f
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














int N, M;
vector<int> E[601];
double dp[601], dp2[601];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		E[a].push_back(b);
	}

	rrep(cu, N - 2, 0) {
		fore(to, E[cu]) dp[cu] += dp[to];
		dp[cu] /= (int)E[cu].size();
		dp[cu] += 1;
	}

	double ans = dp[0];

	rep(stop, 0, N - 1) {
		rep(i, 0, N) dp2[i] = dp[i];
		rep(i, 0, stop + 1) dp2[i] = 0;

		int sz = E[stop].size();
		if (2 <= sz) {
			vector<double> v;
			fore(to, E[stop]) v.push_back(dp2[to]);
			sort(all(v));

			rep(i, 0, sz - 1) dp2[stop] += v[i];
			dp2[stop] /= sz - 1;
			dp2[stop] += 1;
		}
		else continue;

		rrep(cu, stop - 1, 0) {
			fore(to, E[cu]) dp2[cu] += dp2[to];
			dp2[cu] /= E[cu].size();
			dp2[cu] += 1;
		}
		chmin(ans, dp2[0]);
	}

	printf("%.10f\n", ans);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
グラフ全体はDAGになっているので、期待値DPをすることで答えが求まる。
まずは、通路を塞がないパターンを考えてみよう。
dp[cu] := 部屋curから部屋Nへ移動するのにかかる移動回数の期待値
dp[cu] = (dp[to1] + dp[to2] + ... + dp[toM]) / M + 1
これでdp[0]が答えになる。
これも見ると、大きい数から順番に確定させていけばよさそう。
とりあえず、通常DPをしよう。

さて、あとは塞がれる道だが、全探索するとO(M)となり、改めてDPするとO(M^2)で間に合わない。
ある道を塞ぐと、s[i]への遷移がなくなる。
言い換えると、s[i]への遷移しか影響しない。
よって、ある頂点cuについてs[i]=cuを満たす道について考える。
この中で最適に道を消して最終的な期待値を最小化したいので、もっとも遷移先のdpの値が大きいものを消すのが最適。
これで、塞ぐべき道がO(M)からO(N)に減ったので、O(NM)となり間に合う。
///////////////////////// writeup2 end */
