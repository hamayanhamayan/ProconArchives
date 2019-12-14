//https://yukicoder.me/problems/no/890
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
vector<int> enumdiv(int n) { 
    vector<int> S;
    for (int i = 1; 1LL*i*i <= n; i++) if (n%i == 0) { S.push_back(i); if (i*i != n) S.push_back(n / i); }
    sort(S.begin(), S.end());
    return S;
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

int N, K;
mint cnt[1010101];
Comb<mint, 2010101> com;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;
    auto ed = enumdiv(N);
    fore(minloop, ed) if (minloop < N and K % (N / minloop) == 0)
    {
        cnt[minloop] = com.aCb(minloop, K / (N / minloop));
        fore(x, ed) if (x < minloop and minloop % x == 0) cnt[minloop] -= cnt[x];
    }

    mint ans = 0;
    fore(minloop, ed) ans += cnt[minloop];
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
# 前提知識
- [10^9+7mod上での二項係数](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
- [約数系包除原理](https://www.hamayanhamayan.com/entry/2017/04/17/161345)
///////////////////////// writeup2 start
回転対称性について考える。
まず、beetさんが質問していたので見てみる。
```
回転対称性を持つとはある整数i(0<i<n)が存在して、任意の整数jに対して、
j(mod N)番目の点が選ばれているかとj+i(mod N)番目の点が選ばれているかが
同じであることです
```
なるほど。
つまり、回転したときに同じになる場合は最初以外のどこかであればいいことになる。

こういう回転して、同じになるというのは周期性を用いる問題が多い。
円で考えず、列として考えたときに、同じパターンが連続する、つまり、周期性を持てば、回転すれば同じパターンになる場合が存在する。
そして、最小周期で全探索して数え上げしていく問題はいくつも見たことがある。
例えば、N=8であれば、最小周期が1,2,4である場合を考えればいい。

今回は選べる点の数がK個となっているが、最小周期をminloopとすると、グループはN/minloop個できる。
よって、KがN/minloopで割り切れる必要がある。そうでないと周期を作れない。
あとは、各周期について、最小周期がminloopとなるような列を構成すればいい。
これは、C(minloop, K/(N / minloop))をすればいい。
繰り返されるパターンを作るものである。

だが、これだけでは不十分で、こうして作られたパターンは周期がminloopであることは保証されるが、
最小周期がminloopでない可能性がある。
minloopの約数の周期になっている場合がある。
よって、この場合を引こう。
これは、約数系包除原理というテクである。
minloopの小さい方から計算をしていき、cnt[x] := 最小周期がxである組み合わせ
これを使って、ダブっているパターンを引いていく。
///////////////////////// writeup2 end */
