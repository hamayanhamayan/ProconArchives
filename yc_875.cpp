//https://yukicoder.me/problems/no/875
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
#define def make_pair(inf,-1)
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int N, Q, A[101010];
SegTree<pair<int,int>, 1 << 17> st;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) st.update(i, {A[i], i});

    rep(i, 0, Q) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;

        if(t == 1) {
            swap(A[l], A[r]);
            st.update(l, {A[l], l});
            st.update(r, {A[r], r});
        }
        else {
            auto ans = st.get(l, r + 1);
            printf("%d\n", ans.second + 1);
        }
    }
}



/* ///////////////////////// writeup1 start
# 前提知識
- [セグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
区間最小を取得するセグメントツリーを構築する。
これはどこかで学ぼう。
すると、
クエリ1は、l番目とr番目のswap操作なので、配列Aをswapしたら、updateで書き換えればいい。
クエリ2は、{A[i],i}というペアで入れておくと、最小値を取るときの添字も取れる。
ペアで入れておくときはクエリ1で添字を更新しておくこと。
///////////////////////// writeup2 end */
