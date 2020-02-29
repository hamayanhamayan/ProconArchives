//https://yukicoder.me/problems/no/1000
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, Q, A[201010];
char C[201010]; int X[201010], Y[201010];
LazySegTree<ll, 1 << 18> cnt;
ll ans[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> Q;
	rep(i, 0, N) cin >> A[i];
	rep(q, 0, Q) cin >> C[q] >> X[q] >> Y[q];

    rep(q, 0, Q) if (C[q] == 'B') cnt.update(X[q] - 1, Y[q], 1);
    rep(i, 0, N) ans[i] = 1LL * A[i] * cnt.get(i, i + 1);

    rep(q, 0, Q) {
        if (C[q] == 'A') {
            int i = X[q] - 1;
            ans[i] += 1LL * Y[q] * cnt.get(i, i + 1);
        } else {
            cnt.update(X[q] - 1, Y[q], -1);
        }
    }

    rep(i, 0, N) {
        if(i) printf(" ");
        printf("%lld", ans[i]);
    }
    printf("\n");
}





/* ///////////////////////// writeup1 start
# 前提知識
- [遅延セグメントツリー（区間add, 1点取得）](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
- クエリ先読み
///////////////////////// writeup2 start
配列のある区間をコピーしてaddするようなデータ構造は持っていない。
どこから手を付けようか。

まずは簡単な場合から考えてみる。
Bに値が足されるのはクエリBであるため、クエリBだけで構成された場合を考えてみる。
例えば、n=5で、[2,4], [3,5], [1,4]というクエリBが来た場合、
それぞれの要素が足される回数のは、
`1 2 3 3 1`
となる。これは丁度、クエリBの区間について1を区間addすると得られる配列である。
足される回数が得られたら、要素の数とかけ合わせれば、数列Bが復元できる。
区間addするには遅延セグメントツリーを使うといい。
今回は、1点取得なので、BITを使うことでより高速に同様のことが行える。

さて、これでクエリBのみの場合は処理を行うことができた。
次にクエリAを処理しよう。
これはクエリ先読みテクを使うのだが、あるタイミングでクエリAが呼ばれたとする。
この時に要素x[i]に+y[i]される訳だが、この増分である、y[i]が要素x[i]に何回足されるかが分かれば、
クエリBのとき同様に掛け合わせて足すことで高速に計算できる。
これは、それ以降に呼ばれるクエリBの中で要素x[i]が何回含まれるかとなる。
最初にクエリ全体で各要素で含まれる回数を遅延セグメントツリーで計算しておき、
クエリを順番に見ていく過程で、クエリBが来たら、その区間の出現回数を-1すると、
常に「それ以降の各要素での呼ばれる回数」を表現する遅延セグメントツリーが作れる。
///////////////////////// writeup2 end */
