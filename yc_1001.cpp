//https://yukicoder.me/problems/no/1001
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














int N;
vector<int> X[2];
mint dp[3010][3010];
int cnt0[3010], cnt1[3010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) {
		int t, x; cin >> t >> x;
		X[t].push_back(x - 1);
	}

    int n0 = X[0].size(), n1 = X[1].size();

    rep(i, 0, N) fore(x, X[0]) if (i <= x) cnt0[i]++;
    rep(i, 0, N) fore(x, X[1]) if (x <= i) cnt1[i]++;

    dp[0][0] = 1;
    rep(done0, 0, n0 + 1) rep(done1, 0, n1 + 1) {
        int nxt = done0 + done1;

        if (done0 < n0) dp[done0 + 1][done1] += dp[done0][done1] * (cnt0[nxt] - (n0 - (done0 + 1)));
        if (done1 < n1) dp[done0][done1 + 1] += dp[done0][done1] * (cnt1[nxt] - done1);
    }

    cout << dp[n0][n1] << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
難しい。
実装のため、数は全部0～N-1に直しておく。
考え方としては、挿入DPが近いかもしれない。
そっちを学んでから、以下解説を見るとわかりやすさが違うかも。

まず、条件がt=1だけだった場合を考えて、以下のようなDPを考えてみる。
dp[i] := 数i以前まで配置済みのときの順列の組み合わせ
このDPができる大切な要素として、単調性がある。
例えば条件として、全部t=1として{1,4,3,0,2}だったとする。
数0が置けるのは、4番目だけで、数1が置けるのは1番目と4番目。
数2が置けるのは、1,4,5番目…といったように数が大きくなると、置ける範囲が単調増加していく。
つまり、何が言いたいかというと、ある数iが置ける選択肢がk通りあったとして、1つを選んだ場合、
残りのk-1個はそのあとの数を自由に置くことができるということ。
なので、更新の選択肢は常に「置ける個数-既に置いた個数」となる。
よって、ある数iが置ける個数を以下のように前計算しておけば、簡単に計算可能。
cnt1[i] := 数iが置ける場所の個数
dp[i + 1] = dp[i] * (cnt[i + 1] - i)

だが、今回はt=0もある。
基本的な考え方は同じである。
dp[done0][done1] := 数を0から順番に配置して、t=0の部分をdone0個配置済み、t=1の部分をdone1個配置済みのときの組み合わせ
配列cnt1と同様に配列cnt0も作っておこう。
t=1に配置する操作は上と同じようにやればいい。

問題はt=0に配置する操作である（正直こっちあんまし分かってない。間違っていたらすみません）。
これはt=1と異なり、数を増やしていくと候補が単調減少していく。
こういう範囲が狭まっていくものの考え方として、それより後が構築可能な状態を保ちながら貪欲というテクがある。
これを応用するような感じで解いていく。
結論から言うと、更新の選択肢は(cnt0[nxt] - (n0 - (done0 + 1)))個となる。
cnt0[nxt]が次置く数が置ける場所の個数
n0がt=0の全体個数
done0が既に置いているt=0の個数
今置ける組み合わせはcnt0[nxt]通りであるが、全部使える訳じゃない。
置ける範囲はどんどん減っていくので、ここで置ける場所というのは後半のために一部残しておく必要がある。
残しておくべき個数は今置く予定のものを含めると、n0 - (done0 + 1)となる。
done0+1で今置く予定を含めた置いた個数。全体からそれを引くと、後々置くべき個数となる。
この分はあとで置けるようにとっておく必要がある。
なので、それを置ける場所cnt0[nxt]から引くと、置ける場所の組み合わせが求められる。
///////////////////////// writeup2 end */
