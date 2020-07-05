//https://atcoder.jp/contests/abc173/tasks/abc173_e
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














int N, K, A[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> A[i];
    sort(A, A + N, [&](int a, int b) { return abs(a) > abs(b); });

    int cnt = 0;
    mint ans = 1;

    rep(i, 0, K) {
        if (A[i] < 0) cnt++;
        ans *= mint(A[i]);
    }

    if (cnt % 2 == 1) {
        // 負→正
        int m1 = inf, p1 = inf;
        rep(i, 0, K) if (A[i] < 0) m1 = A[i];
        rep(i, K, N) if (0 <= A[i]) {
            p1 = A[i];
            break;
        }
        bool ok1 = (m1 != inf) && (p1 != inf);

        // 正→負
        int p2 = inf, m2 = inf;
        rep(i, 0, K) if (0 < A[i]) p2 = A[i];
        rep(i, K, N) if (A[i] <= 0) {
            m2 = A[i];
            break;
        }
        bool ok2 = (m2 != inf) && (p2 != inf);

        if (ok1 && ok2) {
            if (1LL * p1 * p2 > 1LL * m1 * m2) ans = ans * p1 / m1; // 負→正がいい
            else ans = ans * m2 / p2; // 正→負がいい
        }
        else if(ok1) ans = ans * p1 / m1;
        else if(ok2) ans = ans * m2 / p2;
        else {
            sort(A, A + N, greater<int>());
            ans = 1;
            rep(i, 0, K) ans *= A[i];
        }
    }

    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
貪欲法。コーナーケースが多く、実装も大変。

まず簡単な問題で考えてみる。
全て正の数であれば、数が大きいものから貪欲にK個とっていけばいい。
今回は負の数があるのが、問題。
負の数であっても、絶対値が大きいものから貪欲にK個とって、総積が正であれば、最善であるのは明らかである。
総積が負の場合、次のどちらかの操作を行って大きいものが最適な選び方となる。

1. 既に選択済みの負の数(m1)を取り除いて、選択されていない最大の正の数か0(p1)を入れる
2. 既に選択済みの正の数(p2)を取り除いて、選択されていない最小の負の数か0(m2)を入れる

このとき、どちらの方が結果が良くなるかは、abs(p1/m1)とabs(m2/p2)を比較すればいい。
絶対値が大きいほうが最適なので、方針1の方がいい条件は、
abs(p1/m1) > abs(m2/p2)
absは使えないので展開するのだが、どちらも正と負の割り算なので、全体は負となる。よって、absを展開すると、不等号は逆転して、
p1/m1 < m2/p2
整数で割ると誤差が出るので、×m1p2で分数を消す。これは負の数なので、不等号は逆転して、
p1*p2 > m1*m2
これを判断材料とする。

どちらの方針がやれるかどうかも判定して場合分けする。

ok1 := 方針1ができる
ok2 := 方針2ができる

なお、どちらの方針もできない場合は、配列Aが全て負の数の場合である（コーナーケース）。
その場合は、絶対値が大きいものからK個選ぶと、負の数として小さくなってしまうので、絶対値が小さいものからK個選ぶことにする。
///////////////////////// writeup2 end */
