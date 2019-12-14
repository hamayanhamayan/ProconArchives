//https://yukicoder.me/problems/no/878
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
#define def -1
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
int dp[17][101010];
SegTree<int, 1 << 17> st;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) st.update(i, A[i]);

    rep(p, 0, 17) rep(cu, 0, N + 1) dp[p][cu] = N;
    rep(cu, 0, N) {
        if(A[cu] < st.get(cu, N)) {
            int ok = N, ng = cu;
            while(ng + 1 != ok) {
                int md = (ng + ok) / 2;
                if(A[cu] < st.get(cu, md))
                    ok = md;
                else
                    ng = md;
            }
            dp[0][cu] = ok-1;
        }
    }
    rep(p, 1, 17) rep(cu, 0, N) dp[p][cu] = dp[p - 1][dp[p - 1][cu]];

    rep(i, 0, Q) {
        int t, l, r; cin >> t >> l >> r;
        l--;
        r--;

        int ans = 1;
        int p = 16;
        int pp = 1;
        rep(i, 0, 16) pp *= 2;
        int cu = l;
        while (0 <= p and cu <= r) {
            int to = dp[p][cu];
            if(to <= r) {
                ans += pp;
                cu = to;
            }
            p--;
            pp /= 2;
        }
        printf("%d\n", ans);
    }
}



/* ///////////////////////// writeup1 start
# 前提知識
- [ダブリング](https://www.hamayanhamayan.com/entry/2019/04/13/094157)
///////////////////////// writeup2 start
高い要素の個数を答える方針でしばらく考えていてダメだったので、
ちょっと言い換えを考えてみる。
区間が与えられた時に、先頭から順に最も近い今いる場所より大きい数の所へジャンプすることにする。
このとき区間内で行えるジャンプ回数+1が答えになっている。
よって、何回ジャンプできるかを見ればいい。
それはダブリングでできる。
dp[p][cu] := A[cu]から2^p回ジャンプした時に到達する場所
dp[0][cu]ができていれば、それ以降の更新は難しくない。
問題はここだ。

最も最寄りなA[cu]より大きい数の場所をいかに特定するか。
区間最大セグメントツリー上で二分探索をしよう。
///////////////////////// writeup2 end */
