//https://www.hackerrank.com/contests/eeic-programming-contest-0/challenges/brackets-restoring
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
    T nHk(int n, int k) { if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k); } // nHk = (n+k-1)Ck : n is separator
    T pairCombination(int n) {if(n%2==1)return T(0);return fac[n]*ifac[n/2]/(T(2)^(n/2));}
    // combination of paris for n
}; 
typedef ModInt<1000000007> mint;
/*---------------------------------------------------------------------------------------------------
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












int N, K; string S;
//---------------------------------------------------------------------------------------------------
Comb<mint, 2010101> com;
mint solve() {
	int p = 0, m = 0, diff = 0;
	rep(i, 0, K) {
		if (S[i] == '(') p++, diff++;
		else m++, diff--;

		if (diff < 0) return 0;
	}
	
	if (N < p) return 0;
	if (N < m) return 0;

	int pp = N - p;
	int mm = N - m;

	return com.aCb(pp + mm, pp) - com.aCb(pp + mm, mm - (diff + 1));
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K >> S;
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [カタラン数](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
二乗のDP解法はすぐに思いつく。
dp[i][diff] := 足りない部分のi文字目まで確定していて(の個数-)の個数がdiffのときの組み合わせ数
カッコの組み合わせといえばカタラン数であり、組み合わせは二項係数を使ってうまいこと計算が可能。
記憶している部分の(の個数をp, )の個数をmとする。
最終的に(と)の個数は一致している必要があるので、(の個数はpp=N-p, )の個数はmm=N-mとなる。
なので、Comb(pp+mm,pp)をすればだいたい良い。
大体いいが、途中で(の個数-)の個数が負になる可能性がある。
このパターンを引くが、これはカタラン数の計算で使われてるテクと同じテクを使おう。
元々の問題は切片1の所に直線があるが、今回は切片(diff+1)の所に直線が引かれることになるので、それで計算する。

本体の問題を解く前にpとmを数えて、既にdiffが負になっていないか、p,mがNを超えていないかをチェックしておこう。
///////////////////////// writeup2 end */
