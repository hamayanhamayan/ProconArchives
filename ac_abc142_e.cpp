//https://atcoder.jp/contests/abc142/tasks/abc142_e
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

int N, M, A[1010], B[1010], takara[1010];
int dp[1010][1 << 12];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, M) {
        cin >> A[i] >> B[i];
        rep(j, 0, B[i]) {
            int c;
            cin >> c;
            c--;
            takara[i] |= 1 << c;
        }
    }

    rep(i, 0, M + 1) rep(msk, 0, 1 << N) dp[i][msk] = inf;
    dp[0][0] = 0;

    rep(i, 0, M) rep(msk, 0, 1 << N) {
        chmin(dp[i + 1][msk], dp[i][msk]);
        chmin(dp[i + 1][msk | takara[i]], dp[i][msk] + A[i]);
    }

    int ans = dp[M][(1 << N) - 1];
    if (ans == inf) ans = -1;
    cout << ans << endl;
}






/* ///////////////////////// writeup1 start
# 前提知識
- [bitDP](https://www.hamayanhamayan.com/entry/2017/07/16/130151)
///////////////////////// writeup2 start
Nの制約がかなり小さい。
2^12は4000くらい。
Mも1000であり、4000×1000は間に合う量である。
bitDPをしよう。
dp[i][msk] := i番目の鍵まで使用するかが決まっていて、開けられる宝箱の集合がmskであるのに必要な費用の最小値
ここまで来ていて、bitDPを理解していればそんなに難しくはない。
予め「takara[i] := i番目の鍵を使用したときに開けられる宝箱の集合」を作っておけば、実装がスムーズになる。
///////////////////////// writeup2 end */