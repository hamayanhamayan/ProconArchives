//https://yukicoder.me/problems/no/1085
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














string T; int D;
mint dp[101010][9];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> T >> D;

    bool canAllZero = true;
    fore(x, T) if (x != '?' && x != '0') canAllZero = false;

    if (D == 0) {
        if (canAllZero) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }

    int N = T.size();

    dp[0][0] = 1;
    rep(i, 0, N) rep(mo, 0, 9) {
        if (T[i] == '?') {
            rep(nxt, 0, 10) dp[i + 1][(mo + nxt) % 9] += dp[i][mo];
        }
        else {
            dp[i + 1][(mo + T[i] - '0') % 9] += dp[i][mo];
        }
    }

    D %= 9;
    if (D == 0 && canAllZero) dp[N][D] -= 1;
    cout << dp[N][D] << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- 数字根（知っていれば早い）
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
数字根を知らないとかなり時間をロスすると思う。
ある数について桁和を取れるだけとった結果を数字根という。
数字根は元の数のmod 9と等しくなることが知られている。
ただし、mod 9で0の場合は0以外なら9である。
この性質を計算でチェックサムとして用いる（検算方法として用いる）九去法というのもある。

ここまで分かっていれば、?をある数に変えたときの数 mod 9がDである組合せを求めればいいことが分かる。
今回は数字根なので、?をある数に変えて一回桁和を取ったときの数 mod 9がDである組合せを求めても同じであり、
こちらの方がやや簡単にDPがかける。
dp[i][mo] := i桁目まで確定していて、今までの桁和mod9がmoである組合せ
?だったら[0,9]で全通り試せばいいし、そうでないなら、それで確定。

コーナーケースが問題で、例えば、T=??????, D=9の場合。
D=9の時はmod9で0の組合せが最終的な答えとなるが、S=000000も数え上げられてしまう。
なので、全部0のSが作成可能で、D=9の時は答えが1つ減るので注意。

あとは、D=0となるのはSが全部0の時だけなので、
別途計算して答えてやろう。
///////////////////////// writeup2 end */
