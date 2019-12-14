//https://yukicoder.me/problems/no/900
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
    void add(int u, int v) { g[u].insert(v); g[v].insert(u); } void build() { dfs(0, -1); t = 0; dfs_hld(); }

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
template<class V, int NV> struct LazySegTree { // [L,R)
    vector<V> dat, lazy; LazySegTree() { dat.resize(NV * 2, def); lazy.resize(NV * 2, ldef); }
    void update(int a, int b, V v, int k, int l, int r) { push(k, l, r); if (r <= a || b <= l) return;
        if (a <= l && r <= b) { setLazy(k, v); push(k, l, r); } else {
        update(a, b, v, k * 2 + 1, l, (l + r) / 2); update(a, b, v, k * 2 + 2, (l + r) / 2, r);
        dat[k] = comp(dat[k * 2 + 1], dat[k * 2 + 2]);}}
    V get(int a, int b, int k, int l, int r) { push(k, l, r); if (r <= a || b <= l) return def;
        if (a <= l && r <= b) return dat[k]; auto x = get(a, b, k * 2 + 1, l, (l + r) / 2);
        auto y = get(a, b, k * 2 + 2, (l + r) / 2, r); return comp(x, y);}
    void update(int a, int b, V v) { update(a, b, v, 0, 0, NV); }
    V get(int a, int b) { return get(a, b, 0, 0, NV); }
    // ---- Template ---------------------------------------------------------------------------------
    
    // 区間add, 区間総和
    const V def = 0, ldef = 0;
    V comp(V l, V r) { return l + r; }
    void setLazy(int i, V v) { lazy[i] += v; }
    void push(int k, int l, int r) {
        dat[k] += lazy[k] * (r - l);
        if (r - l > 1) { setLazy(k * 2 + 1, lazy[k]); setLazy(k * 2 + 2, lazy[k]); }
        lazy[k] = ldef;
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















//---------------------------------------------------------------------------------------------------

int N, U[101010], V[101010], W[101010];
LazySegTree<ll, 1 << 17> st;
ll ans;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    HLDecomposition hld(N);
    rep(i, 0, N - 1) {
        cin >> U[i] >> V[i] >> W[i];
        hld.add(U[i], V[i]);
    }
    hld.build();

    rep(i, 0, N - 1) {
        int v = U[i];
        if (hld.depth[v] < hld.depth[V[i]]) v = V[i];
        st.update(hld.vid[v], hld.vid[v] + 1, W[i]);
    }

    int Q; cin >> Q;
    rep(q, 0, Q) {
        int t; cin >> t;
        if (t == 1) {
            int a, x;
            cin >> a >> x;
            st.update(hld.in[a], hld.out[a], x);
            st.update(hld.vid[a], hld.vid[a] + 1, -x);
        }
        else
        {
            int b;
            cin >> b;

            ans = 0;
            hld.foreach(0, b, [](int x, int y) {
                ans += st.get(x, y + 1);
            });
            printf("%lld\n", ans);
        }
    }
}





/* ///////////////////////// writeup1 start
- [HL分解](https://www.hamayanhamayan.com/entry/2017/04/10/172636)
- [遅延評価セグメントツリー(区間add,区間sum)](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
クエリを見ると部分木クエリとパスクエリになっている。
木に対して部分木もパスも行けるHL分解という手法がある。
HL分解を使って、部分木の全ての重みにxを加算し、パスの重みの総和を計算しよう。
辺にコストがあると扱いにくいので頂点に落としておくのがおすすめ。
辺のコストを端点の深さが深い方の頂点にうつしておく。
すると、部分木での操作は、部分木全体に+xして、部分木の根だけ-xすると辺に加算することになる。


HL分解を使えば、部分木もパスも区間に変換して考えることができる。
よって、区間に対してx加算と総和取得ができればいい。
これは遅延評価セグメントツリーを使えば実現できる。

ライブラリで殴っている感があるが、ライブラリで殴れる場合は殴っとこう。
///////////////////////// writeup2 end */
