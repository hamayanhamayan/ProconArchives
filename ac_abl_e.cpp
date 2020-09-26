//https://atcoder.jp/contests/abl/tasks/abl_e
#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; using namespace atcoder;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
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
typedef ModInt<998244353> mint;
using V = pair<mint, mint>;
template<int NV> struct LazySegTree { // [L,R)
    vector<V> dat; vector<int> lazy; LazySegTree() { dat.resize(NV * 2, def); lazy.resize(NV * 2, ldef); }
    void update(int a, int b, int v, int k, int l, int r) {
        push(k, l, r); if (r <= a || b <= l) return;
        if (a <= l && r <= b) { setLazy(k, v); push(k, l, r); }
        else {
            update(a, b, v, k * 2, l, (l + r) / 2); update(a, b, v, k * 2 + 1, (l + r) / 2, r);
            dat[k] = comp(dat[k * 2], dat[k * 2 + 1]);
        }
    }
    V get(int a, int b, int k, int l, int r) {
        push(k, l, r); if (r <= a || b <= l) return def;
        if (a <= l && r <= b) return dat[k]; auto x = get(a, b, k * 2, l, (l + r) / 2);
        auto y = get(a, b, k * 2 + 1, (l + r) / 2, r); return comp(x, y);
    }
    void update(int a, int b, int v) { update(a, b, v, 1, 0, NV); }
    V get(int a, int b) { return get(a, b, 1, 0, NV); }
    // ---- Template ---------------------------------------------------------------------------------

    const V def = make_pair(mint(0), mint(1)); int ldef = -1;
    V comp(V l, V r) {
        return make_pair(l.first * r.second + r.first, l.second * r.second);
    }
    void setLazy(int i, int v) { lazy[i] = v; }
    void push(int k, int l, int r) {
        if (lazy[k] != ldef) {
            // modify------------------------------
            dat[k] = make_pair(mint(lazy[k]), mint(10));
            int kk = k;
            while (kk < NV) {
                kk = kk * 2;
                dat[k] = comp(dat[k], dat[k]);
            }
            // ------------------------------------
            if (r - l > 1) { setLazy(k * 2, lazy[k]); setLazy(k * 2 + 1, lazy[k]); }
            lazy[k] = ldef;
        }
    }

    void print(int i) { printf("%d,%d ", dat[i].first.get(), dat[i].second.get()); }
    void printLazy(int i) { printf("%d ", lazy[i]); }
    void debug() {
        printf("[DAT]\n");
        int len = 1;
        int id = 0;
        while (len <= NV) {
            rep(i, 0, len) print(id), id++;
            printf("\n");
            len *= 2;
        }
        printf("[LAZY]\n");
        len = 1;
        id = 0;
        while (len <= NV) {
            rep(i, 0, len) printLazy(id), id++;
            printf("\n");
            len *= 2;
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














int N, Q;
LazySegTree<1 << 18> st;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    st.update(0, N, 1);
    rep(q, 0, Q) {
        int L, R, D; cin >> L >> R >> D;
        L--;
        st.update(L, R, D);
        int ans = st.get(0, N).first.get();
        printf("%d\n", ans);
    }
}





/* ///////////////////////// writeup1 start
# 前提知識
- [遅延評価セグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
ACLコンテストというのもあり、遅延評価セグメントツリーが真っ先に思いついた。
遅延評価セグメントツリーで解くんだろうなぁと思って考えると、解ける。
遅延評価セグメントツリーの細かい解説はしないので、どこかで勉強してきてほしい。
それが分かっていれば、この問題はそれほど難しくない。

# 区間にどういう情報を持たせるか

セグメントツリーで解くということは、区間のマージをする必要があるが、どういう情報を持つべきだろうか。
一般的に答えがそのまま情報として持たれている場合が多いので、とりあえずそれは入れておく。

- a: 区間を10進数として見たときの整数 (mod)

だが、これだけでは区間をマージするときにできない。
例えば、11と22をマージすると、1122になる。
実際に計算に落としてみると、11*100+22となる。
ここで100という数字が出てくるが、これは10の22の桁数乗である。
このように右側の区間分ずらすために桁数乗も情報として必要のようだ

- a: 区間を10進数として見たときの整数 (mod)
- b: 10の桁数乗 (mod)

こうすれば(a,b)と(c,d)のマージは(a*d+c,b*d)で行えることと言える。
とりあえず遅延評価で更新していくことを抜きにすれば、クエリにこたえられそうだ。

# 遅延評価で何を伝搬させていくか

後は、遅延評価で何を伝搬させるかというところだが、普通に更新したい数を持たせればいい。
区間[L,R)に対してvで更新したい場合は、(v,10)の(R-L)乗を入れてやればいい。
これは繰り返し二乗法で毎回計算しても間に合う。

# 実装

自分のライブラリなので、雰囲気だが、こんな感じ。

```cpp
const V def = make_pair(mint(0), mint(1)); int ldef = -1;
V comp(V l, V r) {
    return make_pair(l.first * r.second + r.first, l.second * r.second);
}
void setLazy(int i, int v) { lazy[i] = v; }
void push(int k, int l, int r) {
    if (lazy[k] != ldef) {
        // modify------------------------------
        dat[k] = make_pair(mint(lazy[k]), mint(10));
        int kk = k;
        while (kk < NV) {
            kk = kk * 2;
            dat[k] = comp(dat[k], dat[k]);
        }
        // ------------------------------------
        if (r - l > 1) { setLazy(k * 2, lazy[k]); setLazy(k * 2 + 1, lazy[k]); }
        lazy[k] = ldef;
    }
}
```
///////////////////////// writeup2 end */
