//https://atcoder.jp/contests/abc156/tasks/abc156_e
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
    // nHk = (n+k-1)Ck : n is separator
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














int N, K;
Comb<mint, 401010> com;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;
    chmin(K, N - 1);

    mint ans = 0;
    rep(zero, 0, min(K + 1, N)) ans += com.aCb(N, zero) * com.nHk(N - zero, N - (N - zero));
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [mod上での二項定理](https://www.hamayanhamayan.com/entry/2018/06/06/210256)
///////////////////////// writeup2 start
どこから手を付ければよいか分からなかったかもしれない。
今回数えたい組み合わせは、手順ではなく最終的な状態である。
どのような条件を満たせば作成可能で、それが何通りあるかを数えよう。

具体的には以下の条件を満たせば、作ることができる。
- 人数の合計が合計N人
- 人が誰もいない部屋がK個以下
この仮定を導き出すのが難しい。

人が誰もいない部屋という条件が少し特殊なので、これを全探索して数え上げていこう。
誰もいない部屋がzero個で、残りの部屋でN人を振り分ける組み合わせは、
C(N, zero) * H(N - zero, N - (N - zero))
となる。
C(N, zero)は誰もいない部屋をどう選ぶかの組み合わせ
H(N - zero, N - (N - zero))がN人を残りでどう置くかの組み合わせ。
もう少し細かくすると、N - zeroは人を配置する部屋の個数で、
N - (N - zero)は、実際に配分する人数であり、N個から(N-zero)を引いているのは、
(N - zero)個分の配置する部屋があり、そこには1人すでに配置しておくためである。
///////////////////////// writeup2 end */
