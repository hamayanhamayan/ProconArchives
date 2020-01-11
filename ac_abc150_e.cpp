//https://atcoder.jp/contests/abc150/tasks/abc150_e
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














int N, C[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> C[i];
	sort(C, C + N, greater<int>());

	mint ans = 0;
	rep(i, 0, N) ans += mint(i + 2) * C[i];
	rep(i, 0, N - 1) ans *= 4;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
多分、何から考えていいかわからない人が多いだろう。
何か限定的に考えていける部分がないか見てみると、とりあえずf(S,T)を求めるにはどうすればいいかというのがある。
操作すべきiは、S[i]!=T[i]部分だけであり、S[i]=T[i]を操作しても無駄であることは分かるだろう。
あとはどの順番で操作を行うかであるが、Dは単調減少していくので、C[i]の小さい順でやっていくのが
最適っぽい。
まあ、それはわかったけど、で？という雰囲気。

大体何かを全探索して、計算していくが、全探索できるのはC[i]くらい。
f(S,T)の総和は？*C[0]+？*C[1]+...となるので、この？の部分を高速に計算できれば、
C[i]で全探索することで、総和を求めることができる。
ちょっと飛躍した発想に見えるかもしれないが、？のような場合の数、組み合わせ的なものを求めて、
値と掛け合わせることで総和を求めるテクは多くの問題で見られる。

さて、残りの問題が、f(S,T)においてC[i]の係数が何であるかという問題になった。
元々の問題よりかはマシになったが、まだ難しい。
この係数が何を示すかというと、すべてのS[i]!=T[i]であるS,Tの組において、
S[j]!=T[j]であり、S[i]≦S[j]である個数の総和
具体的な数はここでは関係ないので、N, N-1, ... 3,2,1に対してこれを考えてみる。
降順になっているのは、以上の個数を考えていくからである。
これは期待値を考えると実は早い。
i番目の数において、C[i]≦C[j]の個数の期待値を考えると、(i + 1)/2である。
場合の数は4^(N-1)*2であるため、個数の総和は、期待値×場合の数で、(i+1)/2*4^(N-1)*2=4^(N-1)*(i+1)
4^(N-1)*2*C[0] + 4^(N-1)*3*C[1] + ...
=4^(N-1)*(2*C[0] + 3*C[1] + ...)
となり、これが答え。
///////////////////////// writeup2 end */
