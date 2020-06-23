//https://atcoder.jp/contests/abc171/tasks/abc171_f
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














int K; string S;
Comb<mint, 2010101> com;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> K >> S;
    int N = S.length();

    mint ans = 0;
    rep(rest, 0, K + 1) {
        int injection = K - rest;
        ans += com.nHk(N, injection) * (mint(25) ^ injection) * (mint(26) ^ rest);
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [数え上げテク greedyからの帰着](https://www.hamayanhamayan.com/entry/2018/09/04/160039)
///////////////////////// writeup2 start
数え上げで最も気にするべきことは、重複して数えてしまわないかということである。
今回も問題は適当にやると容易に重複してしまいそうな感じがする。
これは例題をやったことが無いと厳しいと思う。
greedyからの帰着をする。
説明としてN=|S|としておこう。

## 条件から考える

今回作成するべき条件を満たす文字列は、以下条件を満たす必要がある。

- 長さがN+K
- 部分文字列としてSを含む

単純に考えるとこれを満たす文字列は、C(N+K, N) * 26^Kが答えになりそう。
だが、これをしてしまうと重複して数えてしまうので、嬉しくない。
さあ、どうしようか。

## greedyを使用して文字列を一意に絞り込む

こういう時は何かを固定することで、ある程度制約を付けることにする。
文字列Aと文字列Bが必ず違う文字列であることを保証できるような制約を考えてみる。
長さで差別化はできないから、部分文字列としてSを含むもので考えてみる。
ある文字列Aの部分文字列としてSを含むかを判定するにはgreedyに先頭から文字を探していけばいい。
すると、部分文字列としてSを含むならN個選ぶと最終的に先頭から何番目かで止まることになる。
このように先頭からgreedyにSを探索したときに、先頭から何個目までで止まるかが違えば、ある2つの文字列は必ず違うものになる。

なので、この特徴量で場合分けしよう。
解法では逆に、greedyで取ったときに最後に何文字あまるかでループを回している。
先頭からgreedyに文字列Sを取ったときに最後にrest文字余る組合せが得られれば良くなった。
restが違って同じ文字列になることはないので、全てについてこれを求めて総和を取ると答え。

## rest余るときの組合せ

これはrest余るということは、前からK+N-restに部分文字列としてSが含まれている。
かつ、丁度rest余るということは最後は必ずSの最後になっている必要がある。
S=abcであれば、?a?bcとか??abcとかab??cとかが考えられる。
?に入るのは、greedyに取っていたときに邪魔しないように25通りになる。
しかも、?をどこに入れても25^(?の個数)通りで変わらない。
?の個数はK+N-rest-N=K-restであるので、?を入れる場所はH(N, K - rest)通り。
それで、?を埋める組合せは25^(K - rest)通りで、余るrest分は何が入っていてもいいので、26^rest通り。
よって、H(N, K - rest*25^(K - rest)*26^restの総和を取ると答え。
///////////////////////// writeup2 end */
