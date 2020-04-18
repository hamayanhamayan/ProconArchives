//https://yukicoder.me/problems/no/1030
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
HLDecomposition hld;
#define def -1
template<class V, int NV> struct SegTree { //[l,r)
    V comp(V& l, V& r) { 
        if (l < 0) return r;
        if (r < 0) return l;
        return hld.lca(l, r);
    };

    vector<V> val; SegTree() { val = vector<V>(NV * 2, def); }
    V get(int x, int y, int l = 0, int r = NV, int k = 1) {
        if (r <= x || y <= l)return def; if (x <= l && r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2);
        auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);
        return comp(a, b);
    }
    void update(int i, V v) {
        i += NV; val[i] = v;
        while (i > 1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
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














int N, K, Q;
int C[101010], A[101010];
vector<int> E[101010];
SegTree<int, 1 << 17> st;
//---------------------------------------------------------------------------------------------------
void dfs(int cu, int pa = -1) {
    fore(to, E[cu]) if (to != pa) {
        chmax(C[to], C[cu]);
        dfs(to, cu);
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K >> Q;
    rep(i, 0, N) cin >> C[i];
    rep(i, 0, K) cin >> A[i];

    hld.init(N);
    rep(i, 0, N - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
        hld.add(a, b);
    }
    hld.build(0);

    dfs(0);

    rep(i, 0, K) st.update(i, A[i] - 1);

    rep(_, 0, Q) {
        int T; cin >> T;
        if (T == 1) {
            int X, Y; cin >> X >> Y;
            X--; Y--;
            st.update(X, Y);
        }
        else {
            int L, R; cin >> L >> R;
            L--;

            int ans = C[st.get(L, R)];
            printf("%d\n", ans);
        }
    }
}





/* ///////////////////////// writeup1 start
# 前提知識
- [LCAを載せたセグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
今回の問題はかみ砕くことで解きやすくなる。
問題で与えられている有向グラフは、根付き木として解釈することができる。
問題に書いてある、「会場は、上記のすべてのビーバーにとって到達可能な町にする。」とあるが、
この到達可能な町は、対象となるビーバーのLCAをとり、そのLCAである頂点から根である頂点までがすべて対象となる。
よって、引っ越しクエリを無視すれば、区間のLCAが取れれば、そこから根までのC[i]の最大値が答えになる。
これをやるために、「C[i] := i番目の町の活気」を事前にDFSをして、
「C[i] := i番目から根までの町の活気の最大値」のように変換しておこう。

あと残ったのは、区間LCAであるが、セグメントツリーが使える。
セグメントツリーの更新式にLCAを使うことで、区間LCAが取れる。
こうしておくことで、引っ越しクエリにも対応することができる。
///////////////////////// writeup2 end */
