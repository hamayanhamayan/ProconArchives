//https://atcoder.jp/contests/abc156/tasks/abc156_d
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














int N, A, B;
//---------------------------------------------------------------------------------------------------
mint count(int x) {
    // nCx
    mint res = 1;
    rep(i, 0, x) res *= N - i;
    rep(i, 1, x + 1) res /= i;
    return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> A >> B;

    mint ans = (mint(2) ^ N) - 1;
    ans -= count(A);
    ans -= count(B);
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [mod素数上での計算（割り算）](https://www.hamayanhamayan.com/entry/2018/06/06/210256)
- [繰り返し二乗法による累乗計算](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
本数制限がない場合を考えよう。
すると、N種類の花を使って作れる花束の数は2^N-1となる。
ある花をとるとらないの2通りがN個あるので、2^N通りであるが、1本は選ぶ必要があるので、
全部とらないとしている1通りを引いている。
答えはこれから、a本選んだときとb本選んだときを引いたものになる。

自分の実装ではmod10^9+7を扱うためにmintを使用している。
競プロ界隈はmodを扱うための自作クラスをよく使う人がいて、自分もその一人。

2^Nの計算方法は、繰り返し二乗法を用いる。
やりかたはググってほしい。
[ここ](https://www.hamayanhamayan.com/entry/2018/06/06/210256)を参考にしてもいい。
そのサイトでの知識は競プロでは必要になる。

count関数を作って、実装を考えよう。
count(x) := x本作る時の組み合わせ
これは二項係数のC(N,x)が答えになるが、この問題ではNがとても大きくて困る。
しかし、よく見るとxは10^5くらいである。
よって、高校で習うような公式を使って計算することができる。
///////////////////////// writeup2 end */
