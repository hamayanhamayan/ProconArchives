//https://yukicoder.me/problems/no/886
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
vector<int> makePrimes(int n) { // [2,n]
    vector<int> res, pr(n + 1, 1);
    pr[0] = pr[1] = 0;
    rep(p, 2, sqrt(n) + 2) if (pr[p]) for (int x = p * 2; x <= n; x += p) pr[x] = 0;
    rep(p, 2, n + 1) if (pr[p]) res.push_back(p);
    return res;
}
template<class T> vector<T> convolutionGcd(vector<T> a, vector<T> b) {
    int na = a.size();
    int nb = b.size();

    int n = max(na, nb);
    a.resize(n);
    b.resize(n);
    auto pr = makePrimes(n);

    fore(p, pr) {
        int m = (n - 1) / p;
        rrep(i, m, 1) {
            a[i] += a[i * p];
            b[i] += b[i * p];
        }
    }
    rep(i, 1, n) a[i] *= b[i];
    fore(p, pr) {
        int m = (n - 1) / p;
        rep(i, 1, m+1) a[i] -= a[i * p];
    }
    return a;
}
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int H, W;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> H >> W;

    vector<mint> h(H);
    rep(i, 1, H) h[i] = H - i;

    vector<mint> w(W);
    rep(i, 1, W) w[i] = W - i;

    auto v = convolutionGcd(h, w);
    mint ans = v[1] * 2 + mint(H) * (W - 1) + mint(W) * (H - 1);
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
