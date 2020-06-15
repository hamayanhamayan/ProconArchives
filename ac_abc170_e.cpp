//https://atcoder.jp/contests/abc170/tasks/abc170_e
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














int N, Q, A[201010], B[201010];
SegTree<int, 1 << 18> st;
multiset<int> rates[201010];
int cnt[201010];
//---------------------------------------------------------------------------------------------------
void add(int child, int to) {
    cnt[to]++;
    rates[to].insert(A[child]);
    st.update(to, *rates[to].rbegin());
}
void erase(int child, int from) {
    cnt[from]--;
    auto ite = rates[from].find(A[child]);
    rates[from].erase(ite);

    if (cnt[from] == 0) st.update(from, inf);
    else st.update(from, *rates[from].rbegin());
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    rep(i, 1, N + 1) {
        cin >> A[i] >> B[i];
        add(i, B[i]);
    }

    rep(_, 0, Q) {
        int C, D; cin >> C >> D;
        erase(C, B[C]);
        B[C] = D;
        add(C, B[C]);

        int ans = st.get(0, 201010);
        printf("%d\n", ans);
    }
}





/* ///////////////////////// writeup1 start
# 前提知識
- multiset
- [区間minセグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
シミュレーション高速化の問題。
データ構造をうまく使ってシミュレーションを高速化しよう。
使用するデータ構造については色々代替案があるだろう。

まず、子供が出たり入ったりして管理されてて、その中から最大の物を取り出したり、任意の数を出し入れする
ということで、multisetを使うのかな？と考える。
そして、平等さを計算するために全ての幼稚園から最小の値を取り出すが、一部更新されたりするので、
区間minセグメントツリーを使うのかな？と考える。
ここから、multisetと区間minセグメントツリーを使って全体を考えてみると解法が思いつく。

rates[kind] := 幼稚園kindにいる生徒のレートを保持するmultiset
cnt[kind] := 幼稚園kindにいる生徒の人数
st[L,R) := 幼稚園区間[L,R)での最小値（平等さ）を返すセグメントツリー

このようにデータを持っておく。
これにレートを出し入れしながら操作を行っていく。
具体的には生徒のaddと生徒のeraseのみ実装すれば、全体はそれの組合せで表現可能。

add関数
生徒childを幼稚園toに入れる。
cnt[to]は1人増えるのでインクリメント
rates[to]へは1人増えた分のレートを入れる
そして、ratesが変更したので、幼稚園toでの最強レートが更新された可能性があり、
それに伴ってセグメントツリーも更新しておく。

erase関数
生徒childを幼稚園fromから出す。
cnt[to]は1人減るのでデクリメント
rates[to]ではその生徒のレートを消す。
そして、ratesが変更したので、幼稚園fromでの最強レートが更新された可能性があり、
それに伴ってセグメントツリーも更新しておく。
生徒が一人もいなくなった場合は、区間minで無視させるために∞を入れておく。

実装上の注意として、multiset絡みがある。

- multisetから要素を削除するにはiteratorを使う必要がある
- multisetのcountは遅いので、個数を数えるcnt配列を別途用意した
///////////////////////// writeup2 end */
