//https://codeforces.com/contest/1314/problem/D
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
int getrandmax() {
    static uint32_t y = time(NULL);
    y ^= (y << 13); y ^= (y >> 17);
    y ^= (y << 5);
    return abs((int)y);
}
int getrand(int l, int r) { // [l, r]
    return getrandmax() % (r - l + 1) + l;
}
// [0,n)
vector<int> makePermutation(int n, int loop = 101010) {
    vector<int> v(n);
    rep(i, 0, n) v[i] = i;
    rep(j, 0, loop) {
        int a = getrand(0, n - 1);
        int b = getrand(0, n - 1);
        swap(v[a], v[b]);
    }
    return v;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, K, E[80][80];
//---------------------------------------------------------------------------------------------------
int col[80];
int dp[11][80];
int solve() {
    rep(k, 0, K + 1) rep(cu, 0, N) dp[k][cu] = inf;
    dp[0][0] = 0;
    rep(k, 0, K) rep(cu, 0, N) if (dp[k][cu] != inf) {
        rep(nxt, 0, N) if(col[cu] != col[nxt]) chmin(dp[k + 1][nxt], dp[k][cu] + E[cu][nxt]);
    }
    return dp[K][0];
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) rep(j, 0, N) cin >> E[i][j];

    int ans = inf;
    while (clock() < 1.95 * CLOCKS_PER_SEC) {
        auto vp = makePermutation(N - 1, 1000);
        rep(i, 0, N) col[i] = 0;
        col[0] = 1;
        rep(i, 0, (N - 1) / 2) col[vp[i] + 1] = 1;
        chmin(ans, solve());
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
N頂点の有向の重み付き完全グラフがある。
始点を1として、丁度K回移動を繰り返す。
ある頂点を訪れてから奇数回の移動で同じ頂点に戻ることがないように移動を繰り返したとき、
終点が1となる移動の総コスト（重みの総和とする）の最小値は？
2≦N≦80, 2≦K≦10かつKは奇数

# 前提知識
- [乱択アルゴリズム](https://www.hamayanhamayan.com/entry/2017/08/25/110421)
///////////////////////// writeup2 start
パスが満たすべき、条件を書き下してみよう

- 始点と終点は1
- ある頂点を訪れてから奇数回の移動で同じ頂点に戻らない

これしかないのだが、2番目の条件が明らかにやっかい。
この解決にはブレイクスルーが必要。
『N個の頂点を白黒2色に塗り、白→黒→白のように移動すると決めると、二番目の条件を満たさないパスはなくなる』
どう見ても難しい発想ではあるが、奇数回の移動で同じ頂点に戻らない、二部グラフ、という風に見ると
まあ、分からんでもない位には思える（俺がパッと思いつけるかは怪しい）

ここまでが第一関門。
これで「二色に着色する→その条件下で最適解を見つける」というところまできた。

二色に着色するには、乱択アルゴリズムを使う。
全体を二部グラフとして分ける方法を考えてしまうととてつもない組み合わせとなる。
始点1を黒とすると、パスの長さは最大9なので、他の頂点で黒として訪れる回数は最大4になる。
つまり、始点1以外を二部グラフに分けたときにその最適4点が同じグループに入っていればOKとなる。
最大ケースで考えると、79頂点から半分の39頂点をとってきて、ある4点が同じグループに入る確率が知りたい。
これは計算すると5%ほどある。
失敗する95%が10000回連続する確率は`1.722078e-221`%なので、これは起こりえない。
よって、二部グラフの選び方をランダムで選択していくと、いずれは最適なパターンを得ることができる。
自分の解法では時間いっぱい試行している。

あとは、その二部グラフで最適解を見つけるにはだが、DPで解ける。
dp[k][cu] := k回移動済みで頂点cuにいるときのコスト最小値
遷移するときに二部グラフ確認を行うだけで、そこまで難しいDPではない。

典型問題らしい…
[乱択アルゴリズム紹介(Color-Coding) | Preferred Networks Research & Development](https://tech.preferred.jp/ja/blog/color-coding/)

# 補足
頂点1を黒色とすると、遷移中に黒色にするべき頂点は4頂点しかない。
何やら全探索できそうな感じがあり、全探索解法もTLには流れてきていた。
（枝刈り全探索か、適切な前計算だろう）
///////////////////////// writeup2 end */
