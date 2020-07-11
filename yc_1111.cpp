//https://yukicoder.me/problems/no/1111
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














int N, M, K;
vector<pair<int, int>> E[303];
mint dp[303][606][303];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M >> K;

    rep(i, 1, 301) E[0].push_back({ i, 0 });
    rep(i, 0, M) {
        int a, b, c; cin >> a >> b >> c;
        E[a].push_back({ b, c });
    }

    dp[0][0][0] = 1;
    rep(i, 0, N) rep(k, 0, K + 1) rep(lst, 0, 301) {
         fore(p, E[lst]) dp[i + 1][k + p.second][p.first] += dp[i][k][lst];
    }

    mint ans = 0;
    rep(lst, 1, 301) ans += dp[N][K][lst];
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
mod10^9+7数え上げなので、まずはDP。
先頭から順番に決めていくとして、最後の要素だけがそれ以降の処理に関係してくるし…DPだな

## 動的計画法

dp[i][k][lst] := i番目までコードが確定していて、現状の複雑度がkであり、最後のコードがlstである組合せ

ちょっと複雑なDPを練習している諸君は割とすぐ思いつくかもしれない。
先頭からi番目まで確定している状態で、抽象化に必要な特徴量としては「複雑度」と「最後のコード」なので、
これを状態に持たせる。

状態数は既に27*10^6なので、遷移であまり無茶はできない。
遷移としては、次にどのコードを持ってくるかという選択なので、300通りの選択肢が考えられる。
これを愚直にやってしまうと、91*10^8なので、無理っぽくないというレベル（というかTLEしました）。
そこで、遷移先を必要なものだけに限定する。

## 遷移先を必要なものだけに限定

最後のコードと次のコードを全探索すると、300×300通りとなるが、
最後のコードと次のコードのうち、使えるコード進行に限定すると、M通りに削減することができる。
これで計算量を削減しよう。
この削減テクは、グラフの探索をするときに隣接行列を使うよりも、隣接グラフを使う方が計算量がいいのと同じ原理。
なので、
E[lst] := {使えるコード進行の先, 複雑度}の配列
を使って、必要な遷移先だけにループを限定すると、通る。
O(NMK)
///////////////////////// writeup2 end */
