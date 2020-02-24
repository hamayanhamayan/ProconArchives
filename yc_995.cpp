//https://yukicoder.me/problems/no/995
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M; ll K; int p, q, B[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K >> p >> q;
	rep(i, 0, N) cin >> B[i];

    mint pon = mint(p) / mint(q);
    mint poff = mint(1) - pon;

    Mat m(2, Vec(2, 0));
    rep(i, 0, 2) rep(j, 0, 2) {
        if (i == j) m[i][j] = poff.get();
        else m[i][j] = pon.get();
    }
    m = fastpow(m, K);

    mint on, off;

    {
        Vec v(2);
        v[0] = 1;
        v = mulMatVec(m, v);
        on = v[0];
    }

    {
        Vec v(2);
        v[1] = 1;
        v = mulMatVec(m, v);
        off = v[0];
    }

    mint ans = 0;
    rep(i, 0, N) {
        if (i < M) ans += mint(B[i]) * on;
        else ans += mint(B[i]) * off;
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [行列累乗](https://www.hamayanhamayan.com/entry/2017/03/20/234711)
///////////////////////// writeup2 start
各タピオカ同士は、互いに影響を及ぼさないので、独立に計算ができる。
各タピオカについて美しさの期待値を求め、その総和をとることで、答えを導こう。

期待値は、美味しさ×タピオカが入る確率で計算ができるので、タピオカが入る確率を求めよう。
もともとタピオカがミルクティーに入っている状態のとき、移動の回数が全体で偶数回数になれば、
入っている状態になる。
これをDPで求めることを考えよう。
dp[i][p] := i回パワーを使ったときの移動回数%2=pであるときの確率
普通に計算すると、iがKなので、TLE
だが、今回は1つ前の値にのみ更新が依存するので、行列累乗が行える。
これで確率が求まったら、あとは期待値を求めていけばいい。
///////////////////////// writeup2 end */
