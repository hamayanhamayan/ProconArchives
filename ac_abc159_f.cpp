//https://atcoder.jp/contests/abc159/tasks/abc159_f
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
enum { NONE, L, LR };
mint dp[3010][6010][3];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;
	rep(i, 0, N) cin >> A[i];

    dp[0][0][NONE] = 1;
    rep(i, 0, N) rep(sm, 0, S + 1) rep(state, 0, 3) {
        rep(nxt, state, 3) {
            dp[i + 1][sm][nxt] += dp[i][sm][state];
            if(nxt != NONE && state != LR) dp[i + 1][sm + A[i]][nxt] += dp[i][sm][state];
        }
    }
    cout << dp[N][S][LR] << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
DPを使ってまとめて数え上げることができる。
思いつく仮定としては、DPで解くんだろうと考え始めることと、N,S≦3000なので、dp[N][S]系だろうで
考えることで思いつく。

dp[i][sm][state] := i番目まで使って、区間の総和がsmで、区間の選択状態がstateのときの組み合わせ
stateは0がNone（区間未選択）、1がL（左端のみ確定している）、2がLR（右端も左端も確定している）
遷移としては、次にどの状態に遷移するかの3択と、その要素を使用するか使用しないかの2択の掛け合わせである。

要素が使用できるのは、状態がLかLRのときで、かつ、前の状態がLRでないときである。
前の状態がLRで、今の状態もLRのときは、それよりも前でRが確定していて、今は範囲外にあるので、
要素を使って総和Kに貢献することはできないためである。

状態遷移は値が小さい方には遷移できない。
あとは、オーバーフローにちょっと注意すること。
dp[N][S][LR]が答えになる。
///////////////////////// writeup2 end */
