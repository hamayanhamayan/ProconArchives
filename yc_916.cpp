//https://yukicoder.me/problems/no/916
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
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













int D, L, R, K;
Comb<mint, 2010101> com;
int lft[21], rht[21];
int cnt[21];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> D >> L >> R >> K;

	lft[1] = rht[1] = 1;
	rep(d, 1, D) {
		lft[d + 1] = lft[d] * 2;
		rht[d + 1] = lft[d + 1] * 2 - 1;
	}
	rep(d, 1, D + 1) cnt[d] = rht[d] - lft[d] + 1;

	mint ans = 0;
	rep(dl, 1, D + 1) rep(dr, 1, D + 1) rep(dlca, 1, D + 1) {
		if (dlca > dl) continue;
		if (dlca > dr) continue;
		if ((dl - dlca) + (dr - dlca) != K) continue;

		if (lft[dl] <= L and L <= rht[dl] and lft[dr] <= R and R <= rht[dr]) {
			mint delta = 1;

			if (dl == dr) {
				delta *= cnt[dlca];
				delta *= cnt[dl] / cnt[dlca];
				delta *= cnt[dl] / cnt[dlca];
				delta /= 2;
			}
			else if (dl == dlca) {
				delta *= cnt[dlca];
				delta *= cnt[dr] / cnt[dlca];
			}
			else if (dr == dlca) {
				delta *= cnt[dlca];
				delta *= cnt[dl] / cnt[dlca];
			}
			else {
				delta *= cnt[dlca];
				delta *= cnt[dl] / cnt[dlca];
				delta *= cnt[dr] / cnt[dlca];
				delta /= 2;
			}

			rep(d, 1, D + 1) {
				if (dl == d and dr == d) delta *= com.fac[cnt[d] - 2];
				else if (dl == d or dr == d) delta *= com.fac[cnt[d] - 1];
				else delta *= com.fac[cnt[d]];
			}

			ans += delta;
		}
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
dがとても小さいので、深さ起点で考えれば良さそうな感じがする。
lが書き込まれる頂点の深さ、rが書き込まれる頂点の深さ、その2つのlcaの深さを全探索して、組み合わせ計算？
行けそうですね。

それぞれの深さをdl, dr, dlcaとして、深さがわかれば距離がわかるので、その距離がKであるかをまず確かめる。
後は、根性で（場所の組み合わせ）×（数の組み合わせ）を答える。
ある深さでの上限lft, 下限rhtと数の個数cntを用意すると実装が少し楽。
///////////////////////// writeup2 end */
