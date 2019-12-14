//https://atcoder.jp/contests/otemae2019/tasks/otemae2019_d
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













int N, M; string S[1010];
bool ok[1010][15];
mint dp[2][1010][15];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, M) cin >> S[i];

	rep(i, 0, M) {
		if (S[i] == "Fizz") ok[i][3] = ok[i][6] = ok[i][9] = ok[i][12] = true;
		else if (S[i] == "Buzz") ok[i][5] = ok[i][10] = true;
		else if (S[i] == "FizzBuzz") ok[i][0] = true;
	}
	rep(mo, 0, 15) if (mo % 3 != 0 and mo % 5 != 0) ok[M][mo] = true;

	dp[0][0][0] = 1;
	rep(_idx, 0, N) {
		int idx = _idx % 2;
		int idx2 = 1 - idx;

		rep(spoken, 0, M + 1) rep(mo, 0, 15) dp[idx2][spoken][mo] = 0;

		rep(spoken, 0, M + 1) {
			rep(mo, 0, 15) rep(nxt, 0, 10) {
				if (_idx == 0 and nxt == 0) continue;

				int mo2 = (mo * 10 + nxt) % 15;

				if (spoken == M) {
					if (ok[M][mo2]) dp[idx2][spoken][mo2] += dp[idx][spoken][mo];
				}
				else {
					if (ok[M][mo2]) dp[idx2][spoken][mo2] += dp[idx][spoken][mo];
					if (ok[spoken][mo2]) dp[idx2][spoken + 1][mo2] += dp[idx][spoken][mo];
				}
			}
		}
	}

	mint ans = 0;
	rep(mo, 0, 15) ans += dp[N % 2][M][mo];
	cout << ans << endl;
}






/* ///////////////////////// writeup1 start
# 前提知識
- [桁DP](https://www.hamayanhamayan.com/entry/2017/04/23/212728)
///////////////////////// writeup2 start
まずmod10^9+7なので、とりあえずDPを疑おう。
今回は桁数が大きく、かつ、上から決めていくので、桁DPを疑おう。
倍数によって処理を変えているようなので、modをindexとして使えばよさそう。
いつもの桁DPが思い浮かぶので、やってみるとできそう。
dp[idx][mo] := idx桁目まで確定していて、%15するとmoとなる数の組み合わせ
15の剰余を見れば、状況がまとめられそうなので、indexに入れる。
idx単位でDP更新後、条件を満たさないものは0にするようにして更新していく。

あとは、いつ発言したかであるが、これも何回発言済みかというのをindexに入れれば問題ない。
dp[idx][spoken][mo] := idx桁目まで確定していて、spoken回発言済みで、%15するとmoとなる数の組み合わせ
先頭が0は許されないので、注意。
あと、配列テーブルが大きいので、一応idxはmod2で使いまわすようにして節約した。
あと、文字列そのままで判定するとTLEするので、大丈夫な値を前計算しておこう。
///////////////////////// writeup2 end */
	