//https://atcoder.jp/contests/abc152/tasks/abc152_f
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
// vid : id -> vid          head, heavy, parent : unused
// depth : id -> depth      inv : vid -> id
// in(vid), out(vid) : for euler tree [in[v], out[v])
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
        for (auto u : g[v]) if(depth[v] < depth[u])  if (u != heavy[v]) {
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
        assert(depth[parent]<depth[child]);
        int d = distance(parent, child); assert(times - 1 <= d); return ancestor(child, d - times);
    }
    int go(int from, int to, int times) {
        int d = distance(from, to); assert(0 <= times and times <= d);
        int lc = lca(from, to); if (lc == to)return ancestor(from, times); if (lc == from)return child(from, to, times);
        int dd = distance(from, lc); if (dd <= times)return go(lc, to, times - dd); return ancestor(from, times);
    }
};
#ifdef _MSC_VER
inline unsigned int __builtin_popcount(unsigned int x) { return __popcnt(x); }
#endif // _MSC_VER
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M;
ll po[51];
bitset<50> pre[20];
//---------------------------------------------------------------------------------------------------
void _main() {
	po[0] = 1;
	rep(i, 1, 51) po[i] = po[i - 1] * 2;

	cin >> N;
	HLDecomposition hld(N);
	rep(i, 0, N - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		hld.add(a, b);
	}
	hld.build(0);

	cin >> M;
	rep(i, 0, M) {
		int u, v;
		cin >> u >> v;
		u--; v--;

		while (u != v) {
			int to = hld.go(u, v, 1);

			if(hld.depth[u] > hld.depth[to]) pre[i].set(u);
			else pre[i].set(to);
			
			u = to;
		}
	}

	ll ans = 0;
	rep(msk, 0, 1 << M) {
		int p = __builtin_popcount(msk) % 2;
		
		bitset<50> white;
		rep(i, 0, M) if (msk & (1 << i)) white |= pre[i];

		int rest = N - 1 - white.count();
		if (p == 0) ans += po[rest];
		else ans -= po[rest];
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [包除原理](https://www.hamayanhamayan.com/entry/2017/04/17/161345)
///////////////////////// writeup2 start
条件の弱い所を探すと、N=50, M=20である。
N=50はまあまあ見るのでいいとして、M=20がどう見ても不自然。
ここから考え出す。
20というと、2^20が通るなという感じであり、数え上げで、満たすべき制約について…
包除原理である。

包除原理を用いると答えは以下のように求めることができる。
(制約を最低0個満たしていない)-(制約を最低1個満たしていない)+(制約を最低2個満たしていない)-...
これで計算する方針で考えよう。
2^Mで制約を満たす満たさないの全パターンを見て、組み合わせを計算し、引くか足すかしていく。

あるmskの集合の制約は満たさないと考えると、その集合に含まれる経路は全部白にする必要がある。
それで、それ以外の部分は何色でもいいので、適当に塗る組み合わせを考える。
これで、集合の個数がcntであるとすると、「制約を最低cnt個満たしていない」組み合わせが得られる。
その集合に含まれる経路に使われる辺の個数をwhite.countとすると、全部でN-1本なので、
rest(=N-1-white.count)本がどっちでも塗れる。
なので、組み合わせは2^rest通り。

最後に残ったのは、その集合に含まれる経路の辺の本数をどう数えるかである。
自分は元々ライブラリ化してあるLCAを使って木上を移動するやつを使った。
なくても、前計算できるので、dfsとかで最短経路を見つけて、戻りながら辺を集計すればできそう。
どの辺を使ったかをこちらも集合で記録しておこう。
pre[i] := i番目の制約で使用する辺の集合
これを用意しておくことで、ある集合に含まれる経路の辺集合は、集合のpreのOR和となるので便利。
50なのでllでもいいが、bitsetだとカウントできるからこっちを自分は使った。

色々前計算しないとTLEするので注意。
///////////////////////// writeup2 end */
