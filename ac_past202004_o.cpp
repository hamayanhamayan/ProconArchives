//https://atcoder.jp/contests/past202004-open/tasks/past202004_o
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
struct UnionFind {
    vector<int> par; // uf(x,y)->y
    UnionFind() {}
    UnionFind(int NV) { init(NV); }
    void init(int NV) { par.clear(); rep(i, 0, NV) par.push_back(i); }
    void reset() { rep(i, 0, par.size()) par[i] = i; }
    int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
    void operator()(int x, int y) { x = operator[](x); y = operator[](y); if (x != y) par[x] = y; }
};
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
#define def 0
template<class V, int NV> struct SegTree { //[l,r)
    V comp(V& l, V& r) { return max(l, r); };

    vector<V> val; SegTree() { val = vector<V>(NV * 2, def); }
    V get(int x, int y, int l = 0, int r = NV, int k = 1) {
        if (r <= x || y <= l)return def; if (x <= l && r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); 
        auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);
        return comp(a, b);
    }
    void update(int i, V v) {
        i += NV; val[i] = v;
        while (i>1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
    }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
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














int N, M, A[101010], B[101010], C[101010];
bool used[101010];
SegTree<int, 1 << 17> st;
//---------------------------------------------------------------------------------------------------
int tmp;
void _main() {
    cin >> N >> M;
    rep(i, 0, M) cin >> A[i] >> B[i] >> C[i], A[i]--, B[i]--;

    UnionFind uf(N);
    ll tot = 0;
    vector<int> ord;
    rep(i, 0, M) ord.push_back(i);
    sort(all(ord), [&](int a, int b) { return C[a] < C[b]; });
    fore(i, ord) {
        int a = A[i];
        int b = B[i];
        int c = C[i];

        if (uf[a] != uf[b]) {
            uf(a, b);
            used[i] = true;
            tot += c;
        }
    }

    HLDecomposition hld;
    hld.init(N);
    rep(i, 0, M) if (used[i]) hld.add(A[i], B[i]);
    hld.build(0);

    rep(i, 0, M) if (used[i]) {
        int a = A[i];
        int b = B[i];
        int c = C[i];

        if (hld.depth[a] > hld.depth[b]) st.update(hld.vid[a], c);
        else st.update(hld.vid[b], c);
    }

    rep(i, 0, M) {
        if (used[i]) {
            printf("%lld\n", tot);
            continue;
        }

        int a = A[i];
        int b = B[i];
        int c = C[i];

        int lc = hld.lca(a, b);
        int tm = st.get(hld.vid[lc], hld.vid[lc] + 1);
        st.update(hld.vid[lc], 0);

        ll ans = tot + c;

        tmp = 0;
        hld.foreach(a, b, [&](int x, int y) {
            chmax(tmp, st.get(x, y + 1));
        });

        st.update(hld.vid[lc], tm);

        ans -= tmp;
        printf("%lld\n", ans);
    }
}





/* ///////////////////////// writeup1 start
# 前提知識
- [最小全域木](https://www.hamayanhamayan.com/entry/2018/09/17/163004)
///////////////////////// writeup2 start
どこから手を付けようか。
最小全域木を作る問題なので、既存の最小全域木アルゴリズムから考えてみる。
まず、自明な所として、普通に最小全域木を作成したとして、そこにある辺が含まれていれば、
その最小全域木を構成する重みの総和が答え。
そうでない辺があった場合は、作った最小全域木をベースにして改変することで最小全域木を作成する。
a-bをつなぐ辺を採用すると、木のある頂点をつなぐことになるので、1つのサイクルができる。
このサイクルから1辺を削除すると、木に戻ることができる。
なので、このサイクルからa-bを除く最も重みの大きい辺を選択できれば、
(最小全域木コスト)+(a-b)-(サイクルの最大辺)で答えを導ける。
このサイクルは、lc=lca(a,b)とおくと、a -> lc -> b -> aのサイクルになるので、
(a-lc)と(b-lc)の最大コスト辺を取ってくる問題となる。

つまり、木のあるパスについて最大辺がとってこれればいい。
これにはいくつかやり方がある。

公式解説には、「並列二分探索解」と「ダブリング」が紹介されている。
ダブリング解法が一番優しいと思う。

自分はHL分解+セグメントツリーで解いた。
データ構造でごり押した感じになる。
HL分解を使うと、木へのパスをO(logN)個の区間に分割することができる。
この各区間についてセグメントツリーで最大値を取ってきて、更に区間での最大値を取れば、パスの最大値になる。
類題を解いたことがあれば、この流れはそんなに難しくない。
（習得までが大変ですけど）
///////////////////////// writeup2 end */
