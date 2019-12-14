//https://atcoder.jp/contests/agc037/tasks/agc037_b
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
typedef ModInt<998244353> mint;
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













int N;
string S;
vector<int> Balls[3];
int flag[301010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;
	map<char, int> dic;
	dic['R'] = 0; dic['G'] = 1; dic['B'] = 2;
	rep(i, 0, N * 3) Balls[dic[S[i]]].push_back(i + 1);

	rep(i, 0, N) {
		int ma = max({ Balls[0][i], Balls[1][i], Balls[2][i] });
		int mi = min({ Balls[0][i], Balls[1][i], Balls[2][i] });
		flag[ma] = 1;
		flag[mi] = -1;
	}

	mint ans = 1;
	int r = 0, g = 0, b = 0;
	int rg = 0, rb = 0, gr = 0, gb = 0, br = 0, bg = 0;
	rep(i, 1, 3 * N + 1) {
		char c = S[i - 1];
		if (flag[i] < 0) {
			if (c == 'R') r++;
			if (c == 'B') b++;
			if (c == 'G') g++;
		}
		else if (flag[i] == 0) {
			if (c == 'R') {
				if (0 < g) ans *= g, g--, gr++;
				if (0 < b) ans *= b, b--, br++;
			}
			if (c == 'B') {
				if (0 < r) ans *= r, r--, rb++;
				if (0 < g) ans *= g, g--, gb++;
			}
			if (c == 'G') {
				if (0 < r) ans *= r, r--, rg++;
				if (0 < b) ans *= b, b--, bg++;
			}
		}
		else {
			if (c == 'R') {
				if (0 < gb) ans *= gb, gb--;
				if (0 < bg) ans *= bg, bg--;
			}
			if (c == 'B') {
				if (0 < rg) ans *= rg, rg--;
				if (0 < gr) ans *= gr, gr--;
			}
			if (c == 'G') {
				if (0 < rb) ans *= rb, rb--;
				if (0 < br) ans *= br, br--;
			}
		}
	}
	
	rep(i, 1, N + 1) ans *= i;

	cout << ans << endl;
}



















/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
この問題を本番で解くには、証明力か、性質を見出すセンスが問われる。

自然な流れとして、cj-ajの総和の最小値を考えてみよう。
これのためにlabo関数を作って、実験したり、いろいろ書いて考える。
重要な性質1「各色のボールを昇順ソートして、先頭から順番にとって配ると、最小化できる」
これがわかる。

もう一つ大切なことがある。
重要な性質2「性質1で各人で最小値として使われたボール、最大値として使われたボールが同じであるときが、cj-ajの総和が最小値であるとき」
この性質が数え上げの際にとても使える。

さて、具体的な解説であるが、まず、各色についてソートを行い、「最大値」「最小値」「真ん中」を判定する。
「最小値＜真ん中＜最大値」の組をこれで作っていく。
あとは、色をどうやって対処していくかという問題があるが、貪欲にくっつけていけばいい。
構成の過程で2択で迷うことはない。
///////////////////////// writeup2 end */
