//https://atcoder.jp/contests/abl/tasks/abl_d
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
#define def 0
template<class V, int NV> struct SegTree { //[l,r)
    V comp(V& l, V& r) { return max(l, r); };

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














int N, K, A[301010];
SegTree<int, 1 << 19> st;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];

    rep(i, 0, N) {
        int ma = st.get(max(0, A[i] - K), min(301010, A[i] + K + 1));
        st.update(A[i], ma + 1);
    }

    int ans = st.get(0, 301010);
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [区間maxセグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
たぶん似たような解法をやったことが無いと、思いつくのは難しいかもしれない。
以下のような問題設定は見たことがないだろうか。

- BはAの部分列である
- どのBの隣り合う要素についてもB[i]<B[i+1]が成り立つ

これはLISと言う典型問題である。
今回の問題はこれのセグメントツリー解法を知っていると思いつきやすい。

# 先頭から見ていく

先頭から順に評価をしていくのだが、A[i]について配列Bに加えるかを考えるとしよう。
この時、加えることのできる配列Bは末尾が[A[i]-K,A[i]+K]に含まれるものである。
よって、以下のようなセグメントツリーを用意して、この検索を高速化しよう。

segtree[x] := 末尾の要素がxである配列Bの最大サイズ
segtree[x,y] := [x,y)の最大値

先頭から順に評価して行く中で、このsegtreeを適宜更新することで、以下のようにとらえることができる。

segtree[x] := 『A[i]以前までの要素を使って』末尾の要素がxである配列Bの最大サイズ
segtree[x,y] := [x,y)の最大値

これで得られた最大値+1をsegtree[A[i]]に更新していく。
最後にsegtree全体の最大値を取ると答え。

# これは何か？

色々な考え方があると思うが、TLではin-place DP、インラインDPであるという発言を多く見た。
確かに。

dp[i][x] := 配列Aのi番目までを使って末尾がxの配列Bを作ったときの配列Bの最大サイズ

このように定義すると更新式はこうなる

dp[i][x] -> dp[i + 1][x]
max(dp[i][A[i] - K],...,dp[i][A[i] + K]] -> dp[i + 1][A[i]]

1回の更新ではA[i]の部分しか更新されない。
よってインラインDPができる。
更新時のmaxはセグメントツリーで実現できるので、セグメントツリーをそのままDPっぽく扱って計算していく感じだ。
///////////////////////// writeup2 end */
