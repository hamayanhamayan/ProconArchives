//https://yukicoder.me/problems/no/877
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
// StaticHealthy2DSegtree
#define def 0
using V = ll;
V comp(V& l, V& r) { return l + r; };
struct SegTree { //[l,r)
    int NV;
    vector<V> val;
    void init(int n) {
        NV = 1;
        while (NV < n) NV *= 2;
        val = vector<V>(NV * 2, def);
    }
    V get(int x, int y, int l, int r, int k) {
        if (r <= x || y <= l) return def; if (x <= l&&r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); auto b = get(x, y, (l + r) / 2, r, k * 2 + 1); return comp(a, b);
    }
    V get(int x, int y) { return get(x, y, 0, NV, 1); }
    void update(int i, V v) { i += NV; val[i] = v; while (i>1)i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]); }
    void compupdate(int i, V v) { update(i, comp(v, val[i + NV])); }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};

struct StaticHealthy2DSegTree {
    int NV;
    vector<SegTree> st;
    vector<vector<int>> index;
    
    void init(vector<vector<pair<int,V>>> &v) {
        int n = v.size();
        NV = 1; while (NV < n) NV *= 2;
        index.resize(2 * NV);
        rep(i, 0, n) fore(p, v[i]) index[i + NV].push_back(p.first);
        rrep(i, NV * 2 - 1, 1) {
            sort(index[i].begin(), index[i].end());
            index[i].erase(unique(index[i].begin(), index[i].end()), index[i].end());
            fore(j, index[i]) index[i / 2].push_back(j);
        }
        st.resize(2 * NV);
        rep(i, 1, NV * 2) st[i].init(index[i].size());
        
        rep(i, 0, n) fore(p, v[i]) {
            int j = lower_bound(index[i + NV].begin(), index[i + NV].end(), p.first) - index[i + NV].begin();
            st[i + NV].update(j, p.second);
        }

        rrep(i, NV * 2 - 1, 2) {
            rep(j, 0, index[i].size()) {
                V v = st[i][j];
                
                int k = lower_bound(index[i / 2].begin(), index[i / 2].end(), index[i][j]) - index[i / 2].begin();
                st[i / 2].compupdate(k, v);
            }
        }
    }
    V get(int sx, int tx, int sy, int ty, int k, int l, int r) {
        assert(k < NV * 2);
        assert(l < r);
        if (r <= sx or tx <= l) return def;
        if (sx <= l and r <= tx) {
            int syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
            int tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
            return st[k].get(syy, tyy);
        }
        int md = (l + r) / 2;
        V le = get(sx, tx, sy, ty, k * 2, l, md);
        V ri = get(sx, tx, sy, ty, k * 2 + 1, md, r);
        return comp(le, ri);
    }
    V get(int sx, int tx, int sy, int ty) {
        return get(sx, tx, sy, ty, 1, 0, NV);
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














int N, Q, A[101010];
StaticHealthy2DSegTree sum, cnt;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    rep(i, 0, N) cin >> A[i];

    vector<vector<pair<int, ll>>> v_sum(N), v_cnt(N);
    rep(i, 0, N) {
        v_sum[i].push_back({A[i], 1LL*A[i]});
        v_cnt[i].push_back({A[i], 1LL});
    }
    sum.init(v_sum);
    cnt.init(v_cnt);

    rep(i, 0, Q) {
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        l--;

        ll ans = sum.get(l, r, x, inf) - cnt.get(l, r, x, inf) * x;
        printf("%lld\n", ans);
    }
}



/* ///////////////////////// writeup1 start
# 前提知識
- [セグメントツリーにセグメントツリーを乗せるテク](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
やりすぎ回答かもしれない。
maxという制約が入ったままだと問題としては扱いづらい。
なので、[l,r]という制約に加えて、x以上の数だけとってくるようにしよう。
こうすればmaxは排除できる。
sum{a[i]-x}=sum{a[i]}-x*a_cnt
であるため、A[l,r]でありx以上の数の総和と個数が分かれば問題が解ける。
これはセグメントツリーにセグメントツリーを乗せるテクを使えば実現することができる。
これにより矩形範囲のデータがとってこられるので、とってきて答える。
///////////////////////// writeup2 end */
