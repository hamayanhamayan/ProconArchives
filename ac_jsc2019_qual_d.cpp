//https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_d
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N;
int ans[500][500];
//---------------------------------------------------------------------------------------------------
void dfs(int l, int r, int level) {
    if(l + 1 == r) return;
    int c = (l + r) / 2;

    rep(x, l, c) rep(y, c, r) ans[x][y] = ans[y][x] = level;

    dfs(l, c, level + 1);
    dfs(c, r, level + 1);
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    dfs(0, N, 1);

    rep(i, 0, N) {
        rep(j, i + 1, N) {
            if(j != i + 1) printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}





/* ///////////////////////// writeup1 start
# 前提知識
- [分割統治](https://www.hamayanhamayan.com/entry/2017/05/21/234616)
///////////////////////// writeup2 start
何もわからず解説を見てしまった。
分割統治を行う。
まず、パスが全て偶数になるために満たすべき条件は、グラフが二部グラフであるという条件である。
よって、レベルを適切に設けて、全てのレベルで二部グラフになればいい。
このグラフの構築には分割統治を使おう。
f(l, r, level) := levelレベル以上で[l,r)の頂点で二部グラフを構築する
これはc = (l+r)/2とすると、[l,c)と[c,r)の間の任意の頂点に辺を貼ると二部グラフになる。
これで、2つの区間の間に貼れる辺は全て貼ったことになるので、後は、それぞれの区間で辺を貼ることを考えればいい。
そのため、残りはf(l, c, level + 1)とf(c, r, level + 1)に操作を託す。
これを繰り返すと答え。
///////////////////////// writeup2 end */
