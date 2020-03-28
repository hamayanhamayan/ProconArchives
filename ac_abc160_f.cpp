//https://atcoder.jp/contests/abc160/tasks/abc160_f
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
template<typename T, int FAC_MAX> struct Comb { vector<T> fac, ifac;
    Comb(){fac.resize(FAC_MAX,1);ifac.resize(FAC_MAX,1);rep(i,1,FAC_MAX)fac[i]=fac[i-1]*i;
        ifac[FAC_MAX-1]=T(1)/fac[FAC_MAX-1];rrep(i,FAC_MAX-2,1)ifac[i]=ifac[i+1]*T(i+1);}
    T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
    T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
    T nHk(int n, int k) { if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k); } // nHk = (n+k-1)Ck : n is separator
    T pairCombination(int n) {if(n%2==1)return T(0);return fac[n]*ifac[n/2]/(T(2)^(n/2));}
    // combination of paris for n
}; 
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














Comb<mint, 401010> com;
int N;
vector<int> E[201010];
//---------------------------------------------------------------------------------------------------
mint dp[201010];
int cnt[201010];
void dfs1(int cu, int pa = -1) {
    dp[cu] = 1;

    int cn = 0;
    fore(to, E[cu]) if (to != pa) {
        dfs1(to, cu);
        cn += cnt[to];
        dp[cu] *= dp[to] * com.ifac[cnt[to]];
    }

    dp[cu] *= com.fac[cn];
    cnt[cu] = cn + 1;
}
//---------------------------------------------------------------------------------------------------
mint ans[201010];
void dfs2(int cu, int pa = -1) {
    int cn = 0;
    ans[cu] = 1;
    fore(to, E[cu]) {
        cn += cnt[to];
        ans[cu] *= dp[to] * com.ifac[cnt[to]];
    }
    ans[cu] *= com.fac[cn];

    fore(to, E[cu]) if (to != pa) {
        cnt[cu] = cn - cnt[to] + 1;
        dp[cu] = ans[cu] * com.ifac[cn] / dp[to] * com.fac[cnt[to]] * com.fac[cn - cnt[to]];
        dfs2(to, cu);
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    dfs1(0);
    dfs2(0);

    rep(i, 0, N) printf("%d\n", ans[i].get());
}





/* ///////////////////////// writeup1 start
# 前提知識
- [全方位木DP](https://www.hamayanhamayan.com/entry/2017/02/09/155738)
///////////////////////// writeup2 start
全方位木DPが分かっていないと解けない。
この問題で全方位木DPを学ぶには少し問題がややこしい。
入門問題としては「Educational DP Contest / DP まとめコンテスト V Subtree」あたりがいいだろう。
これの解説を探して学んでもいいし、「全方位木DP」や「Rerooting」で検索して解説を読むのもいいだろう。

さて、まずは全方位木DPでありがちな、ある頂点を根とした時の木DPをまずは考えよう。
部分問題である。
dp[cu] := 頂点cuを根とした部分木にルールにしたがって1,2,3,...のように番号をつける組み合わせ
とりあえず、こう定義すればよさそう。
これを起点に考えると、更新式が見える。
頂点cuの直接の子供をto1, to2, ..., toMとして、頂点cuを根とした部分木の頂点数をcnt[cu]とすると、
dp[cu] = dp[to1] * dp[to2] * ... * dp[toM] * !(cnt[to1] + cnt[to2] + ... + cnt[toM]) / (!cnt[to1] * !cnt[to2] * ... * !cnt[toM])
こうなる。

例えば、ABC,abcという部分木の書き込み方をマージするときに、根は1なので、1ABCabcと書いてもいいし、
1AaBbCcとか1ABabcCみたいにしても大丈夫。つまり、部分木の書き込み方の順番は変えずにマージする感じ。
更新式の前半のdp[to1] * dp[to2] * ... * dp[toM]は各部分木での書き込み方で、
後半の!(cnt[to1] + cnt[to2] + ... + cnt[toM]) / (!cnt[to1] * !cnt[to2] * ... * !cnt[toM])でマージの場所の組み合わせを決めている。
後半部分は、これである。
[【高校数学A】同じものを含む順列 n!/p!q!r! | 受験の月](https://examist.jp/mathematics/baainokazu/onajimono-jyunretu/)

こうすることで木DP部分は出来上がったので、全方位木DPに変換していく。
この変換作業が難しいのだが、差分だけを計算するように頑張って計算する。
0割りしてしまいそうな気もするのだが、サボって逆元使って計算すると通る。
///////////////////////// writeup2 end */
