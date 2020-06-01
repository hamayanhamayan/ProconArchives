//https://atcoder.jp/contests/abc169/tasks/abc169_f
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
template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
template<typename T, int FAC_MAX> struct Comb { vector<T> fac, ifac;
    Comb(){fac.resize(FAC_MAX,1);ifac.resize(FAC_MAX,1);rep(i,1,FAC_MAX)fac[i]=fac[i-1]*i;
        ifac[FAC_MAX-1]=T(1)/fac[FAC_MAX-1];rrep(i,FAC_MAX-2,1)ifac[i]=ifac[i+1]*T(i+1);}
    T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
    T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
    T nHk(int n, int k) { if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k); } // nHk = (n+k-1)Ck : n is separator
    T pairCombination(int n) {if(n%2==1)return T(0);return fac[n]*ifac[n/2]/(T(2)^(n/2));}
    // combination of paris for n
}; 
typedef ModInt<998244353> mint;
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, S, A[3010];
Comb<mint, 101010> com;
mint dp[3010][6010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;
	rep(i, 0, N) cin >> A[i];

    dp[0][0] = mint(2) ^ N;
    rep(i, 0, N) rep(tot, 0, S + 1) {
        dp[i + 1][tot] += dp[i][tot];
        dp[i + 1][tot + A[i]] += dp[i][tot] / 2;
    }

    cout << dp[N][S] << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
問題設定がややこしいが、慣れている人であれば、これは主客転倒テクをしてくれというメッセージにも見える。
一部が言ってるだけなので、あまり強調すると怒られそうだけれど、主客転倒テクという言い方は便利なので、
できれば使いたい。
主客転倒テクは、
「Aを全列挙して、それぞれに含まれるBの点数を全部計算して足す」
みたいな問題を
「Bを全列挙して、それが出てくるAの組合せを計算して、(Bの点数)×(Bが出てくる組み合わせの総和)」
のように言い換えること。
この手の言い換えはよく見るし、テクニックとしてもいいと思う。

さて、これを使ってどうするかであるが、
部分集合Tを全列挙して、f(T)を全部計算して足すのが、この問題。
f(T)というのは、Tから更に部分集合Xを取って総和がSとなる部分集合Xの個数。
主客転倒する。
今回の問題は、「総和がSとなる部分集合X」を部分集合に持つTの組合せの総和が答えと等しくなる。
(Bの点数)×(Bが出てくる組み合わせの総和)と比較してみると、Bの点数にあたる部分は1なので、消えている。
ここまでをまず理解しないと進まない。

ここまでしっかり理解できていれば、1つ目の山は越えられている。
「総和がSとなる部分集合X」を部分集合に持つTの組合せは何通りになるだろうか。
例えば、X={x1, x2, ..., xk}であるとすると、これを部分集合に持つTは少なくとも、Xは持っている。
それ以外は持っていてもいいし、持っていなくてもいい。
よって、2^(N-k)通りある。
この組合せで重要なのは集合Xの要素数だけである。
よって、総和がSである集合Xを考えるが、要素数を除いて抽象化して問題ないということだ。
以下のDPを考える。

dp[i][tot][k] := i番目までのAを使って、総和がtotで要素数がk個の組合せ
これを使えば、k=1..Nについてdp[N][S][k] * 2^(N - k)の総和が答え。
このDPを作るまでが2つ目の山。

このDPではO(SN^2)なので間に合わない。
もう1段落工夫が必要である。最後の山である。ここがきつい。
dp[i][tot][k]の更新式は

dp[i + 1][tot][k] += dp[i][tot][k]
dp[i + 1][tot + A[i]][k + 1] += dp[i][tot][k]

であり、最後にdp[N][S][k] * 2^(N - k)としている。
最後をちょっと変形してみると、dp[N][S][k] * 2^N / 2^kである。
つまりは、要素数分÷2をしている。
言い換えると、選択する遷移回数文÷2をしている。
よって、遷移式を以下のように変える。

dp[i + 1][tot][k] += dp[i][tot][k]
dp[i + 1][tot + A[i]][k + 1] += dp[i][tot][k] / 2

すると、最後はdp[N][S][k] * 2^Nとなる。
これが重要でkの要素を持っていたのは最後に必要だったからで、遷移に÷2を持ってくることで最終的に
kを使って係数を変えて足し合わせる必要がなくなった。
つまり、iとtotが同じであればkの違いによる計算の違いがなくなったことになる。
kの情報は必要なくなったので、削除しよう。

dp[i + 1][tot] += dp[i][tot]
dp[i + 1][tot + A[i]] += dp[i][tot] / 2

すると、dp[N][S] * 2^Nが答え。
自分の実装では初期値dp[0][0][0]=1ではなく、dp[0][0][0]=2^Nとして、答えをdp[N][S]としている。
///////////////////////// writeup2 end */
