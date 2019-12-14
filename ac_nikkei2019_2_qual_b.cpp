//https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b
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
typedef ModInt<998244353> mint;
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/











int N, D[101010];
//---------------------------------------------------------------------------------------------------
mint solve() {
	map<int, int> cnt;
	rep(i, 0, N) cnt[D[i]]++;

	int n = cnt.size();
	rep(i, 0, n) if (cnt[i] == 0) return 0;
	if (cnt[0] != 1) return 0;
	if (D[0] != 0) return 0;

	mint res = 1;
	rep(i, 1, n) res *= mint(cnt[i - 1]) ^ cnt[i];
	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> D[i];
	cout << solve() << endl;
}


/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
300点問題ではあるが、累乗を使う所があるので、そのライブラリを持っていないと厳しい。
mod上での掛け算は理解しているとして進める（かけてmodとるだけだけど）。
後、色々コーナーケースがあるので注意。

根から順番に組み合わせを確定させていくことを考える。
頂点1は根なのでD[0]=1である必要があり、かつ、ここだけである必要がある。
cnt[d] := D[i]=dである頂点の個数
以上のように置くと、cnt[0]=1である必要がある。

距離が1の頂点について考えると、これは全て根につなげるしか無い。
よって、1通り。

距離が2の頂点について考える。
その中の1つの頂点について考えると、これを距離が1の頂点のどれかにつなげると考えるとcnt[1]通りある。
他の頂点についても同様であるため、距離が2の頂点を距離が1の頂点につなげる組み合わせは、
cnt[1]^cnt[2]通りとなる。
この計算は、以下も同様となるので、求めたい答えはcnt[i]^cnt[i+1]の総積である。

あと、距離は0から順番に存在する必要がある。
距離3と5の頂点はあるけど、距離4の頂点は無いというのはありえない。
///////////////////////// writeup2 end */
