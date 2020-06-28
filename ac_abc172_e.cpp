//https://atcoder.jp/contests/abc172/tasks/abc172_e
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
    // nHk = (n+k-1)Ck : n is separator (k balls to n boxs)
    T nHk(int n, int k) { if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k); }
    T pairCombination(int n) {if(n%2==1)return T(0);return fac[n]*ifac[n/2]/(T(2)^(n/2));}
    // combination of paris for n
}; 
typedef ModInt<1000000007> mint;
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M;
Comb<mint, 1010101> com;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    
    mint ans = 0;
    rep(same, 0, N + 1) {
        mint cnt = com.aCb(N, same) * com.aPb(M, same) * com.aPb(M - same, N - same) * com.aPb(M - same, N - same);
        if (same % 2 == 0) ans += cnt;
        else ans -= cnt;
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [個数系包除原理](https://www.hamayanhamayan.com/entry/2017/04/17/161345)
- [素数mod上での二項係数](https://www.hamayanhamayan.com/entry/2018/06/06/210256)
///////////////////////// writeup2 start
もうこの手の問題をやりすぎて、何となく包除かな？という所からそれっぽいコードを書いて、サンプルが合ったので出したらACだった。
以下、試行手順を作って記載する。

## 難しい所はどこか

数列を二つ縦に並べたときに横も縦もダブってる数が無いようにするのが条件。
数列内でダブりが無いように数えるのはそれほど難しくはないが、数列間でのダブりを抑えるのが難しい。
適当に作ったときに2箇所ダブったり、3箇所ダブったり、NGの部分の個数が変わってしまう。
このようにNGの個数が変わるような問題はかなり難しそうに見えるが、包除原理に慣れると包除原理で解決できるアレだとなる。

## 包除原理

包除原理といえば、
n(AorBorC) = n(A) + n(B) + n(C) - n(A&B) - n(B&C) - n(C&A) + n(A&B&C)
というものであるが、
もし、「cnt[i] := i個の&で表現できる組み合わせ数」が高速に計算できれば、
n(AorBorC) = cnt[1] - cnt[2] + cnt[3]
のように個数に着目した包除原理に変換することができる。

これを今回の問題でも応用しよう。
cnt[same] := A[i]=B[i]である部分がsame個以上ある組合せの個数
こうすると、答えはcnt[0] - cnt[1] + cnt[2] - cnt[3] +...となる。

## cntの計算

cnt[same]が計算できれば、もう答えが導けるが、これは高校の組合せ計算をする。
結論から言うとこれが組合せ。
com.aCb(N, same) * com.aPb(M, same) * com.aPb(M - same, N - same) * com.aPb(M - same, N - same)
分けて書く。

- com.aCb(N, same) : N要素のうちどのsame個の要素が同じか
- com.aPb(M, same) : [1,M]の数からsame個の同じ所に数を割り当てる
- com.aPb(M - same, N - same) : 同じ数に割り当てていない数を配列Aの同じじゃないところに割り当てる
- com.aPb(M - same, N - same) : 同じ数に割り当てていない数を配列Bの同じじゃないところに割り当てる

素数mod上での二項係数ライブラリを用意しておく必要がある。
///////////////////////// writeup2 end */
