//https://atcoder.jp/contests/kupc2019/tasks/kupc2019_d
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
template<typename T, int FAC_MAX> struct Comb {
	vector<T> fac, ifac;
	Comb() {
		fac.resize(FAC_MAX, 1); ifac.resize(FAC_MAX, 1); rep(i, 1, FAC_MAX)fac[i] = fac[i - 1] * i;
		ifac[FAC_MAX - 1] = T(1) / fac[FAC_MAX - 1]; rrep(i, FAC_MAX - 2, 1)ifac[i] = ifac[i + 1] * T(i + 1);
	}
	T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
	T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
	// nHk = (n+k-1)Ck : n is separator
	T nHk(int n, int k) {
		if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
		return aCb(n + k - 1, k);
	} 
	// combination of paris for n
	T pairCombination(int n) { if (n % 2 == 1)return T(0); return fac[n] * ifac[n / 2] / (T(2) ^ (n / 2)); }
	// (0,0) -> (a,b)   constraint: y <= x
	T catalanNumber(int a, int b) {
		return aCb(a + b, a) - aCb(a + b, b - 1);
	}
};
typedef ModInt<998244353> mint;
vector<pair<char, int>> runLengthEncoding(string s) {
	int n = s.length();

	vector<pair<char, int>> res;
	char pre = s[0];
	int cnt = 1;
	rep(i, 1, n) {
		if (pre != s[i]) {
			res.push_back({ pre, cnt });
			pre = s[i];
			cnt = 1;
		}
		else cnt++;
	}

	res.push_back({ pre, cnt });
	return res;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/











Comb<mint, 201010> com;
int N;
string S;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;

	auto rl = runLengthEncoding(S);

	mint ans = 1;
	fore(p, rl) ans *= com.catalanNumber(p.second, p.second);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
順列を2グループに分けていく問題であるが、小さいほうから確定させていくことを考える。
01を作る場合は

```
千| 0
月| 

千| 0
月| 1

千| 0
月| 12

千| 03
月| 12
```

となる。負ける方に先に割り当てていく。
010101の場合は操作は一意に定まるが、0011の場合は違う。

```
千| 0
月| 

ここまではいいが、次が分岐する

千| 01
月| 2

千| 02
月| 1

ここからは一本道。

千| 01
月| 234

千| 02
月| 134

ここからもそれぞれ分岐（上でだけ分岐させてみる）。

千| 0157
月| 2346

千| 0167
月| 2345
```

このように、連続している部分で分岐が起こり、境目で一旦戻ることになる。
よって連続している部分での組み合わせを掛け合わせていくと答えになる。

連続していくとどれだけの組み合わせがあるかであるが、実はカタラン数というのに帰着する。
例えば、千咲さんに配ることを(、月乃瀬さんに配ることを)として、4回勝負ですべて月乃瀬さん勝利とすると、
(が4つ、)が4つで正しいかっこ列を作ることと配り方が丁度対応する。
これは直感的でないかもしれないが、どんなターンでも千咲さんが必ず多いという制約があることから分かるだろう。
この正しいかっこ列の組み合わせはカタラン数と丁度一致する。
カタラン数は、二項係数を使った効率的な計算方法がよく知られている。
よって、それを使うと解ける。


///////////////////////// writeup2 end */
