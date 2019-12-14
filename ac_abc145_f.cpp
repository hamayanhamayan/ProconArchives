//https://atcoder.jp/contests/abc145/tasks/abc145_f
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
vector<int> compress1(int* v, int n, vector<int> def) {
	vector<int> dic(all(def));
	rep(i, 0, n) dic.push_back(v[i]);
	sort(all(dic));
	dic.erase(unique(all(dic)), dic.end());
	rep(i, 0, n) v[i] = lower_bound(all(dic), v[i]) - dic.begin();
	return dic;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/








int N, K, H[301];
ll dp[301][301][301];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> H[i];

	auto dic = compress1(H, N, { 0 });
	int M = dic.size();

	rep(i, 0, N + 1) rep(k, 0, K + 1) rep(h, 0, M) dp[i][k][h] = infl;
	dp[0][0][0] = 0;

	rep(i, 0, N) {
		rep(k, 0, K) rep(h, 1, M) chmin(dp[i + 1][k + 1][h], min(dp[i][k][h - 1], dp[i + 1][k + 1][h - 1]) + dic[h] - dic[h - 1]);
		rep(k, 0, K) {
			ll mi = infl;
			rrep(h, M - 1, 0) {
				chmin(mi, dp[i][k][h]);
				chmin(dp[i + 1][k + 1][h], mi);
			}
		}
		rep(k, 0, K + 1) rep(h, 0, M) chmin(dp[i + 1][k][H[i]], dp[i][k][h] + max(0, dic[H[i]] - dic[h]));
	}

	ll ans = infl;
	rep(k, 0, K + 1) rep(h, 0, M) chmin(ans, dp[N][k][h]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 必要知識
- 座標圧縮
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
必要な知見として高さを操作するが、最初に与えられているHiの高さにするか0にするかしかない。
中途半端なものに変更しても旨味がない。
あとは、Nの制約がとても小さいため、dp[300][300][300]かなーと思って考えるとDPが出てくる。

DP[i][k][h] := i行目までで、k回操作を行っていて、最後の列の高さがhである場合の必要な操作回数
DP[i][k][h]からdp[i+1][k+1][h2]への遷移ではh2≦hであれば追加コストはかからない。
これは、元々ある操作の一部を一列分拡張すればいいからである。
h<h2であればコストが差分だけかかる。
hは座標圧縮しないと状態数が足りない。

遷移が3つあるので、3つに分けて遷移させよう。

先にH[i]=hを片付けよう。
DP[i+1][k][h] = min(DP[i][k][全てのh]+max(0,H[i]-h)

DP[i][k][h]からdp[i+1][k+1][h2]への遷移では、h2≦hとなっている。
追加コストがかからないので、DP[i+1][k+1][h2] = min(DP[i][k][h2より大きい])
逆順で更新して、順番に最小値を持っていれば更新可能

h<h2の場合。
DP[i+1][k+1][h] = min(DP[i][k][h未満] + hとh未満の差)
差の計算が難しいが、結果は伝播させることができる。
実は、DP[i+1][k+1][h] = min(DP[i][k][h-1] + hとh-1の差, DP[i+1][k+1][h-1] + hとh-1の差)とできる。
これは
DP[i+1][k+1][h] = min(DP[i][k][h未満] + hとh未満の差)
をよく見ると、
DP[i+1][k+1][h] = min(DP[i][k][h-1] + hとh-1の差, min(DP[i][k][h-1未満] + hとh-1未満の差))
DP[i+1][k+1][h] = min(DP[i][k][h-1] + hとh-1の差, min(DP[i][k][h-1未満] + h-1とh-1未満の差) + hとh-1の差)
DP[i+1][k+1][h] = min(DP[i][k][h-1] + hとh-1の差, DP[i+1][k+1][h-1] + hとh-1の差)
という感じである。
あとは、これをまとめればいいが、h<h2は以前の結果を使用するので、これを最初にやって、残りをやっていく。
///////////////////////// writeup2 end */
