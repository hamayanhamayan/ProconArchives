//https://codeforces.com/contest/1246/problem/C
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
template<int VW, int VH> struct Ruisekiwa2D {
    using T = int;
    T v[VH][VW];
    Ruisekiwa2D() { rep(y, 0, VH) rep(x, 0, VW) v[y][x] = 0; }
    void set(int x, int y, T c) { v[y][x] = c; }
    void add(int x, int y, T c) { v[y][x] += c; }
    void build() {
        rep(y, 0, VH) rep(x, 0, VW) {
            if (0 < y) v[y][x] += v[y - 1][x];
            if (0 < x) v[y][x] += v[y][x - 1];
            if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
        }
    }
	// [sx,sy]～[tx,ty]
    T get(int sx, int tx, int sy, int ty) {
        if (tx < sx or ty < sy) return 0;
        T rs = v[ty][tx];
        if (0 < sx) rs -= v[ty][sx - 1];
        if (0 < sy) rs -= v[sy - 1][tx];
        if (0 < sx && 0 < sy) rs += v[sy - 1][sx - 1];
        return rs;
    }
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













const int MAXSIZE = 2010;
#define DOWN 0
#define RIGHT 1
int H, W;
string B[MAXSIZE];
mint dp[MAXSIZE][MAXSIZE][2];
mint rui[MAXSIZE][MAXSIZE][2];
Ruisekiwa2D<MAXSIZE, MAXSIZE> blank, rock;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) cin >> B[y];

	if (H == 1 and W == 1) {
		cout << 1 << endl;
		return;
	}

	rep(y, 0, H) rep(x, 0, W) {
		if (B[y][x] == '.') blank.add(x, y, 1);
		else rock.add(x, y, 1);
	}
	blank.build();
	rock.build();

	dp[0][0][DOWN] = dp[0][0][RIGHT] = 1;
	rep(y, 0, H) rep(x, 0, W) {
		// for RIGHT
		int num_blank = blank.get(x, x, y + 1, H + 1);
		int ng = -1, ok = y + 1;
		while (ng + 1 != ok) {
			int md = (ng + ok) / 2;
			if (rock.get(x, x, md, y) <= num_blank) ok = md;
			else ng = md;
		}
		//rep(yy, max(0, ng), y) dp[y][x][RIGHT] += dp[yy][x][DOWN];
		if (max(0, ng) < y) {
			mint d = 0;
			if (0 <= y - 1) d = rui[y - 1][x][DOWN];
			if (0 <= max(0, ng) - 1) d -= rui[max(0, ng) - 1][x][DOWN];
			dp[y][x][RIGHT] = d;
		}

		// for DOWN
		num_blank = blank.get(x + 1, W + 1, y, y);
		ng = -1, ok = x + 1;
		while (ng + 1 != ok) {
			int md = (ng + ok) / 2;
			if (rock.get(md, x, y, y) <= num_blank) ok = md;
			else ng = md;
		}
		//rep(xx, max(0,ng), x) dp[y][x][DOWN] += dp[y][xx][RIGHT];
		if (max(0, ng) < x) {
			mint d = 0;
			if (0 <= x - 1) d = rui[y][x - 1][RIGHT];
			if (0 <= max(0, ng) - 1) d -= rui[y][max(0, ng) - 1][RIGHT];
			dp[y][x][DOWN] = d;
		}

		rui[y][x][DOWN] = dp[y][x][DOWN];
		if(0 <= y - 1) rui[y][x][DOWN] += rui[y - 1][x][DOWN];
		rui[y][x][RIGHT] = dp[y][x][RIGHT];
		if(0 <= x - 1) rui[y][x][RIGHT] += rui[y][x - 1][RIGHT];
	}
	cout << dp[H - 1][W - 1][DOWN] + dp[H - 1][W - 1][RIGHT] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
