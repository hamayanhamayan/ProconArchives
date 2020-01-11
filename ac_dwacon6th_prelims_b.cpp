//https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_b
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, X[101010];
mint dp[101010];
Comb<mint, 201010> com;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> X[i];

	dp[0] = 0;
	mint tot = 0;
	rep(i, 1, N + 1) {
		dp[i] = (tot + i) / i;
		tot += dp[i];
	}

	mint ans = 0;
	rep(i, 0, N - 1) ans += mint(X[i + 1] - X[i]) * dp[i + 1];
	ans *= com.fac[N - 1];

	cout << ans << endl;

}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
なんだか昨日も[似た方針の問題](https://atcoder.jp/contests/abc150/tasks/abc150_e)を解いた気がするが、解くのに時間かかってしまった。
[昨日の問題の解説](https://www.hamayanhamayan.com/entry/2020/01/11/145124)も自分は書いていて、これと似たような方針で解けるのに類題として復習するのもいいだろう。

解法であるが、ぱっと見て、方針に悩んだ人も多いだろう。
スライムが移動した距離の総和の期待値を求めたいのだが、これは各スライム間の距離について期待値を取っていていくと同様の値を取れる。
これを「各スライム間の距離×その距離が足される回数の期待値」の総和で求めることにする。
なぜ、この総和が、スライムが移動した距離の総和の期待値になるのかであるが、このままだと分かりにくいと思う。
両方に場合の数、(N-1)!を書けると等しくなると分かるかもしれない。
スライムが移動した距離の総和の期待値×場合の数(N-1)!でスライムが移動した距離の総和となる。
「各スライム間の距離×その距離が足される回数の期待値」の総和×場合の数(N-1)!で「各スライム間の距離×その距離が足される回数」の総和となる。
この2つが等しいことを考える方が易しい。

さて、これで問題は、「その距離が足される回数の期待値」を求めることになる。
スライム1,2,3と並んでいるとする。
この時、スライム3と4の間の距離が足される回数に関係するのは、1,2,3の位置関係だけである。
例えば、123の順であれば3回足されるし、132であれば2回足される。
この回数は、最大の数から左方向に単調減少でどれだけ取れるかと等しい。
123であれば、3から始めて3→2→1で3つ。
132であれば、3から始めて3→1で2つ。
仮に、143627であれば、7→6→3→1で4つ。
この計算には特に距離は関係ないので、考えるべきスライムの個数を順列の個数と考えて期待値を計算すればいい。
これは挿入DPで計算可能である。

dp[i] := i個の順列を並び替えた全通りについての上記の個数の期待値
元々i-1個ある順列に対して数iを加えてi個の順列にすることを考える。
加えることができる部分はi通りあるので、それぞれ1/iの確率となる。
個数で関係するのは、追加した部分より前の部分であり、その部分での期待値から+1されるため、更新式は以下のようになる。
dp[i] = (dp[0] + 1) / i + (dp[1] + 1) / i + (dp[2] + 1) / i + (dp[3] + 1) / i + ... + (dp[i - 1] + 1) / i
dp[0]～dp[i-1]をtotとして累積和で持っておくと、
dp[i] = (dp[0] + dp[1] + dp[2] + dp[3] + ... + dp[i - 1] + i) / i
dp[i] = (tot + i) / i
これで、「その距離が足される回数の期待値」が得られるので、あとは、距離との積の総和を取って、問題に指定のあるように(N-1)!をかけて答えると答え。
///////////////////////// writeup2 end */
