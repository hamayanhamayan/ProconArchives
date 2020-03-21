//https://www.hackerrank.com/contests/75th/challenges/many-powers
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
int mod = 1000000007;
int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
template<class... T> int add(int x, T... y) { return add(x, add(y...)); }
int mul(int x, int y) { return 1LL * x * y % mod; }
template<class... T> int mul(int x, T... y) { return mul(x, mul(y...)); }
int sub(int x, int y) { return add(x, mod - y); }
int modpow(int a, long long b) {
    int ret = 1; while (b > 0) {
        if (b & 1) ret = 1LL * ret * a % mod; a = 1LL * a * a % mod; b >>= 1;
    } return ret;
}
int modinv(int a) { return modpow(a, mod - 2); }
/*---------------------------------------------------------------------------------------------------
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












ll A, B, C;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B >> C;

    mod = C;

    int ans = 0;
    rep(i, 0, C) {
        ll cnt = A / C;
        if (0 < i && i <= A % C) cnt++;
        ans = add(ans, mul(cnt % C, modpow(i, B)));
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
今回の問題の弱点はCが小さいことである。

例えば、(1^3 + 2^3 + 3^3 + 4^3 + 5^3 + 6^3 + 7^3) % 3を計算しようと考えたときに、
mod 3上では、4^3 = 1^3となるので、全部0^3～2^3に変換できる。
よって、(2 * 0^3 + 3 * 1^3 + 2 * 2^3) % 3を計算できればいいことになる。

解法としては、0～C-1を全探索する。
i^Bとなる個数を計算したいが、倍数の個数を計算しているようなものなので、単純な割り算で計算可能。
あとは、個数×i^Bの総和をmod Cでやれば答え。
///////////////////////// writeup2 end */
//　