//https://atcoder.jp/contests/past202005-open/tasks/past202005_c
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
ll mul(ll a, ll b) { if (a == 0) return 0; if (infl / a < b) return infl; return min(infl, a * b); }
ll fastpow(ll x, ll n) {
    ll ret = 1;
    while (0 < n) {
        if ((n % 2) == 0) x = mul(x, x), n >>= 1;
        else ret = mul(ret, x), --n;
    }
    return ret;
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














int A, R, N;
int MA = 1e9;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> R >> N;

    ll an = mul(A, fastpow(R, N - 1));
    if (MA < an) cout << "large" << endl;
    else cout << an << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- 繰り返し二乗法
///////////////////////// writeup2 start
（公式解説見たら、解説の方がよっぽどいい方針でした。そちらがオススメ）
自分の解法はライブラリ貼るだけで終わりそうだったので、それでやった解法です。

まず、一番厳しい問題としてオーバーフローがある。
A=R=N=10^9という最大ケースを考えると、普通に第N項を計算しようとすると、
C++で楽に扱える10^18はゆうに越えてしまう。
pythonとかの多倍長整数が扱えれば大丈夫かもしれないが、このサイズ感はどうなんだろう（よくわからない）。
この問題を解決する上で少し重要なことなのだが、A, AR, AR^2, ...としていったときに広義単調増加となる。
つまり、ある地点で10^9より大きければ、それ以降はずっと大きくなる。
なので、計算過程である値より大きい値が出てきても、ある限界値でトリムしても大丈夫なことになる。

何を言ってるか分からないかもしれないので、具体例を出す。
計算に上限値を設けるということだ。
上限値を100として、10×20は200だけど上限100なので、100と計算する。
これで上限値を10^9+1としてやれば、最終的な結果が10^9+1以上であれば、
実際の計算結果がそれ以上であることはあまり問題ではなく、「large」が答えになる。

`ll mul(ll a, ll b) { if (a == 0) return 0; if (infl / a < b) return infl; return min(infl, a * b); }`
自分は、infl（10^18くらい)を上限値として掛け算する関数をライブラリとして持ってるので使った。

さて、上限付き掛け算を使うことでオーバーフロー対策ができることは分かった。
これを使って、AR^(N-1)を計算して10^9を越えているかどうかを判定できればよさそうだ。

A×はいいとして、R^(N-1)を高速に計算することが求められる。
これには繰り返し二乗法を使用する。
累乗計算の高速化として有名なので、どこかで学んできてほしい。
まあ、学んでしまえばもう終わりで、掛け算している所を上の上限付き掛け算にするだけで終わり。
///////////////////////// writeup2 end */
