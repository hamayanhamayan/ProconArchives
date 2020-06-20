//https://yukicoder.me/problems/no/1086
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














int N; ll L[101010], R[101010]; int D[101010];
mint dp[101010];
//---------------------------------------------------------------------------------------------------
mint count(ll r, int mo) {
    if (r == 0) return 0;
    return ((mint(10) ^ r) - 1) / 9;
}
mint count(ll L, ll R, int mo) {
    return count(R, mo) - count(L, mo);
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> L[i];
    rep(i, 0, N) cin >> R[i];
    rep(i, 0, N) cin >> D[i];

    dp[0] = 1;
    bool allzero = true;
    int mo = 0;
    rep(i, 0, N) {
        if (D[i] == 0) {
            if (allzero) dp[i + 1] = dp[i];
        }
        else {
            D[i] %= 9;
            if (mo == D[i] && !allzero) dp[i + 1] += dp[i];
            rep(nxt, 0, 9) if ((mo + nxt) % 9 == D[i]) dp[i + 1] += dp[i] * count(L[i], R[i], nxt);
            allzero = false;
            mo = D[i];
        }
    }
    cout << dp[N] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
[下位問題](https://yukicoder.me/problems/no/1085)があるので、そちらがまだならそちらを解いてから、こちらを考えるといい。
基本的には、下位問題と似たような感じになる。
数列の要素を数字根を計算して、その総和に対して更に数字根を計算しているのだが、
これは数列の要素の総和mod9としてしまっていい。
10^9+7問題なので、とりあえずDPを考えてみる。
dp[i] := i番目の要素まで確定してる時の組合せ
dpでやる必要もないのだが、実装しやすかったので使っている。

問題が、[10^L, 10^R)で9で割った余りがmoである数が何個あるかということになる。
count(L, R, mo) := [10^L, 10^R)で9で割った余りがmoである数が何個か
これを計算しよう。
まず簡単のために1からの区間で考えるようにしよう
count(r, mo) := [1, 10^r)で9で割った余りがmoである数が何個あるか
すると、count(L, R, mo) = count(R, mo) - count(L, mo)となる。

count(r, mo)の答えは(10^r-1)/9となる。
mod上ではうまく切り捨てとかはしてくれないので、適当にやってはいけないのだが、今回は10^rという制約が効いており、
うまくこの式でやれる。（余りの種類によって個数は変わらない、一様に分布してるので）
///////////////////////// writeup2 end */
