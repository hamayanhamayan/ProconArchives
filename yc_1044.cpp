//https://yukicoder.me/problems/no/1044
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














int N, M, K;
Comb<mint, 401010> com;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M >> K;

    mint ans = 0;
    rep(m, 1, M + 1) {
        if (N < m) continue;

        int k = (N - m) + (M - m);
        if (k < K) continue;

        ans += com.nHk(m, M - m) * com.aCb(N, m);
    }

    ans *= com.fac[N - 1];
    ans *= com.fac[M];
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
説明のため、N人の正直者を正直者1, 正直者2, ..., 正直者Nと呼ぶことにする。

円の数え上げの典型テクを使う
「1つを先頭として固定することで、列の数え上げにする」
先頭を正直者1と固定することにしよう。

今回の問題の条件を少しわかりやすく変えると、
「隣が同じなら正直者と返答する」つまり、「K個以上隣接が同じである組合せ」が答えになる。
ここで重要なのは、条件的には正直者や嘘つきの個々の区別は必要ないということ。
なので、先頭を正直者1として、他の正直者・嘘つきの『配置』の組合せを求める。
この答えに×(N-1)!×M!をすると、人を区別した、本当の答えになる。
よって、これ以降は、先頭を正直者として、残りの場所に正直者・嘘つきを条件を満たすように配置する組合せを考えることにする。

（ここまでがテクニックとして覚えておくべきなのだが、説明が分かりにくかったらごめん）

ここからも難しい。
先に正直者N個を置いておき、そこに嘘つきを挿入していくことを考える。
先頭には入れられないので、挿入先はN通りある。
ここで、嘘つきの集団をm個作ると考える。（←唐突ですが）
これをN通りの挿入先に入れていくことを考えると、同じところに集団を2ついれちゃうと、集団がマージされてm個にならないので、
N個からm個選んでいれることにする。
すると、白が隣接する箇所はN-m箇所になる。
しかも、嘘つきの集団をm個作ると考えると、黒が隣接する箇所はM-m箇所になる。
これは各集団の先頭m個を先に配置して、残りのM-mは配置するごとに黒の隣接箇所が1つ増えるためである。
何が言いたいかというと、嘘つきの集団の個数を固定すると、隣接が同じ箇所が分かるという嬉しさがある。

つらつら書いたが、解法に移る。
嘘つきの集団をm個として、mを[1,M]で全探索する。
mがN個より多くは作れないのと、隣接が同じ箇所は(N-m)+(M-m)となるので、これがK未満であるのもダメ。
すると、嘘つきの集団を入れる組み合わせはC(N,m)であり、嘘つきの集団の分け方はH(N,M-m)となる。
この積が嘘つきの集団がm個のときの組合せとなる。
これの総和を取って、×(N-1)!×M!をすると答え。
///////////////////////// writeup2 end */
