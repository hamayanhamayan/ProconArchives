//https://atcoder.jp/contests/abc143/tasks/abc143_e
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














int N, M, L, Q;
ll D[303][303];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> L;
	rep(i, 0, N) rep(j, 0, N) {
		if (i != j) D[i][j] = infl;
		else D[i][j] = 0;
	}
	rep(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		D[a][b] = D[b][a] = c;
	}
	rep(k, 0, N) rep(i, 0, N) rep(j, 0, N) chmin(D[i][j], D[i][k] + D[k][j]);

	rep(i, 0, N) rep(j, 0, N) {
		if (i != j) {
			if (D[i][j] <= L) D[i][j] = 1;
			else D[i][j] = infl;
		}
		else D[i][j] = 0;
	}
	rep(k, 0, N) rep(i, 0, N) rep(j, 0, N) chmin(D[i][j], D[i][k] + D[k][j]);

	cin >> Q;
	rep(q, 0, Q) {
		int s, t; cin >> s >> t; s--; t--;

		ll ans = D[s][t];
		if (ans == infl) ans = -1;
		else ans--;
		printf("%lld\n", ans);
	}
}





/* ///////////////////////// writeup1 start
# 前提知識
- [ワーシャルフロイド](https://www.hamayanhamayan.com/entry/2017/05/14/134606)
///////////////////////// writeup2 start
問題としては最短経路問題に似ている。
似ているが、燃料が足りなくなったらコストが1かかるという部分。
燃料補給する場合は一杯になるまで補給すればいい。
今のグラフを元に新たに今回答えるべき答えに即したグラフに作り直そう。
具体的には、頂点aから頂点bに補給無しで移動できるならコスト1の辺、移動できないならコスト∞の辺のグラフにする。
この辺の言い換えが思いついた理由を説明するのは難しいのだが、思い当たる節でいうと

- N≦300で最短経路問題はワーシャルフロイドが思い当たる。だが今の辺のコストでやっても意味がない
- 順当に考えるとダイクストラが思い当たるが、最小化したい変数が(補給回数, 残り燃料)でちょっと大変
- 何故かクエリ問題になっている（前計算させるってことは全頂点間での値が欲しい？やっぱワーシャルフロイドか？）

さて、解法にもどると、
「頂点aから頂点bに補給無しで移動できるならコスト1の辺、移動できないならコスト∞の辺のグラフ」を作る。
あとは、これでワーシャルフロイドをして、各クエリではD[s][t]-1を答えればいい。
街tiに着いたときに燃料補給する必要はないからである。
///////////////////////// writeup2 end */
