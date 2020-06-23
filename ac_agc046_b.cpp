//https://atcoder.jp/contests/agc046/tasks/agc046_b
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int A, B, C, D;
mint dp[3030][3030];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B >> C >> D;

    dp[A][B] = 1;
    rep(h, A, C + 1) rep(w, B, D + 1) {
        if (A < h) dp[h][w] += dp[h - 1][w] * w;
        if (B < w) dp[h][w] += dp[h][w - 1] * h;
        if (A < h && B < w) dp[h][w] -= dp[h - 1][w - 1] * (w - 1) * (h - 1);
    }
    cout << dp[C][D] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
### まずはDPから考えてみる

とりあえずmod数え上げなので、DPから考えてみる。
制約からまず以下のDPをベースに考え始めてみる。
dp[h][w] := 盤面が縦hで横wであるときの塗られ方の組合せ
塗る操作をそのままDPの遷移に落とし込むと、
行追加で、dp[h - 1][w] * w -> dp[h][w]
列追加で、dp[h][w - 1] * h -> dp[h][w]
という遷移が出てくる。掛け算しているのは、塗る場所の組合せ。
だが、これでは、行追加→列追加と列追加→行追加としたときに、最終的な盤面が同じ場合が出てくる。
例えば、以下の場合である。

```
..X...
?????.
?????.
?????X
?????.
?????.
?????.
```

### 重複分を引く

`dp[h][w] = dp[h - 1][w] * w + dp[h][w - 1] * h`とすると、重複分がダブってカウントされてしまうので、
重複分を引くことにしよう。
ここから、簡単化して説明する。

以下のような重複盤面を見てみると、重複してしまうのは、右上が塗られておらず、
最上行の右上以外で1つ塗られていて（w-1通り)、
最右列の右上以外で1つ塗られている（h-1通り）盤面である。
それ以外の部分は、ある共通盤面から遷移しているので、dp[h-1][w-1]通り。

```
..X...
?????.
?????.
?????X
?????.
?????.
?????.
```

よって、dp[h-1][w-1] * (h-1) * (w-1)が共通部分になる。
これを引くようにする。
dp[h][w] = dp[h - 1][w] * w + dp[h][w - 1] * h - dp[h-1][w-1] * (h-1) * (w-1)
これで提出すると、サンプルが合うので、出すとAC。
サンプル3が合えば、どんなやつでも何となく合うんじゃないかな？
mod数え上げは、ちょっとでかめのやつが合えば、方針は合ってると思う。

### （あんま自信ない話題）厳密ではないのか？

先の説明はやや不十分である（本番だと、サンプル3が合ってるから、とりあえず投げると思うけど）。
先ほどの説明では追加遷移は、「行→列」か「列→行」しか考えていないが、「行→行」みたいな操作をすると、

```
..X...
?????X
?????.
?????X
?????.
?????.
?????.
```

みたいな端に複数黒が出てくる盤面も考えられる。
問題はこの盤面が他の遷移から現れるかという話であるが、「行→列」に操作を変えると
最右の列に黒は1つだけになるので、この状態にはならない。
つまり、重複しないので、問題ない。

更に追加補足（説明がややこしいので無視してもいい）
このようなパターンではなくて、行→行をやった結果、端に黒が2つ出てくる盤面になっているものも
あるかもしれないが、一手前のDPの段階でその辺はまとめられて数え上げられているので、
どの操作でその盤面になったかまでは、特に考える必要はない
なので、結果はどうあれ、重複操作は「行→列」か「列→行」と仮定して解いても問題ない。
///////////////////////// writeup2 end */
