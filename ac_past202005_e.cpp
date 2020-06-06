//https://atcoder.jp/contests/past202005-open/tasks/past202005_e
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













int N, M, Q;
vector<int> E[202];
int c[202];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M >> Q;
    rep(i, 0, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    rep(i, 0, N) cin >> c[i];

    rep(_, 0, Q) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x; x--;
            printf("%d\n", c[x]);
            fore(to, E[x]) c[to] = c[x];
        }
        else {
            int x, y; cin >> x >> y;
            x--;

            printf("%d\n", c[x]);
            c[x] = y;
        }
    }
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
この問題では、競技プログラミングではよく出る無向グラフをうまく扱えるかが問われている問題。
競プロでは、無向グラフの辺については、隣接グラフで持つ方が多くの場面でよいとされている。
そうしておくと、今回の問題のクエリにも十分に対応可能である。
以下の配列が隣接グラフである。
E[cu] := 頂点cuから遷移可能な頂点の集合

クエリ1では、単純にc[x]を答える。O(1)
クエリ2では、E[x]にある頂点のcをc[x]で置き換える。O(N)
よって全体でO(QN)であり、間に合う。
///////////////////////// writeup2 end */
