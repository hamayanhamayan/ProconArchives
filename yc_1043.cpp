//https://yukicoder.me/problems/no/1043
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













#define DPMAX 101010
int N, M, V[101], R[101], A, B;
mint dp1[DPMAX], dp2[DPMAX];
//---------------------------------------------------------------------------------------------------
void dodp(int n, int* v, mint* dp) {
    dp[0] = 1;
    rep(i, 0, n) rrep(tot, DPMAX - 1, 0) if (0 <= tot - v[i]) dp[tot] += dp[tot - v[i]];
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> V[i];
	rep(i, 0, M) cin >> R[i];
	cin >> A >> B;

    dodp(N, V, dp1);
    rep(v, 1, DPMAX) dp1[v] += dp1[v - 1];

    dodp(M, R, dp2);

    mint ans = 0;
    rep(r, 1, DPMAX) {
        ll L = 1LL * A * r;
        ll R = 1LL * B * r;

        // [L, R]
        if (DPMAX <= L) continue;
        R = min(R, 1LL * DPMAX - 1);

        ans += dp1[R] * dp2[r];
        if (0 < L) ans -= dp1[L - 1] * dp2[r];
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
- [累積和](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
///////////////////////// writeup2 start
初手がなかなか難しいし、色々なテクを必要とするので、少し難しい問題。
逆に言うと理解すれば色々な技を得られるだろう。
制約を見るとそんなに大きくないし、10^9+7数え上げなんで、まずはDPかなぁ…で考える。
今回は当てが当たったというか、ぶっ飛んで考察進んだので、行間があんまない。

**DPフェーズ**

DPをする。
dp[i][tot] := i番目までの乾電池を使って合計電圧をtotにする選び方の組合せ
合計電圧の最大は10^5なので、状態数が10^2×10^5=10^7となる。
これは全部メモリを用意するには少し心配。
更新式は`dp[i+1][tot] = dp[i][tot] + dp[i][tot - V[i]]`であるが…

と、ここで1つ典型がある。
DPの空間削減テクというのがあって、今回のようにdp[i+1]がdp[i]のみから更新できるときに、
dp[i][tot]と定義しなくてもdp[tot]だけで済むという空間削減テクがある。
（このテクを知らない場合は、まずdp[i][tot]で実装するのがオススメ。それの変形で書ける）
[動的計画法における空間計算量削減テク - hogecoder](http://tsutaj.hatenablog.com/entry/2017/12/09/000000)
ここを見て学習しよう。一応以下にも簡単に概要は書いておく。

一般に空間が削減されると、処理が高速になるので、やれるときはやるといい。
さて、どうやってやるかというと、DPは以下のように定義する。
dp[tot] := 合計電圧をtotにする選び方の組合せ
i番目を順番に評価していくのは同じなのだが、totを降順に更新していく。
すると、dp[tot] += dp[tot - V[i]]と更新式を改めることができる。
これはdp[tot]を更新しようとしている場面では降順にtotを見ているので、dp[tot - V[i]]は実質dp[i][tot - V[i]]ということになる。
それをdp[i][tot]に加算しているので、元の更新式と一致するという寸法である。

このDPを乾電池でも豆電球でもしておく。
dp1[tot] := 合計電流がtotである乾電池の組合せ
dp2[tot] := 合計抵抗がtotである豆電球の組合せ

**累積和フェーズ**

なんで累積和が出てくるんだという感じだと思う。
条件としてA≦電流/抵抗≦Bを満たす必要があるが、変数が2つもあるとやりにくい。
抵抗を全探索することで解決しよう。
抵抗をrとして固定すると、条件はAr≦電流≦Brを満たす必要がある。
L=Ar, R=Brとすると、
抵抗がrのときに条件を満たす組み合わせはdp2[r] * (dp1[L] + dp1[L+1] +... + dp1[R-1] + dp1[R])となる。
このdp1の区間和は累積和で求めることができる。

dp1を累積和に変換しておこう。
dp1[tot] := 合計電流がtot以下である乾電池の組合せ
すると、条件を満たす組み合わせはdp2[r] * (dp1[R] - dp1[L - 1])となる。
あとは、[1,10^5]の範囲でrを動かして組合せを足し合わせると答えになる。
///////////////////////// writeup2 end */
