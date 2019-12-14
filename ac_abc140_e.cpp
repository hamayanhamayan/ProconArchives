//https://atcoder.jp/contests/abc140/tasks/abc140_e
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

int N, P[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> P[i];

    SegTree<int,1<<17> st;
    rep(i, 0, N) st.update(i, P[i]);

    ll ans = 0;
    rep(i, 0, N) {
        int a = -1, b = -1, c = -1, d = N, ok, ng;
        ll comb = 0;

        if(P[i] < st.get(0, i)) {
            ok = 0;
            ng = i;
            while(ok + 1 != ng) {
                int md = (ok + ng) / 2;
                if(P[i] < st.get(md, i))
                    ok = md;
                else
                    ng = md;
            }
            b = ok;

            if(P[i] < st.get(0, b)) {
                ok = 0, ng = b;
                while(ok + 1 != ng) {
                    int md = (ok + ng) / 2;
                    if(P[i] < st.get(md, b))
                        ok = md;
                    else
                        ng = md;
                }
                a = ok;
            }
        } else
            b = -1;

        if(P[i] < st.get(i, N)) {
            ok = N;
            ng = i;
            while(ng + 1 != ok) {
                int md = (ok + ng) / 2;
                if(P[i] < st.get(i, md))
                    ok = md;
                else
                    ng = md;
            }
            c = ok-1;

            if (P[i] < st.get(c + 1, N)) {
                ok = N, ng = c + 1;
                while(ng + 1 != ok) {
                    int md = (ok + ng) / 2;
                    if(P[i] < st.get(c+1, md))
                        ok = md;
                    else
                        ng = md;
                }
                d = ok - 1;
            }
        }
        else c = N;

        //printf("%d %d %d %d\n", a, b, c, d);

        if (0 <= b) {
            comb += 1LL * (b - a) * (c - i);
        }
        if (c < N) {
            comb += 1LL * (d - c) * (i - b);
        }

        ans += comb * P[i];
    }
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
総和を求める問題でよく使うテクであるが、「全てのパターンについてある値の総和」というのを
「（ある値×その値になる組み合わせ）の総和」として言い換えることで解くものがある。
これは、全てのパターンを列挙するより、ある値を列挙する方が数が少ないときである。
今回は、X[L,R]として取りうるパターンはN-2通りであるため、こちらの方針でいこう。

X[L,R]がA[i]であると決めたとき、区間は必ずA[i]を含む必要がある。
そして、A[i]より大きい数がただ一つ含まれる必要がある。
後半の条件が少し難しい。
さて、「a .. b ..  A[i] .. c .. d」という状況を考える。
abcdはどれもA[i]よりも大きい数であり、その間の..にはA[i]未満の数があるとする。
これで有効な[L,R]を考えてみる。
以降、abcd,A[i]を添え字のように扱うので注意。
最も大きいものをbとすると、Lの範囲は(a,b]となる。
このときのRはcを含んではいけないので、[A[i],c)となる。
そして、この間であれば、どれでもいいので、組み合わせは(b-a)*(c-A[i])である。
最も大きいものをcとした場合も同様のように計算できる。
これで組み合わせが求まった。

これが解法である。
A[i]に最寄りの最大値を求めるのもやや厄介。
自分は最大値取得のセグメントツリーで二分探索をして、割り出した。O(Nlog^2N)
abやcdが存在しないなどの状態もあるので、実装には注意。
///////////////////////// writeup2 end */
