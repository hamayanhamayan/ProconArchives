//https://www.hackerrank.com/contests/75th/challenges/i-want-to-be-a-high-achiever
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
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












int N, X, A[501], B[501];
int dp[501][201010];
int offset = 100005;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> X;
    bool ok = false;
    rep(i, 0, N) {
        cin >> A[i];
        if (X <= A[i]) ok = true;
    }
    rep(i, 0, N) cin >> B[i];

    if (!ok) {
        cout << -1 << endl;
        return;
    }

    rep(i, 0, N + 1) rep(tot, 0, 201010) dp[i][tot] = inf;
    dp[0][offset] = 0;

    rep(i, 0, N) rep(tot, 0, 201010) if(dp[i][tot] != inf) {
        chmin(dp[i + 1][tot], dp[i][tot] + B[i]);
        chmin(dp[i + 1][tot + A[i] - W], dp[i][tot]);
    }

    int ans = inf;
    rep(tot, offset, 201010) chmin(ans, dp[N][tot]);
    cout << ans << endl;

}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
重要なテクがあり、これが適用できれば、ACにだいぶ近づく。
「A[i]の平均がX以上 <=> A[i]-Xの総和が0以上」
平均を実際に求めようと思うと、総和と個数の2種類の情報が必要になるが、
このテクを使えば、総和だけを見ることで平均がX以上になるかを判定できる。
これで変数を1つ減らすことで間に合うDPを作成できる。

dp[i][tot] := i番目までの教科を処理済みで、X[i]-Xの合計がtotのときの必要コストの最小値
遷移は、以下の2種類。chmin(A,B)はA=min(A,B)の意味

- その教科を残す `chmin(dp[i + 1][tot + A[i] - W], dp[i][tot])`
- その教科を消す `chmin(dp[i + 1][tot], dp[i][tot] + B[i])`

注意点としてtotは負の数になる可能性があるので、offsetを使って0を中心に持ってこよう。
///////////////////////// writeup2 end */