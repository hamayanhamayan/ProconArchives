//https://www.hackerrank.com/contests/yfkpo3-1/challenges/median-permutation
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
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












int N;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;

    mint ans = 1;

    if (N % 2 == 1) N--;

    while (0 < N) {
        ans *= 2;
        ans *= N / 2;
        N -= 2;
    }

    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ɌcALeaderboardƁAŊFʂĂB
āAȒPȉ̂낤B
ȌȉTB

܂͏lĂ݂B
N=5lĂ݂ƁAŌ̗vf3ƂȂB
ȂƁAlɂȂȂB
_ _ _ _ 3@c 1,2,4,5

ŁAdvȐB
̐ǂ̂悤ɐzuĂ3lɂȂ邱Ƃ͕ςȂB
āA3͂lKv͂ȂB1,2,4,5Ƃ邪A1,2,3,4ƍlĂςȂB
܂AċAIɌvZłƂƁB
f(i) := 1`ȉŏ𖞂gݍ킹
ƒuƁAf(N)ɂȂ邪Ai̎lƁA
f(i) = f(i - 1) (i)

ł́Ai̎lĂ݂悤B
_ _ _ _ c 1,2,3,4
3Ԗڂɒû́A2,32B
܂AS2̂ǂꂩɂȂB
3Ԗڂ2uƂƁA4Ԗڂɒû́AƂ̔Α3,4ƂȂB
t3Ԗڂ3uƂƁA4Ԗڂɒû́AƂ̔Α1,2ƂȂB
ȂƁA1,2ԖڂuāA3ԖڂlɂȂȂƕ邾낤B
3,4ԖڂŊm肵āAm肷΁A1,2Ԗڂ̒uɂ炸3Ԗڂ͖̏̂ŁA
ċAIɌvZłB
f(i) = f(i - 2) * 2 * (N / 2)
Ƃ́AƓB

̎ł͍ċA֐g킸whileŌvZĂB
{Iɂ͓vZĂB
///////////////////////// writeup2 end */
