//https://atcoder.jp/contests/agc046/tasks/agc046_c
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
vector<string> split(string str, string delim) { // strをdelimそれぞれで分割
	vector<string> items;
	size_t dlm_idx;
	if (str.npos == (dlm_idx = str.find_first_of(delim))) {
		items.push_back(str.substr(0, dlm_idx));
	}
	while (str.npos != (dlm_idx = str.find_first_of(delim))) {
		if (str.npos == str.find_first_not_of(delim)) {
			break;
		}
		items.push_back(str.substr(0, dlm_idx));
		dlm_idx++;
		str = str.erase(0, dlm_idx);
		if (str.npos == str.find_first_of(delim) && "" != str) {
			items.push_back(str);
			break;
		}
	}
	return items;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














string S; int K;
int N;
int A[303];
mint dp[603][603];
mint imos1[603][603], imos2[603][603];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> S >> K;
    N = S.length();
    chmin(K, N);

    auto v = split(S, "0");
    int M = v.size();
    rep(i, 0, M) A[i] = v[i].length();
    
    dp[0][0] = 1;
    rep(i, 0, M) {
        rep(need, 0, N) rep(k, 0, K + 1) imos1[need][k] = 0;
        rep(need, 0, N) rep(k, 0, K + 1) imos2[need][k] = 0;

        rep(need, 0, N) rep(k, 0, K + 1) {
            int L = min(need, A[i]);
            int R = 0;

            imos1[need - L][k + L] += dp[need][k];
            if(k) imos1[need + 1][k - 1] -= dp[need][k];

            imos2[need + 1][k] += dp[need][k];
        }

        rep(need, 1, N) rrep(k, K - 1, 0) imos1[need][k] += imos1[need - 1][k + 1];
        rep(need, 1, N) rep(k, 0, K + 1) imos2[need][k] += imos2[need - 1][k];
        rep(need, 0, N) rep(k, 0, K + 1) dp[need][k] = imos1[need][k] + imos2[need][k];
    }

    mint ans = 0;
    rep(k, 0, K + 1) ans += dp[0][k];
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
### DPだろうけど…

mod数え上げなので、DPかなと感じではあるが、うまく条件をまとめ上げる必要があるので、
まとめ上げるための性質を探す。
操作はK回以下と緩い制約となっており、1はそれより前に移動させるしかないため、
「とある1は一回しか操作されない」と仮定して問題なさそうだ。
1を動かす操作を考えてみると、重複があることが分かる。
重複を数えないようにどうすればいいかを考えてみると、今回の文字列Sは以下の数列に言い換えた方がよさそう。
A[i] := 0で区切ったときのi番目のグループに含まれる1の個数
例えば、`110101110`であれば`A = {2,1,3,0}`である。
こうすると、各要素から数字をより前の要素に移すという問題に言い換えることができる。
見通しがいい感じになってきたので、DPに落とそう。

### どのようにDPを組むか

誤回答であるが、以下のようにDPを組むのは不十分。

dp[i][k] := 配列Aのi番目まで処理済みで、操作回数がk回であるときの組合せ

このようなDPだと、dp[i][k]からの遷移を考えるときに、それ以前の部分に1を分配するような形になるが、
これは重複して数え上げる可能性がある。
重要なのは、処理済みの部分は確定させてしまうこと。
よって、以下のようなDPを組む。

dp[i][need][k] := 配列Aのi番目まで操作で確定していて、操作回数がk回で、need個1を前に移動させる必要があるときの組合せ
i番目までは値を確定させるようにして、必要な個数を添え字に追加する。
dp[i][need][k]では何個後ろからもらうかの遷移を書けば、全体O(N^4)
これでも通るらしいので、復習ならまずはこれで出してみる（TLEするなら、ここまでは合ってるんじゃないかな？）
配列はメモリ節約するとより早くすることができるし、modを取る回数を減らしたりすると通るんじゃないかな？

感覚的には[greedyからの帰着](https://www.hamayanhamayan.com/entry/2018/09/04/160039)が似ているかもしれない。

### 高速化

imos法を使って高速化を行う。
更新式を見ると、区間和をしているような感じになっている。
うまくimos法を使うことで、O(N^3)まで計算量を落とすこともできる。
///////////////////////// writeup2 end */
