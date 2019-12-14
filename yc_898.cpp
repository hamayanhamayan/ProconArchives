//https://yukicoder.me/problems/no/898
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int N;
vector<pair<int, int>> E[101010];
int Q;
//---------------------------------------------------------------------------------------------------
HLDecomposition hld;
ll sm[101010];
void dfs(int cu, int pa = -1) {
    fore(p, E[cu]) {
        int to, c;
        tie(to, c) = p;

        if (pa == to) continue;
        sm[to] = sm[cu] + c;
        dfs(to, cu);
    }
}
ll get(int a, int b) {
    return sm[a] + sm[b] - 2LL * sm[hld.lca(a, b)];
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    
    hld.init(N);
    rep(i, 0, N - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
        E[b].push_back({a, c});
        hld.add(a, b);
    }

    hld.build();
    dfs(0);

    cin >> Q;
    rep(q, 0, Q) {
        int x, y, z;
        cin >> x >> y >> z;

        ll ans = 0;
        ans += get(x, y);
        ans += get(y, z);
        ans += get(z, x);
        ans /= 2;

        printf("%lld\n", ans);
    }
}

/* ///////////////////////// writeup1 start
# 前提知識
- [LCA](https://www.hamayanhamayan.com/entry/2017/05/03/131624)
///////////////////////// writeup2 start
頂点数が最小で連結な部分グラフを持ってくるが、
これはx-y, x-z, y-z間の最小パスで使われる頂点を集めたものになる。
これは直感的に分かるかもしれない。
ここで、x->y->z->xのように一筆書きをしてみると、全ての辺はちょうど2回ずつ通っている。
そのため、
(x->yでのパスの重みの総和) + (y->zでのパスの重みの総和) + (z->xでのパスの重みの総和)
の半分が答えになる。
あとは、パスの重みの総和を高速に計算する方法が分かれば解ける。

これは典型問題で、LCAとDFSを使って解くのが、常套。
LCAが分からない場合は、先にどこかで勉強しよう。
(a->bでのパスの重みの総和)は、まず、aとbのLCAを計算する。
LCAをlca(a,b)とすると、(a->bでのパスの重みの総和)は、
(0->aでのパスの重みの総和) + (0->bでのパスの重みの総和) - 2*(0->lca(a,b)でのパスの重みの総和)
となる。
(0->aでのパスの重みの総和)は、DFSをして前計算しておく。
自分のプログラムでは
sm[a] := 0->aでのパスの重みの総和
としている。
///////////////////////// writeup2 end */
