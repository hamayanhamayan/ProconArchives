//https://atcoder.jp/contests/abc154/tasks/abc154_f
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












Comb<mint, 2010101> com;
//---------------------------------------------------------------------------------------------------
mint dp[2010101];
mint g(int R, int C) {
    dp[0] = 1;
    int r1 = 0, c1 = 0;
    int r2 = 0, c2 = 0;
    rep(rc, 0, R + C) {
        dp[rc + 1] = dp[rc] * 2;

        if (r1 != R) r1++;
        else {
            dp[rc + 1] -= com.aCb(r1 + c1, r1);
            c1++;
        }

        if (c2 != C) c2++;
        else {
            dp[rc + 1] -= com.aCb(r2 + c2, r2);
            r2++;
        }
    }
    mint res = 0;
    rep(rc, 0, R + C + 1) res += dp[rc];
    return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

    mint ans = g(r2, c2) - g(r1 - 1, c2) - g(r2, c1 - 1) + g(r1 - 1, c1 - 1);
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [2次元累積和の考え方](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
- [mod素数上での二項係数](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
問われているのは、ある矩形区間での総和であるが、変数が4つもあるのは扱いにくい。
2次元累積和で使われている考え方を用いて、変数を2つに減らそう。
g(r,c) := 左下が(0,0)で、右上が(r,c)である矩形区間でのf(r,c)の総和
これを計算することができれば、`g(r2, c2) - g(r1 - 1, c2) - g(r2, c1 - 1) + g(r1 - 1, c1 - 1)`が答えとなる。
もし、これがあまりピンとこない場合は、2次元累積和について学ぶと良い。

これで変数が絞られたので、g(r,c)の計算方法を考えよう。
f(r,c)の計算方法を考えると、二項係数を使う方法が有名。
高校数学でもよく出てくる。[これ](https://xn--48s96ub7b0z5f.net/saitankeiro/)
しかし、競技プログラミング的にはDPで解く方法も良く使われる。
もし、二項係数で一発で計算できるのであれば、制約が10^6というのは小さい気がする。
DPでうまく計算するんだろうか。

DPにするとしたら、何を添字とするかとなるが、10^6なので1変数しか使えない。
ここからひらめくと、以下のようなDPができる。
dp[rc] := r+c=rcである(r,c)についてf(r,c)の総和
もしDPで行くとしたら、これしか作れない感があるのだが、実はこれが計算可能。
これの遷移を見てみると、序盤はdp[rc+1] = dp[rc] * 2となっていることに気がつく。
途中では片方の端の要素だけ2倍とならず、最後は両端の要素だけ2倍とならない。
つまり、遷移をしていくが、2倍とならない要素だけ、引くことで計算ができる。
2倍とならない要素は両端の最大2個なので、そこだけ二項係数を使って計算して引いてやればいい。

最後は2倍とならない要素の判定方法である。
rcをインクリメントしていくのは、傾き-1の直線が平行移動していくようなイメージ。
その時に矩形区間と交わる部分が端となる。
端に注目すると、↑→と移動する点1と、→↑と移動する点2が、速度1で同時に移動しているような感じになる。
点1が→に移動する時は、遷移先に1回しか足されてないので、引く。
点2が↑に移動する時は、遷移先に1回しか足されてないので、引く。
よって、それぞれの点の座標を覚えておいて、遷移しながら移動させることで、引く要素を判定するといい感じ。
///////////////////////// writeup2 end */
