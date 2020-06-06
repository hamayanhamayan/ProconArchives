//https://atcoder.jp/contests/past202005-open/tasks/past202005_j
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
#define def inf
template<class V, int NV> struct SegTree { //[l,r)
    V comp(V& l, V& r) { return min(l, r); };

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














int N, M, A[301010];
SegTree<int, 1 << 17> st;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, M) cin >> A[i];

    rep(i, 0, N) st.update(i, 0);
    rep(i, 0, M) {
        int ng = 0, ok = N + 1;
        while (ng + 1 != ok) {
            int md = (ng + ok) / 2;
            if (st.get(0, md) < A[i]) ok = md;
            else ng = md;
        }
        if (ok != N + 1) {
            int eat = ok - 1;
            st.update(eat, A[i]);
            printf("%d\n", eat + 1);
        }
        else printf("-1\n");
    }
}





/* ///////////////////////// writeup1 start
# 前提知識
- [セグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
///////////////////////// writeup2 start
最初に「まだお寿司を1つを食べていない」という条件は、
自分の過去最高美味しさを-1とでもしておけば無視できるので、そういう感じに変えておく。
あるお寿司を食べる子供は、それより前の子供がスルーして、かつ、自分の過去最高美味しさより大きい場合である。
それより前の子供がスルーというのがいまいちなので言い換えると、
「それより前の子供の過去最高美味しさの最小値が、今のお寿司以上」
の場合である。
もっと言い換えると、
「(今のお寿司)≦(ある子どもより前の子供の過去最高美味しさの最小値)、かつ、(ある子供の過去最高美味しさ)＜(今のお寿司)」
であれば、その子が食べる。

ここまで考察が進めば、あとはデータ構造を知っているかの問題になる。
区間最小値のセグメントツリーを使おう。
segtree[i] := 先頭からi番目の子供の過去最高美味しさ
これと二分探索を使って、
「(今のお寿司)≦(ある子どもより前の子供の過去最高美味しさの最小値)、かつ、(ある子供の過去最高美味しさ)＜(今のお寿司)」
の境界線を探す。
これで誰が食べるかは分かるので答えて、セグメントツリーの食べた子の部分を記録更新しておく。
///////////////////////// writeup2 end */
