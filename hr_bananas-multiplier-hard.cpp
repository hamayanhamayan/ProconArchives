//https://www.hackerrank.com/contests/yfkpo3-1/challenges/bananas-multiplier-hard
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
template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
typedef ModInt<1000000007> mint;
/*---------------------------------------------------------------------------------------------------
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












int N, Q;
vector<pair<int, int>> E[101010];
mint tot[101010];
//---------------------------------------------------------------------------------------------------
void dfs(int cu = 0, int pa = -1, mint to = 1) {
    tot[cu] = to;
    fore(p, E[cu]) {
        if (p.first == pa) continue;
        dfs(p.first, cu, to * p.second);
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;

    HLDecomposition hld;
    hld.init(N);
    rep(i, 0, N - 1) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        hld.add(u, v);
        E[u].push_back({ v, c });
        E[v].push_back({ u, c });
    }
    hld.build(0);

    dfs();
    cin >> Q;
    rep(_, 0, Q) {
        int m, p, x;
        cin >> m >> p >> x;
        m--; p--;

        int lca = hld.lca(m, p);
        mint ans = tot[m] * tot[p] / tot[lca] / tot[lca] * x;
        printf("%d\n", ans.get());
    }
}





/* ///////////////////////// writeup1 start
# Om
- iԂzjLCA, ݐϘaۂݐϐ
- ̉@ƁAHLASparseTable
///////////////////////// writeup2 start
̉@͂ǂĂI[o[LȂ̂ŁA܂QlɂȂĂB
HLgƁA؂̃pXɂăZOgc[ōs悤ȑ삪sB
āAgƁApX̏d݂̐ςvZłāAoii̐Γ܂B
HLSparseTable𗝉΁Agݍ킹邾ŉƂłB

```cpp
int N, U[101010], V[101010], C[101010];
SparseTable<mint> st;
int Q;
mint ans = 1;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    HLDecomposition hld;
    hld.init(N);
    rep(i, 0, N - 1) {
        cin >> U[i] >> V[i] >> C[i];
        U[i]--; V[i]--;
        hld.add(U[i], V[i]);
    }
    hld.build(0);

    vector<mint> v(N, 1);
    rep(i, 0, N - 1) {
        if (hld.depth[U[i]] < hld.depth[V[i]]) v[hld.vid[V[i]]] = C[i];
        else v[hld.vid[U[i]]] = C[i];
    }
    st.init(v);

    cin >> Q;
    rep(_, 0, Q) {
        int m, p, x; cin >> m >> p >> x;
        m--; p--;

        ans = x;

        hld.foreach(m, p, [&](int a, int b) {
            ans *= st.get(a, b + 1);
        });

        int lca = hld.lca(m, p);
        ans /= st.get(hld.vid[lca], hld.vid[lca] + 1);
        printf("%d\n", ans.get());
    }
}
```

# 炭z

źALCAƗݐϘał낤B
2̃ASYȂꍇ́AOOĒׂ悤B

LCA+ݐϘagƁA؂̃pX̃RXg̑aɋ߂邱Ƃ͗LłB
́Al̏sƂŁApX̃RXg̑ς߂邱ƂłB
tot[cu] := 璸_cuւ̃RXg̐
DFSŌvZĂB
ƁA_mƒ_pƂLCA𒸓_lcaƂ邱ƂŁA
tot[m] * tot[p] / tot[lca] / tot[lca]
_mƒ_p̃pX̃RXg̑ςƂȂB
///////////////////////// writeup2 end */
