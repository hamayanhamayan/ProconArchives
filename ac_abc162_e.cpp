//https://atcoder.jp/contests/abc162/tasks/abc162_e
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














int N, K;
mint cnt[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;

    rrep(g, K, 1) {
        cnt[g] = mint(K / g) ^ N;
        int gg = g * 2;
        while (gg <= K) {
            cnt[g] -= cnt[gg];
            gg += g;
        }
    }

    mint ans = 0;
    rep(g, 1, K + 1) ans += cnt[g] * g;
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [約数系包除](https://www.hamayanhamayan.com/entry/2017/04/17/161345)
///////////////////////// writeup2 start
この問題をACするには約数系包除を理解しないといけない。
だが、この問題は約数系包除を理解する入門問題としては最適であるので、やや真面目に書く。
とりあえず、約数系包除という言葉は忘れてもいい。

K=3,N=3であれば、
(1,1,1), (1,1,2), (1,1,3), (1,2,1), ...というすべての組み合わせであれば、
gcd(1,1,1) + gcd(1,1,2) + gcd(1,1,3) + gcd(1,2,1) + ...を計算すれば答え。
だが、これでは間に合わない。
主客転倒をする。
1 * (gcdが1となる数列の組み合わせ) + 2 * (gcdが2となる数列の組み合わせ) + 3 * (gcdが3となる数列の組み合わせ)
で計算可能である。
これがちょっとわからない場合は、全通りを書き下して、gcdが同じものが何個あるか数えてみると、雰囲気がわかる。

ありうるgcdは1～Kなので、O(K)なら大丈夫そうな雰囲気もある。
よって、「cnt[g] := gcdがgである数列の組み合わせ」が計算できれば解くことができ、これを解くことを考える。

「gcdがgである数列」というのは、最低限満たすべき条件として数列すべてがgの倍数であることが言える。
1～Nの中で、gの倍数はN/g個あるので、数列の1要素はN/g通りのパターンがある。
それが、N個分あるので、(N/g)^N通りがgcdがgの『倍数』である組み合わせとなる。
gの倍数を拾ってきているつもりでも、パターンの中に2gの倍数とかが含まれればgcdが2gになるかもしれない。
よって、このまま計算すると、gcdがgの倍数である組み合わせだけ得られる。

ここから、gcdがgである組み合わせを得るにはどうすればいいだろうか。
端的に説明すると、以下の式で計算する。
(gcdがgである組み合わせ) = (gcdがgの倍数である組み合わせ) - (gcdが2gである組み合わせ) - (gcdが3gである組み合わせ) - (gcdが4gである組み合わせ) -...
倍数の組み合わせを引いていくが、K以下までやればいい。
これはcntを大きい方から順に構成していくと考えると、既にgより大きい組み合わせは計算済みなので、計算することができる。
cnt[g] = (N/g)^N - cnt[2g] - cnt[3g] - ...
これをやれば、gcdがピッタリgである組み合わせが得られる。
毎回倍数を見て、やっていくと、間に合わない気もするが、エラトステネスの篩的（調和級数的）計算量により、O(KlogK)となり間に合う。
このように倍数（約数）に注目してダブりを抜いていく典型を「約数系包除」という。

[GCD Products hard | 灘校75回生中学卒業記念コンテスト Question | Contests | HackerRank](https://www.hackerrank.com/contests/75th/challenges/gcd-product-1)
類題がここにあるので、復習にこちらをやってみるのもいいだろう。
///////////////////////// writeup2 end */
