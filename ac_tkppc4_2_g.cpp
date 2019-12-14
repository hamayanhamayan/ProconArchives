//https://atcoder.jp/contests/tkppc4-2/tasks/tkppc4_2_g
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














int N, K, A;
int a[2010], b[2010], c[2010], d[2010];
//---------------------------------------------------------------------------------------------------
double dp[2010][2010][2];
bool check(double ave) {
    rep(i, 0, N + 1) rep(k, 0, K + 1) rep(taibu, 0, 2) dp[i][k][taibu] = -1e18;
    dp[0][K][0] = A - ave;

    rep(i, 0, N) rrep(k, K, 0) {
        // そのまま採用
        chmax(dp[i + 1][k][0], max(dp[i][k][0], dp[i][k][1]) + a[i] - ave);

        // 退部
        if(0 <= k - d[i]) chmax(dp[i + 1][k - d[i]][1], max(dp[i][k][0], dp[i][k][1]));

        // 強化
        if(0 <= k - c[i]) chmax(dp[i + 1][k - c[i]][0], dp[i + 1][k][0] + b[i]);
    }

    double ma = -1e18;
    rep(k, 0, K + 1) rep(taibu, 0, 2) chmax(ma, dp[N][k][taibu]);
    return 0 <= ma;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K >> A;
    rep(i, 0, N) cin >> a[i] >> b[i] >> c[i] >> d[i];

    double ok = 0, ng = 1e18;
    rep(_, 0, 100) {
        double md = (ng + ok) / 2;
        if(check(md)) ok = md;
        else ng = md;
    }
    printf("%.5f\n", ok);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
- [DP](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
制約が割と小さい。小課題でヒントとして与えられている情報を考えると、dpできそうな感じがする。
dp[i][k] := i番目の人まで操作が完了していて、体力がkだけ残っている時のレーティングの総和の最大値
これをやれば、遷移でO(K)なので、O(NK^2)で300点であれば、間に合う。
とりあえず、これの高速化を考えてみよう。
遷移がO(K)で多いのが問題っぽいので、これを何とかする方針で考える。
操作の回数によって、特に加点があるわけではないため、遷移を1回にとどめて、それを伝搬させることはできないだろうか。
これはできるんじゃないか？
だが、退部させてしまっては、それができないので、それに対するフラグをDPに追加しよう。
dp[i][k][taibu] := i番目の人まで操作が完了していて、体力がkだけ残っていて、最後の部員が退部しているかがtaibuである時のレーティングの総和の最大値
これで行けそうだが、退部させたときは分母が減っている。
これはどうやって扱おうか。
これについては、平均を前もって決めておくことで行える。
平均を決めておけば、その平均との差の総和をとった時に0以上であれば、それが達成できることになる。
よって、答えの平均を二分探索して、
dp[i][k][taibu] := i番目の人まで操作が完了していて、体力がkだけ残っていて、最後の部員が退部しているかがtaibuである時の(レーティング-平均)の総和の最大値
これを計算すればいい。
///////////////////////// writeup2 end */
