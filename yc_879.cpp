//https://yukicoder.me/problems/no/879
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
template<int NV> struct LazySegTree { // [L,R)
    using V = tuple<ll, ll, ll, ll>;
    vector<V> dat, lazy;
    LazySegTree()
    {
        dat.resize(NV * 2, def);
        lazy.resize(NV * 2, ldef);
    }
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
    const V def = make_tuple(0,0,0,0), ldef = make_tuple(0,0,0,0);
    V comp(V l, V r) {
        ll odd_cnt = get<0>(l) + get<0>(r);
        ll odd_sum = get<1>(l) + get<1>(r);
        ll even_cnt = get<2>(l) + get<2>(r);
        ll even_sum = get<3>(l) + get<3>(r);

        return make_tuple(odd_cnt, odd_sum, even_cnt, even_sum);
    }
    void setLazy(int i, V v) {
        lazy[i] = v;
    }
    void push(int k, int l, int r) {
        if (lazy[k] != ldef) {
            // modify------------------------------
            dat[k] = lazy[k];
            int kk = k;
            while (kk < NV - 1) {
                kk *= 2;
                dat[k] = mul(dat[k], dat[k]);
            }
            // ------------------------------------
            if (r - l > 1) { setLazy(k * 2 + 1, lazy[k]); setLazy(k * 2 + 2, lazy[k]); }
            lazy[k] = ldef;
        }
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
void _main() {
}





/* ///////////////////////// writeup1 start
# 前提知識
- [遅延セグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
区間addに加えて特殊な置き換えがある。
遅延セグメントツリーかな？という前提で考えてみる。
最初は頂点に何を乗せるかという部分であるが、
- まずは答えの部分木のsum
- 偶奇で置き換えるかをやるので、偶奇それぞれについて情報を持てば良さそう。
(奇数の個数, 奇数の総和, 偶数の個数, 偶数の総和)
これだけあれば良さそう。

クエリ1は、
奇数の総和=奇数の個数
偶数の総和=0

クエリ2は、
xの偶奇によって、処理を分ける。
xが偶数なら、
奇数の総和=奇数の総和+奇数の個数*x
偶数の総和=偶数の総和+偶数の個数*x
xが奇数なら、
奇数の総和=偶数の総和+偶数の個数*x
奇数の個数=偶数の個数
偶数の総和=奇数の総和+奇数の個数*x
偶数の個数=奇数の個数

クエリ3は、
奇数の総和と偶数の総和をとってくる
///////////////////////// writeup2 end */
