//https://yukicoder.me/problems/no/1011
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
    ModInt& operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt& operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r;
}
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














int N, d, K;
mint dp[303][101010];
mint tot[303][101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> d >> K;
    
    dp[0][0] = 1;
    rep(turn, 0, N) {
        tot[turn][0] = dp[turn][0];
        rep(i, 1, K + 1) tot[turn][i] = dp[turn][i] + tot[turn][i - 1];
        rep(i, 1, K + 1) {
            dp[turn + 1][i] = tot[turn][i - 1];
            if (0 <= i - d - 1) dp[turn + 1][i] -= tot[turn][i - d - 1];
        }
    }

    cout << dp[N][K] << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [累積和を用いた動的計画法高速化](https://www.hamayanhamayan.com/entry/2017/03/20/234711)
///////////////////////// writeup2 start
10^9+7数え上げ、かつ、既視感のある問題なので、DP解法から考え始める。
すると、以下のDPなら解けることが分かる。

dp[turn][i] := 行動をturn回行って、i段目にいる移動方法の組み合わせ
これの遷移は、1回の行動で何階分移動するかでd通りになる。
これで状態数がO(dN^2)で、遷移がO(d)となるため、状態数は解ける範囲内だが、遷移まで入れると間に合わない。
遷移の更新分を高速化することで、解くことはできないだろうか。
まずは、このDPの更新式。

```
    dp[0][0] = 1;
    rep(turn, 0, N) rep(i, 0, K + 1) rep(delta, 1, d + 1) {
        dp[turn + 1][i + delta] += dp[turn][i];
    }
```

これは配るDPになっているので、貰うDPに変換する。
配るDPとは遷移元から遷移先を更新していく形で、遷移先に添え字の差分が入る。
貰うDPとは遷移先から遷移元を参照して更新していく形で、遷移元に添え字の差分が入る。

```
    dp[0][0] = 1;
    rep(turn, 0, N) rep(i, 0, K + 1) {
        rep(delta, 1, min(i, d) + 1) dp[turn + 1][i] += dp[turn][i - delta];
    }
```

これを見ると、1つ前のターンのある区間の総和を使って更新していることが分かる。
区間の総和は事前に累積和を取っておけば計算可能だ。

ターンの頭で以下の累積和を取っておこう。
tot[turn][i] := dp[turn][0] + dp[turn][1] + ... + dp[turn][i]
あとは、これを使ってdelta変数を使ったfor文部分を累積和による更新に置き換えると更新がO(1)となって間に合う。
///////////////////////// writeup2 end */
