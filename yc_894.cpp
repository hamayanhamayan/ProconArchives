//https://yukicoder.me/problems/no/894
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
ll mul(ll a, ll b) { if(infl/a<b) return infl; return min(infl, a*b); }
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
ll lcm(ll a, ll b) { if (a == infl || b == infl) return infl; return mul(a / gcd(a, b), b); }
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

ll T, A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> T >> A >> B;

    ll go1 = (T - 1) / A + 1;
    ll go2 = (T - 1) / B + 1;
    ll go12 = (T - 1) / lcm(A, B) + 1;

    ll ans = go1 + go2 - go12;
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
出発回数を計算するが、包除原理を用いる。
(バス1が出発 または バス2が出発) = (バス1が出発) + (バス2が出発) - (バス1が出発 かつ バス2が出発)
これをそれぞれ計算する。

「バス1が出発」の組み合わせは、(T-1)/A+1となる。
同様に「バス2が出発」の組み合わせは、(T-1)/B+1となる。
どちらも出発する組み合わせは、lcm(A,B)時間に出発するものなので、(T-1)/lcm(A,B)+1である。

注意点として、A,Bが10^18と大きいので普通にlcm(A,B)を取るとオーバーフローしてしまう。
オーバーフロー対策がなされているlcmを使おう。
///////////////////////// writeup2 end */
