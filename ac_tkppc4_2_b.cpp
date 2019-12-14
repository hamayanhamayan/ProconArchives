//https://atcoder.jp/contests/tkppc4-2/tasks/tkppc4_2_b
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














int N, M;
vector<int> E[101010];
int col[101010];
//---------------------------------------------------------------------------------------------------
int dp[101010];
void dfs(int cu, int pa = -1) {
    if(col[cu]) dp[cu] = 1;

    fore(to, E[cu]) if(to != pa) {
        dfs(to, cu);
        dp[cu] += dp[to];
    }
}
//---------------------------------------------------------------------------------------------------
bool ans = true;
void dfs2(int cu, int pa = -1) {
    int cnt = 0;
    fore(to, E[cu]) if(0 < dp[to]) cnt++;
    if(2 < cnt) ans = false;

    int tot = 0;
    fore(to, E[cu]) tot += dp[to];
    fore(to, E[cu]) if(to != pa) {
        dp[cu] = tot - dp[to];
        if(col[cu]) dp[cu]++;
        dfs2(to, cu);
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, N - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    rep(i, 0, M) {
        int c; cin >> c; c--;
        col[c] = 1;
    }

    dfs(0);
    dfs2(0);

    if (ans) cout << "Yes" << endl;
    else cout << "trumpet" << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [全方位木DP](https://www.hamayanhamayan.com/entry/2017/02/09/155738)
///////////////////////// writeup2 start
問題を少し読み替えて考えてみる。
全ての写真を集めることができない状況というのは、どういう状況だろうか。
同じ街を二度通ることはできないので、3択の状態ができると困る。
ある町を根とした根付き木を考えた時、その根から遷移する部分木の中で写真がある部分木が3つ以上あるときにダメ。
なので、全ての頂点を根として、その部分木で写真が全て2つ以下であるかを判定しよう。
部分点の方は、全ての頂点を根として木DPをすればACできる。
完答の方は、全方位木DPをすればいい。
///////////////////////// writeup2 end */
