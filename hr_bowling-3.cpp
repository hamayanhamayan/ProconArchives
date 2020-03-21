//https://www.hackerrank.com/contests/75th/challenges/bowling-3
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












int N, P[101010], A[101010];
ll dp[101010][2];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> P[i] >> A[i];

    dp[0][1] = -infl;
    rep(i, 0, N) rep(isJust, 0, 2) {
        if (isJust) {
            chmax(dp[i + 1][0], dp[i][isJust] + P[i] * 2);
            chmax(dp[i + 1][1], dp[i][isJust] + A[i] * 2);
        }
        else {
            chmax(dp[i + 1][0], dp[i][isJust] + P[i]);
            chmax(dp[i + 1][1], dp[i][isJust] + A[i]);
        }
        
    }

    ll ans = max(dp[N][0], dp[N][1]);
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
特殊ルールとして、前のターンでA[i]ピッタリ倒すと次のターンは点数二倍になるというのがある。
ここから得られる、重要なことが「あるターンの状況を決定するには前のターンでピッタリだったかどうかだけが関係する」ということ。
よって、DPで前のターンのピッタリ具合を添え字に入れれば状態をまとめ上げることができる。

dp[i][isJust] := iターン目まで終わっていて、前のターンでピッタリだったかがisJustのときの最大点数
dp[0][0]=0だが、dp[0][1]はありえないので、-∞を入れておこう。

これで更新していけば答えなのだが、遷移がP[i]通りあるので、どうしようか。
ピッタリのときは1通りであるが、ピッタリじゃないときの遷移が多い。
ピッタリじゃないときは、最大ピンを倒すのが最適であり、他の選択はする必要がない（メリットがない）。
よって、遷移は2通りに限られるので、間に合う。
///////////////////////// writeup2 end */
//　