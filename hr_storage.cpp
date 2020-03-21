//https://www.hackerrank.com/contests/oyamac/challenges/storage
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












int A, N, K, W[1010];
bitset<1010> dp[2][1010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> N >> K;
    rep(i, 0, N) cin >> W[i];

    dp[0][0].set(0);
    rep(i, 0, N) {
        int cu = i % 2;
        int ne = 1 - cu;
        rep(k, 0, K + 1) dp[ne][k].reset();

        rep(k, 0, K + 1) {
            dp[ne][k] |= dp[cu][k];
            dp[ne][k + 1] |= dp[cu][k] << W[i];
        }
    }

    rep(k, 0, K + 1) if (dp[N % 2][k][A]) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [bitsetによる動的計画法高速化](https://www.hamayanhamayan.com/entry/2017/06/07/234608)
///////////////////////// writeup2 start
見た目、ナップサック問題に近いし、yes/no系動的計画法でよく見る形でもあるので、
yes/no系動的計画法で解くことを考えてみよう。

以下のようなDPが思いつく。

dp[i][k][w] := i個目までの荷物を使って、k個の荷物を選択したときに、容量wが達成できるか
dp[i][k][w] = dp[i - 1][k][w] | dp[i - 1][k - 1][w - W[i]]

DPのサイズは10^3*10^3*10^3なので、かなりギリギリ。
だが、この遷移はbitset高速化ができる形になっている。

最後のwをbitsetのbitで表現することにすると、更新式は以下のように変わる。
dp[i][k] = dp[i - 1][k] | (dp[i - 1][k - 1] << W[i])
これで/64するので間に合うようになる。
///////////////////////// writeup2 end */
//　