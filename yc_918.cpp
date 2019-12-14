//https://yukicoder.me/problems/no/918
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
// トポロジカルソートする O(n)
// 返り値が true の時のみ意味を持つ(false の場合は閉路)
struct TopologicalSort {
	vector<vector<int>> E; TopologicalSort(int N) { E.resize(N); }
	void add_edge(int a, int b) { E[a].push_back(b); }
	bool visit(int v, vector<int>& order, vector<int>& color) {
		color[v] = 1;
		for (int u : E[v]) {
			if (color[u] == 2) continue; if (color[u] == 1) return false;
			if (!visit(u, order, color)) return false;
		} order.push_back(v); color[v] = 2; return true;
	}
	bool sort(vector<int>& order) {
		int n = E.size(); vector<int> color(n);
		for (int u = 0; u < n; u++) if (!color[u] && !visit(u, order, color)) return false;
		reverse(order.begin(), order.end()); return true;
	}
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int H, W, A[404], B[404];
int ans[404][404];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) cin >> A[y];
	rep(x, 0, W) cin >> B[x];

	sort(A, A + H, greater<int>());
	sort(B, B + W, greater<int>());

	TopologicalSort ts(H * W);
	rep(y, 0, H) {
		rep(x, 0, A[y] - 1) ts.add_edge(y * W + x, y * W + x + 1);
		rep(x, A[y] - 1, W - 1) ts.add_edge(y * W + x + 1, y * W + x);
	}
	rep(x, 0, W) {
		rep(y, 0, B[x] - 1) ts.add_edge(y * W + x, (y + 1) * W + x);
		rep(y, B[x] - 1, H - 1) ts.add_edge((y + 1) * W + x, y * W + x);
	}

	vector<int> ord;
	bool res = ts.sort(ord);
	assert(res);

	int num = 1;
	fore(i, ord) {
		int x = i % W;
		int y = i / W;

		ans[y][x] = num;
		num++;
	}

	rep(y, 0, H) {
		rep(x, 0, W) {
			if(x) printf(" ");
			printf("%d", ans[y][x]);
		}
		printf("\n");
	}
}





/* ///////////////////////// writeup1 start
# 前提知識
- [トポロジカルソート](https://www.hamayanhamayan.com/entry/2017/06/11/124732)
///////////////////////// writeup2 start
<blockquote class="twitter-tweet" data-partner="tweetdeck"><p lang="ja" dir="ltr">Eのお絵かきのようす <a href="https://t.co/oeQdMigeea">pic.twitter.com/oeQdMigeea</a></p>&mdash; satanic@競プロ🔥 (@satanic0258) <a href="https://twitter.com/satanic0258/status/1187745030284419072?ref_src=twsrc%5Etfw">October 25, 2019</a></blockquote>
<script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>
天才だ…わかり易すぎる

どう手をつけていいかわからない問題構築では、ある種の仮定をすることで解けるようになってくる。
今回であれば、最長増加列は前半部分に昇順で作り、後半は降順にする。
あと、数列A,Bは降順の状態で考えることにする。
すると、結果的に作られる大小関係は、satanicさんのような図になる。
賢い。

あとは、この大小関係を満たすように順列を割り当てていくだけだが、これにはトポロジカルソートを使おう。
ソート順で大きい数から割り当てていけば、構築できる。
///////////////////////// writeup2 end */
