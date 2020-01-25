//https://atcoder.jp/contests/abc152/tasks/abc152_e
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
map<int, int> enumpr(int n) {
    map<int, int> V;
    for (int i = 2; 1LL*i*i <= n; i++) while (n%i == 0) V[i]++, n /= i;
    if (n>1) V[n]++;
    return V;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[10101];
map<int, int> primes[10101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) primes[i] = enumpr(A[i]);

	map<int, int> allPrimes;
	rep(i, 0, N) fore(p, primes[i]) chmax(allPrimes[p.first], p.second);
	mint lcm = 1;
	fore(p, allPrimes) lcm *= mint(p.first) ^ p.second;

	mint ans = 0;
	rep(i, 0, N) {
		mint b = lcm / mint(A[i]);
		ans += b;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [LCM](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
条件を簡単にしよう。
条件をよくみると、A[i]B[i]=A[j]B[j]が全組み合わせある感じである。
ということは、全てのA[i]B[i]が同じ数になるという条件になることがわかる。

全てのA[i]B[i]が同じになるようにB[i]を決めて、かつ、B[i]の総和の最小値をとるという問題である。
ちょっとメタ読みな発想であるが、総和のmodの最小値というのは、modになっちゃってるので、
DPで比較みたいなことはできない。
なので、ある最適方針があるのではないかという方針で考える。

ある数をかけて全て同じ数にするというのは、公倍数と同じである。
そして、B[i]の総和を最小化したいということなので、最小公倍数を計算せよという問題となる。
なのでA[i]を素因数分解して、各素因数毎に個数の最大値を取って、全部合わせて最小公倍数を作ろう。
B[i]は最小公倍数/A[i]となるので、これをmod10^9+7でやったら、でてくる。
これの総和が答え。

自分の解法ではmintでmod10^9+7計算を全て隠蔽してある。
///////////////////////// writeup2 end */
