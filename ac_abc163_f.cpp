//https://atcoder.jp/contests/abc163/tasks/abc163_f
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
    // 区間代入,区間和
    const V def = 0, ldef = -1;
    V comp(V l, V r) { return l + r; }
    void setLazy(int i, V v) { lazy[i] = v; }
    void push(int k, int l, int r) {
        if (lazy[k] != ldef) {
            // modify------------------------------
            dat[k] = lazy[k] * (r - l);
            // ------------------------------------
            if (r - l > 1) { setLazy(k * 2 + 1, lazy[k]); setLazy(k * 2 + 2, lazy[k]); }
            lazy[k] = ldef;
        }
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














int N, C[201010];
vector<int> E[201010];
vector<int> cols[201010];
LazySegTree<int, 1 << 18> lst;
//---------------------------------------------------------------------------------------------------
int L[401010], R[401010], dpt[201010];
int idx = 0;
void euler(int cu, int pa = -1) { // [L[v],R[v])
    L[cu] = idx; idx++;
    for (int to : E[cu]) if (to != pa) {
        dpt[to] = dpt[cu] + 1;
        euler(to, cu);
    }
    R[cu] = idx;
}
//---------------------------------------------------------------------------------------------------
ll solve(int c) {
    ll ans = 1LL * N * (N - 1) / 2;

    auto& v = cols[c];

    sort(all(v), [&](int a, int b) { return dpt[a] > dpt[b]; });
    lst.update(0, N, 1);

    fore(cu, v) {
        fore(to, E[cu]) if (dpt[cu] < dpt[to]) {
            ll cnt = lst.get(L[to], R[to]);
            ans -= cnt * (cnt - 1) / 2;
        }
        lst.update(L[cu], R[cu], 0);
    }
    ll cnt = lst.get(0, N);
    ans -= cnt * (cnt - 1) / 2;

    return ans + cols[c].size();
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) {
        cin >> C[i];
        cols[C[i]].push_back(i);
    }

    rep(i, 0, N - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    euler(0);

    rep(c, 1, N + 1) {
        ll ans = solve(c);
        printf("%lld\n", ans);
    }
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
