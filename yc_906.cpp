//https://yukicoder.me/problems/no/906
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/










ll N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;

	mint ans = 0;
	ans += (N - 4) / 2 + 1;

	ll ma = (N - 4 - 3) / 3;
	if (0 <= ma) {
		ll even_ma = ma / 2;

		ans += mint(N / 2 - 3) * mint(even_ma + 1);
		if (N % 2) ans += mint(even_ma + 1);

		ans -= mint(3) * (even_ma + 1) / 2 * even_ma;
	}

	if (1 <= ma) {
		ll odd_ma = (ma-1) / 2;

		ans += mint((N - 9) / 2) * mint(odd_ma + 1);
		if ((N - 9) % 2) ans += mint(odd_ma + 1);

		ans -= mint(3) * (odd_ma + 1) / 2 * odd_ma;
	}

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
数列辞典にかけたい気持ちをぐっとこらえて考察する。

玉の分配を考えてみると、N個のうち4つはもう分配が決まっている。
次数3の玉が1つ。そこから3路あるが、それぞれ1つずつ玉を置く。
残りのN-4を3路に分配する。
N-4を3つに分けるが、同じ数で構成される組み合わせは排除したい。
これをうまくやる方法であるが、以下を満たすように組み合わせを求める。

- a + b + c = N - 4
- a ≦ b ≦ c

難しくないか？？
何かを全探索で計算することはできなさそう。
こういう数学系は場合分けか？式変形か？

a=b=cの場合は一通りでN-4が3で割り切れるか見ればいいけど、下の2つかぶっているときで見れるので特にいらない。
a,b,cのうち2つがかぶっているときは、あと一つはN-4-2*(被った数)で一意に定まるので、被った数を数えればいい。
これは、(N-4)/2+1通りありそう（+1は0の分）。

全部違うときが問題で、わからん。
解説を見ると、式変形してる。
うんうん。

最小値aを決めると、b,cにもa+1をあらかじめ割り当てておく。
すると、残りはN-(3a+6)となるので、これを2つに分ける。
例えば、残りが4ならば(0,4),(1,3)の2通り、残りが5ならば(0,5),(1,4),(2,3)の3通りとなる。
つまり、切り上げが組み合わせになる。
aの範囲は0～(N-4-3)/3である。-3はa,a+1,a+2が最小構成であるため。
ma = (N-4-3)/3としておこう。

sum{a=0..ma} ceil((N-(3a+6)) / 2)
が答え。
これは、ceilが扱いにくいので、aの偶奇で計算を分ける。
aが偶数なら、a=2Aとすると
sum{A=0..floor(ma/2)} ceil((N-(6A+6)) / 2)
= sum{A=0..floor(ma/2)} ( ceil((N / 2 - 3) - 3A )
= ceil(N / 2 - 3) * (floor(ma/2) + 1) - 3 * sum{A=0..floor(ma/2)} A

aが奇数なら、a=2A+1とすると
sum{A=0..floor((ma-1)/2)} ceil((N-(3(2A+1)+6)) / 2)
= sum{A=0..floor((ma-1)/2)} ( ceil((N - 9) / 2) - 3A )
= ceil((N-9) / 2) * (floor((ma-1)/2) + 1) - 3 * sum{A=0..floor((ma-1)/2)} A

ceilについてはNの偶奇で分けてやればいい。
sumについては等差数列の総和公式を使おう。
全然式が合わんくてきつかった
///////////////////////// writeup2 end */
