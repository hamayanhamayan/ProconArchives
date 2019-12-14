//https://yukicoder.me/problems/no/895
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

int a, b, c;
Comb<mint, 301010> com;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> a >> b >> c;

    mint ans = 0;
    mint z_tot = 1, z_cur = 1;
    rep(yi, 2, a + b + c)
    {
        int aa = a - (a + b + c - yi);
        int bb = b - 1;
        int cc = c;
        if (0 <= aa and 0 <= bb) {
            ans += com.fac[yi - 2] / (com.fac[aa] * com.fac[bb] * com.fac[cc - 1]) * z_tot;
        }
        z_cur *= 2;
        z_tot += z_cur;
    }
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
最後の条件がなかなか見慣れないので、考えてみよう。
これは、全てのビットかかぶらず、かつ、下位a+b+cビットに全部集まっていることを示している。
なので、a+b+c個ある1をx,y,zに割り振っていく問題と捉えていこう。

2番目の条件x > y > zは、それぞれの最上位ビットだけを見れば条件を満たすかがわかる。
この最上位ビットだけを考えてやれば、他の部分は適当に分配できそう？
いや、全探索と言っても、a+b+c番目の1は、xが取る必要がある。
yの最上位ビットを全探索してやれば、良さそうか？
良さそうだな。

yの最上位ビットがyi番目のとき、
[a+b+c,yi)番目のビットはすべてxのものになる。
(yi,1]番目の1は、xyzのどれに振ってもx>y>zの条件は満たすので大丈夫。
あとは、a,b,c個になるように計算する必要がある。
すでにxは(a+b+c)-yi個とっているし、yは1個とっているのでそれは減らそう。

(yi-1)個をa個b個c個の3グループに分ける。
zの総和に関係してくるのは、(yi-1)個からc個とってくる部分。
あるビットが1になっている組み合わせは、(yi-2)!/{a!b!(c-1)!}である。
これはどのビットについても組み合わせは変わらない。
よって、(1+2+4+8+...+2^(yi-1))*(yi-2)!/{a!b!(c-1)!}がyi固定としたときのzの取りうる値の総和になる。
///////////////////////// writeup2 end */
