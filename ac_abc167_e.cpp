//https://atcoder.jp/contests/abc167/tasks/abc167_e
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














int N, M, K;
Comb<mint, 1010101> com;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M >> K;

    if (N == 1) {
        cout << M << endl;
        return;
    }

    if (M == 1) {
        if (N - 1 == K) cout << M << endl;
        else cout << 0 << endl;
        return;
    }

    mint ans = 0;
    rep(k, 0, K + 1) ans += com.aCb(N - 1, k) * M * (mint(M - 1) ^ (N - 1 - k));
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、素数mod上での四則演算とコンビネーションが計算できるようにしよう。
[二項係数 mod 素数を高速に計算する方法 [累積和, フェルマーの小定理, 繰り返し二乗法, コンビネーション, 10^9+7] - はまやんはまやんはまやん](https://www.hamayanhamayan.com/entry/2018/06/06/210256)
このライブラリがあることがACの必要条件。

どこから数え上げようかと思うところであるが、何かを固定することで計算しやすくなる部分が無いか探す。
問題を見ると、固定する部分の候補として「隣り合うブロックで同色である部分の個数」がある。
この個数をk個としておく。
すると、k=0,1,...,Kの場合の組合せの総和を取れば答えになる。

少しシンプルになった。
隣り合うブロックの組であって、同じ色で塗られている組がk個であるとする。
ここからちょっと飛躍が必要なのだが、隣り合うブロック部分はN-1個あるが、
そのN-1個のうち、どこにk個等しくなる部分があるかを考える。
これはC(N-1, k)通りある。
そして、実は、その全ての組について色の塗り方は等しくなり、M×(M-1)^(N-1-k)通りとなる。

分かりやすさのために、N-1個のうち最初のk個が同色になっていると考えよう。
すると、1番目はM色の選択ができ、そこから次のk個は色が同じである必要があるため、1通り、
それ以降は、前のブロックとは違う色にする必要があるので、M-1通りとなる。
よって、(1番目)×(同じにする)×(異なるようにする)で、M×1^K×(M-1)^(N-1-k)であり、M×(M-1)^(N-1-k)となる。
これが、最初のk個が同色以外のパターンでも考えてみると、前のブロックと同じにする回数と
前のブロックと異なるようにする回数は同じになるため、結局M×(M-1)^(N-1-k)となる。

よって、各kについて、C(N-1, k)×M×(M-1)^(N-1-k)となり、これの総和を取ると答えになる。
自分の解法では、なんとなくN-1,M-1があるので、N=1とM=1の時は念のため場合分けしている。
もしかしたら、いらないかも。
///////////////////////// writeup2 end */
