//https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_c
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














int N; string S;
int A[201010];
#define open 1
#define close 2
//---------------------------------------------------------------------------------------------------
bool check(char c, int cnt) {
    if (cnt % 2 == 0 and c == 'W') return true;
    if (cnt % 2 == 1 and c == 'B') return true;
    return false;
}
//---------------------------------------------------------------------------------------------------
mint solve() {
    N *= 2;

    if(S[0] == 'W') return 0;

    A[0] = open;

    int cnt = 1;
    rep(i, 1, N) {
        if(check(S[i], cnt)) A[i] = close, cnt--;
        else A[i] = open, cnt++;

        if(cnt < 0) return 0;
    }

    if(cnt != 0) return 0;

    mint ans = 1;
    cnt = 0;
    rep(i, 0, N) {
        if (A[i] == open) cnt++;
        else {
            ans *= cnt;
            cnt--;
        }
    }

    N /= 2;
    rep(i, 1, N + 1) ans *= i;

    return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> S;
    cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
何から手を付けていいかわからないかもしれない。
こういうときは、色々試していくしかないが、全探索対象を探してみる。
2Nマスに対して、N回操作を端点として選択するマスがかぶらないように操作をするということは、
各マスについて「先頭」か「末尾」をN個ずつ割り当てることになる。
この時、先頭を「(」、末尾を「)」とした時に正しいカッコ列である必要がある。

dp[i][open] := i番目まで全て白になっていて、ここまでカッコがopen個開いている組み合わせ
このdpでは解けないが、これによって、だいぶ解法に近づく。
遷移する時にちゃんとi+1番目が白になっていることを確認しながら、遷移を行う。
これをよくよく考えてみると、整合性を確認しながら、カッコを開くか閉じるか決めていくので、
各要素についてカッコが開くか閉じるかというのは一意に定まる。
よって、カッコを決める必要はなくなる。

ここまで来れば比較的簡単。
後問題になるのは、先頭と末尾が決まっているマスについて、N通りの組を作る組み合わせになる。
末尾の方を先頭から順番に見ていって、(そこまでに出ている先頭)-(そこまでに出ている末尾)の総積が組み合わせとなる。
最後にN!を書けると操作の組み合わせとなる。
///////////////////////// writeup2 end */
