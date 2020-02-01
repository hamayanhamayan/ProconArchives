//https://yukicoder.me/problems/no/980
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














int p, Q;
mint B[2010101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> p >> Q;
	
	B[4] = 1;
	rep(i, 5, 2010101) {
		B[i] = B[i - 1] * 2 * p
			+ (mint(2) - mint(p) * mint(p)) * B[i - 2]
			- B[i - 3] * 2 * p
			- B[i - 4];
	}

	rep(_, 0, Q) {
		int q; cin >> q;
		printf("%d\n", B[q].get());
	}
}





/* ///////////////////////// writeup1 start
# 前提知識
- [母関数](https://www.hamayanhamayan.com/entry/2019/12/14/221205)
///////////////////////// writeup2 start
問題を見ると数列を作成して、畳込み計算をすれば答えられる。
今回は、各所で解説されている母関数で解く方法を解説しよう。

まず、元々の数列は線形漸化式になっているので、多項式の積によって遷移を表現することができる。
母関数をf(T)=A[1] T + A[2] T^2 + ...としておこう。
すると、1回の遷移は(pT+T^2)の積で表現できるので、
f(T)=f(T)(pT+T^2) + T^2
と表現できる。最後のT^2は初期値A[2]=1を反映している。
きれいにするとf(T)=T^2/(1-pT-T^2)となる。

求めたいものは畳み込み計算されたものになる。
2数列の畳み込みは、母関数の積で計算可能なので、畳込み計算した求めたい数列をBとすると、
母関数はg(T)={f(T)}^2となる。
きれいにすると、g(T)=T^4/(1-2pT+(p^2-2)T^2+2pT^3+T^4)となる。
分子が初期値になってるので、B[0]=B[1]=B[2]=B[3]=0, B[4]=1が初期値。
分母が遷移になっているので、B[n]=2pB[n-1]+(2-p^2)B[n-2]-2pB[n-3]-B[n-4]となる。
これを事前計算しておけば、クエリでは答えるだけになる。
///////////////////////// writeup2 end */
