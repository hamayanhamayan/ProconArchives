//https://yukicoder.me/problems/no/897
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

int N, K;
//---------------------------------------------------------------------------------------------------
int solve() {
    cin >> N >> K;
    if(K == 1) return N - 1;

    ll tot = 1;
    ll kk = K;
    rep(d, 0, 1010)
    {
        if (N <= tot) return d;

        tot += kk;
        kk *= K;
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    int Q; cin >> Q;
    rep(q, 0, Q) cout << solve() << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
深さを最小化したいなら、なるべく子供をK個にするのがいい。
そうすると、密度が高まり、多くの頂点で深さを最小化できる。

あとは、計算だが、深さ基準で考えよう。
深さ0のときは、頂点が1個が最大。
深さ1のときは、頂点からK個子供を伸ばせばいいので、K+1が最大。
深さ2のときは、葉がK個なので、そこから子供の伸ばすので、K^2+K+1が最大。
これで、規則性がわかってきただろう。
深さdのときは、K^d+...+1が最大個数となる。
これを見ると、dが増えると、爆発的に数が増えそう。
なので、dを0から順番に確認していけばいい。
N≦K^d+...+1を満たす最小のdが答えになる。

K=1のときはゼロ割りになってしまうので、場合分けしよう。
その場合は、N-1が答え。
///////////////////////// writeup2 end */
