//https://atcoder.jp/contests/past202004-open/tasks/past202004_l
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
#define def make_pair(inf, inf)
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
        while (i>1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
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














int N, K, D, A[201010];
SegTree<pair<int, int>, 1 << 18> st;
int ans[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K >> D;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) st.update(i, make_pair(A[i], i));

    int idx = 0;
    rep(k, 0, K) {
        int rest = K - k;

        // [L, R]
        int L = idx;
        int R = N - 1 - ((rest - 1) * D);

        if (R < L) {
            cout << -1 << endl;
            return;
        }
        
        auto p = st.get(L, R + 1);
        ans[k] = p.first;
        idx = p.second + D;
    }

    rep(i, 0, K) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
こういった構築には典型が存在する。
「辞書順最小の構築問題は先頭から貪欲に選択していく」

さて、先頭から貪欲に行うとはどういうことだろう。
例えば、3 2 1 4 5 6 7という数列があって、貪欲に先頭をまず決めたいときは、1を取ってきたいと思うだろう。
辞書順最小なので、1が先頭にあるのが貪欲的な選択である。
問題は、1を取ったあとに、数列全体を構築することができるかである。
もし、できれば選択すればいいし、できなければ妥協する必要がある。
今回の例でK=3でD=2であるとする。
この時、1番目に1を選択すると、1,5,7と取れば3個とれるので、それ以降の操作が行えるので、1を選択してもいい。
仮に3 2 1 4 5 6であれば、1を取ってしまうと、それ以降で2個取れないので1は選択できない。

もう少し一般化して考えると、i番目の数を選択するときは、それを取った後、K-i個選択する必要がある。
そして、K-i個選択するには末尾から(K-i)*D個は必ず必要になる。
よって、3 2 1 4 5 6 7でK=3,D=2であれば、末尾から4個は必ず必要となるので、貪欲に取ることができるのは
3 2 1の範囲になる。なので、この中の最小値を選択すれば、有効な貪欲手となる。
区間の最小値はセグメントツリーを使おう。どの部分を取ったかもわかるように、(A[i], i)で入れておくといい。
A[i]が同じものが複数ある時は、最も左にあるものを使おう。
そうすると、その後の操作に必ず有利に働くためである。

これで、貪欲していけば答え。
///////////////////////// writeup2 end */
