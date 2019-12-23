//https://atcoder.jp/contests/abc148/tasks/abc148_f
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
struct HLDecomposition {
	vector<set<int>> g; vector<int> vid, head, heavy, parent, depth, inv, in, out;
	HLDecomposition() {} HLDecomposition(int n) { init(n); }
	void init(int n) {
		g.resize(n); vid.resize(n, -1); head.resize(n); heavy.resize(n, -1);
		parent.resize(n); depth.resize(n); inv.resize(n); in.resize(n); out.resize(n);
	}
	void add(int u, int v) { g[u].insert(v); g[v].insert(u); }
	void build(int root) { dfs(root, -1); t = 0; dfs_hld(root); }

	int dfs(int curr, int prev) {
		parent[curr] = prev; int sub = 1, max_sub = 0;
		heavy[curr] = -1;
		for (int next : g[curr]) if (next != prev) {
			depth[next] = depth[curr] + 1;
			int sub_next = dfs(next, curr); sub += sub_next;
			if (max_sub < sub_next) max_sub = sub_next, heavy[curr] = next;
		}return sub;
	}

	int t = 0;
	void dfs_hld(int v = 0)
	{
		vid[v] = in[v] = t;
		t++;
		inv[in[v]] = v;
		if (0 <= heavy[v]) {
			head[heavy[v]] = head[v];
			dfs_hld(heavy[v]);
		}
		for (auto u : g[v]) if (depth[v] < depth[u])  if (u != heavy[v]) {
			head[u] = u;
			dfs_hld(u);
		}
		out[v] = t;
	}


	void foreach(int u, int v, function<void(int, int)> f) { // [x,y]
		if (vid[u] > vid[v]) swap(u, v); f(max(vid[head[v]], vid[u]), vid[v]);
		if (head[u] != head[v]) foreach(u, parent[head[v]], f);
	}
	int ancestor(int from, int times) {
		while (true) {
			if (depth[head[from]] > depth[from] - times) {
				times -= depth[from] - depth[head[from]] + 1; if (head[from] == 0)return -1; from = parent[head[from]];
			}
			else return inv[vid[from] - times];
		}
	}
	int lca(int u, int v) {
		if (vid[u] > vid[v]) swap(u, v); if (head[u] == head[v]) return u;
		return lca(u, parent[head[v]]);
	}
	int distance(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
	int child(int parent, int child, int times) {
		assert(depth[parent] < depth[child]);
		int d = distance(parent, child); assert(times - 1 <= d); return ancestor(child, d - times);
	}
	int go(int from, int to, int times) {
		int d = distance(from, to); assert(0 <= times and times <= d);
		int lc = lca(from, to); if (lc == to)return ancestor(from, times); if (lc == from)return child(from, to, times);
		int dd = distance(from, lc); if (dd <= times)return go(lc, to, times - dd); return ancestor(from, times);
	}
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, u, v;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> u >> v;
	u--; v--;

	HLDecomposition hld(N);
	rep(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--; b--;
		hld.add(a, b);
	}
	hld.build(u);

	int ans = 0;
	rep(leaf, 0, N) if (hld.g[leaf].size() == 1) {
		int lc = hld.lca(leaf, v);

		int taka = hld.distance(lc, u);
		int aoki = hld.distance(lc, v);

		if (aoki <= taka) continue;
		
		int taka2 = hld.distance(u, leaf);
		int aoki2 = hld.distance(v, leaf);

		int cnt = taka2;

		int d = aoki2 - taka2;
		cnt += d - 1;
		chmax(ans, cnt);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
色々考えることができそう。
以下解法は全探索しているが、色々なことを要求しているので、木へのライブラリを余り持ってない場合は、
ちょっと理解するに難しいかもしれない。

何か全探索できないだろうか。
性質として、青木くんは、なるべく高橋くんに接近するように動くのが良さそう。
つまり、高橋くんの移動ルートが決まれば青木くんの行動は一意に定まることになる。
なので、全探索すべきは高橋くんの行動であることになる。

高橋くんは最終的には追い詰められるわけで、木で追い詰められる所というと葉になる。
なので、全ての葉に対して高橋くんが目指した時にゲームが終了する回数を数えて最大のものが答えになる。
高橋くんがある葉に移動するときに、まず、その葉に到達できる可能性を考えてみる。
これは、高橋くんと青木くんが同時にその葉に向かったときに、パスが合流する頂点に高橋くんが1ターン先に
到達できる場合である。
同じターンに到達すると、高橋くん移動→青木くん移動となって、だめ。
この頂点を効率良く求めるには、LCAを使用する。
葉は毎回変わるが、高橋くんと青木くんは変わらない。
よって、高橋くんを根として、葉と青木くんのLCAを取る。
すると、合流地点が分かる。
（どこを根にしても問題ないかも）
各頂点間の距離はDFSしておけば、LCAと組み合わせることで計算可能。
自分はこの辺の木ライブラリを1つにまとめて上手いことしてあるので、ペタっと貼るだけ。

最後は青木んと葉の距離-高橋くんと葉の距離をdとしたときに、
d=1なら0, d=2なら1, d=3なら2, d=4なら3, d=5なら4, d=6なら5という感じなのでd-1だけ移動することになる。
///////////////////////// writeup2 end */
