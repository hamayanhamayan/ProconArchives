//https://yukicoder.me/problems/no/872
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
vector<pair<int,int>> E[201010];
//---------------------------------------------------------------------------------------------------
ll ans = 0;
int cnt[201010];
void dfs(int cu, int pa = -1) {
    cnt[cu] = 1;
    fore(p, E[cu]) if(p.first != pa) {
        dfs(p.first, cu);
        cnt[cu] += cnt[p.first];

        int A = cnt[p.first];
        int B = N - A;

        ans += 1LL * A * B * 2 * p.second;
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N - 1) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        E[a].push_back({b, c});
        E[b].push_back({a, c});
    }

    dfs(0);
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
全てのパスの長さの総和を求める問題であるが、こういう問題は集計方法を変えるといい。
全てのパスを列挙するのには、O(N^2)かかるので、全てのパス全探索はしたくない。
他に全探索対象を探すと、辺は全探索できる。
全てのパスの長さの総和＝（辺の長さ×その辺を含むパスの個数）の総和
この言い換えが思いつかないかもしれないが、自分は見たことがあったので、すんなり思いついた。
このような全探索対象のすり替えテクがある。

あとは、その辺を含むパスの個数をどう求めるかであるが、その辺を挟んで頂点がA個、B個あれば、
A個の中から1つとってきて端点とする、B個の中から1つとってきて端点とすれば、パスが完成するので、
端点のうち始点をどちらにするかで2通りあるので、A*B*2組み合わせある。
これをdfsしながら計算すると答え。
///////////////////////// writeup2 end */
