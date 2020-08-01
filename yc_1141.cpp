//https://yukicoder.me/problems/no/1141
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
struct Ruisekiwa2D {
    int VH, VW;
    using T = int;
    vector<vector<T>> v;
    bool needBuild = false;
    Ruisekiwa2D() { }
    Ruisekiwa2D(int w, int h) { init(w, h); }
    void init(int w, int h) { 
        needBuild = true;
        VH = h; VW = w;
        v.clear();
        v.resize(h, vector<T>(w));
        rep(y, 0, VH) rep(x, 0, VW) v[y][x] = 0; }
    void set(int x, int y, T c) { v[y][x] = c; }
    void add(int x, int y, T c) { v[y][x] += c; }
    void build() {
        rep(y, 0, VH) rep(x, 0, VW) {
            if (0 < y) v[y][x] += v[y - 1][x];
            if (0 < x) v[y][x] += v[y][x - 1];
            if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
        }
        needBuild = false;
    }
    // [sx,sy]～[tx,ty]
    T get(int sx, int tx, int sy, int ty) {
        if (needBuild) assert(0 && "Need Build");
        if (tx < sx or ty < sy) return 0;
        T rs = v[ty][tx];
        if (0 < sx) rs -= v[ty][sx - 1];
        if (0 < sy) rs -= v[sy - 1][tx];
        if (0 < sx && 0 < sy) rs += v[sy - 1][sx - 1];
        return rs;
    }
    T getToDown(int x, int y, int len) {
        if (needBuild) assert(0 && "Need Build");
        if (VH - y < len) len = VH - y;
        return get(x, x, y, y + len - 1);
    }
    T getToUp(int x, int y, int len) {
        if (needBuild) assert(0 && "Need Build");
        if (y + 1 < len) len = y + 1;
        return get(x, x, y - len + 1, y);
    }
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int H, W, Q;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    rep(y, 0, H) rep(x, 0, W) cin >> A[y][x];

    Ruisekiwa2D r2d(W, H);
    rep(y, 0, H) rep(x, 0, W) if (A[y][x] == 0) {
        r2d.add(x, y, 1);
        A[y][x] = 1;
    }
    r2d.build();

    vector<mint> columns(W, 1);
    rep(x, 0, W) rep(y, 0, H) columns[x] *= A[y][x];
    vector<mint> rows(H, 1);
    rep(x, 0, W) rep(y, 0, H) rows[y] *= A[y][x];

    mint tot = 1;
    rep(y, 0, H) rep(x, 0, W) tot *= A[y][x];

    cin >> Q;
    rep(_, 0, Q) {
        int y, x; cin >> y >> x;
        y--; x--;

        int zero = 0;
        zero += r2d.get(0, x - 1, 0, y - 1); // LU
        zero += r2d.get(0, x - 1, y + 1, H - 1); // LD
        zero += r2d.get(x + 1, W - 1, 0, y - 1); // RU
        zero += r2d.get(x + 1, W - 1, y + 1, H - 1); // RD

        if (0 < zero) printf("0\n");
        else {
            mint ans = tot / columns[x] / rows[y] * A[y][x];
            printf("%d\n", ans.get());
        }
    }
}





/* ///////////////////////// writeup1 start
# 前提知識
- [2次元累積和](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
///////////////////////// writeup2 start
ちょっと難しい。
ある矩形についての操作を行う問題なので、累積和とかが使えないか考えてみる。

## 二次元累積和っぽく、いらない所を消す感じで考えてみる

今回の問題は全体から塗りつぶされたマスの数を取り除いて、積を取るような問題になっている。
積の逆は割り算なので、割り算でうまいことできないか？

答え = 全体の積 ÷ 縦の積 ÷ 横の積 × (r,c)の数

となる。二次元累積和が分かっている人なら、何となく分かるだろう。
後は、mod10^9+7は逆元があるので、全体の積、縦の積、横の積を前計算すれば、クエリに答えられる。

## A[r][c] = 0

これがコーナーケースとしてある。
0が含まれていると、逆元がうまく計算できない。
これをうまく扱う方法があり、0を1にしてしまえば問題ない。

しかし、これでは答えが0になるケースをカバーできない。
縦横を黒く塗ると、白い領域が最大4箇所できる。
この部分に0が含まれていれば、答えは0になるので、二次元累積和を使って、
A[r][c]=1であれば1、そうでないなら0で二次元累積和を作っておき、
白い領域の総和を取って1以上（0が存在する）なら0を答えとする。
///////////////////////// writeup2 end */
