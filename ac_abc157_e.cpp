//https://atcoder.jp/contests/abc157/tasks/abc157_e
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
#ifdef _MSC_VER
inline unsigned int __builtin_popcount(unsigned int x) { return __popcnt(x); }
#endif // _MSC_VER
#define def 0
template<class V, int NV> struct SegTree { //[l,r)
    V comp(V& l, V& r) { return l | r; };

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














int N; string S; int Q;
SegTree<ll, 1 << 19> st;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> S >> Q;
    rep(i, 0, N) st.update(i, 1LL << (S[i] - 'a'));
    rep(_, 0, Q) {
        int t; cin >> t;
        if (t == 1) {
            int i; char c; cin >> i >> c; i--;
            st.update(i, 1LL << (c - 'a'));
        }
        else {
            int l, r; cin >> l >> r; l--;
            ll msk = st.get(l, r);
            int ans = __builtin_popcount(msk);
            printf("%d\n", ans);
        }
    }
}





/* ///////////////////////// writeup1 start
# 前提知識
- [セグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
何から手を付ければいいか分からなかったかもしれない。
一点更新、区間クエリなので、セグメントツリー的な解法から考えるといいかもしれない。

文字種類の個数を数えるのには、bit演算のorが有用である。
a -> 0, b -> 1, c -> 2, ...のようにマッピングを行い、その文字があれば、対応する下位iビットのフラグを
立てたものを考える。
つまり、aであれば、...0001であるし、bであれば、...0010である。
アルファベットは26文字なので、long longを使えばビット数は足りる。
これのORをとることでビットが立っているものをすべて集めることができるので、
区間の数の種類は、区間のビットのOR和のビットが立っている個数と等しくなっている。

ここまで分かっていれば、後は実装するだけ。
ビットが立っている個数を取得するには__buildin_popcountを使うといい。
///////////////////////// writeup2 end */
