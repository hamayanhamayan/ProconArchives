//https://yukicoder.me/problems/no/997
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
typedef ModInt<1000000007> mint;

int mod = 1000000007;
int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
template<class... T> int add(int x, T... y) { return add(x, add(y...)); }
int mul(int x, int y) { return 1LL * x * y % mod; }
template<class... T> int mul(int x, T... y) { return mul(x, mul(y...)); }
int sub(int x, int y) { return add(x, mod - y); }
int modpow(int a, long long b) {
    int ret = 1; while (b > 0) {
        if (b & 1) ret = 1LL * ret * a % mod; a = 1LL * a * a % mod; b >>= 1;
    } return ret;
}
int modinv(int a) { return modpow(a, mod - 2); }
typedef vector<int> Vec;
typedef vector<Vec> Mat;
Vec mulMatVec(Mat a, Vec b)
{
    int n = b.size(); Vec ret(n, 0);
    rep(i, 0, n) rep(j, 0, n) ret[i] = add(ret[i], mul(a[i][j], b[j]));
    return ret;
}
Mat mulMatMat(Mat a, Mat b)
{
    int n = a.size(); Mat ret(n, Vec(n, 0));
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
    return ret;
}
Mat fastpow(Mat x, ll n)
{
    Mat ret(x.size(), Vec(x.size(), 0));
    rep(i, 0, x.size()) ret[i][i] = 1;
    while (0 < n) { if ((n % 2) == 0) { x = mulMatMat(x, x); n >>= 1; } else { ret = mulMatMat(ret, x); --n; } }
    return ret;
}
void printVec(Vec a) { cout << "[\t"; rep(i, 0, a.size()) cout << a[i] << "\t"; cout << "]" << endl; }
void printMat(Mat a) { rep(i, 0, a.size()) printVec(a[i]); }


// example: n=2
// x[0] = init[0], x[1] = init[1]
// x[i] = co[0] * x[i-1] + co[1] * x[i-2]
int solveLinearRecurrenceFormula(vector<int> init, vector<int> coefficient, ll idx) {
    int n = init.size();

    Vec v = init;
    Mat m(n, Vec(n, 0));
    rep(i, 0, n - 1) m[i][i + 1] = 1;
    rep(i, 0, n) m[n - 1][i] = coefficient[n - 1 - i];

    m = fastpow(m, idx);
    v = mulMatVec(m, v);

    return v[0];
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/











int N, W, A[101]; ll K;
mint dp[201];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> W >> K;
	rep(i, 0, N) cin >> A[i];

    dp[0] = 1;
    rep(cu, 0, W * 2) rep(i, 0, N) dp[cu + A[i]] += dp[cu];
    dp[2 * W] -= dp[W] * dp[W];

    int ans = solveLinearRecurrenceFormula({ dp[0].get(), dp[W].get() }, { dp[W].get(), dp[2 * W].get() }, K);
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [行列累乗](https://www.hamayanhamayan.com/entry/2017/03/20/234711)
///////////////////////// writeup2 start
Wの倍数で白石を踏んでいく必要がある。
例えば、白石を必ず踏んでいく必要がある場合は、白石間の組み合わせを計算して、K乗すれば答えが得られる。
これを発展させて考えると、ある白石が踏まれるのは、1つ前の白石が踏まれるか、2つ前の白石が踏まれる場合である。
以下のようなdpが思いつく。
dp[i] := i番目の白石を踏む組み合わせ
dp[i] = dp[i - 1] * （白石間の組み合わせ） + dp[i - 2] * （1つ白石を飛ばした時の白石間の組み合わせ）
この計算は行列累乗で高速化できるので、これで計算可能。

あとは、（白石間の組み合わせ）と（1つ白石を飛ばした時の白石間の組み合わせ）が分かればいい。
これもDPを使うことで計算可能。
dp[cu] := cu番目の石に到達するためのジャンプの組み合わせ
これは一般的な組み合わせDPで可能。
すると、
（白石間の組み合わせ） = dp[W]
（1つ白石を飛ばした時の白石間の組み合わせ） = dp[2*W]-dp[W]*dp[W]
となるので解決。
///////////////////////// writeup2 end */
