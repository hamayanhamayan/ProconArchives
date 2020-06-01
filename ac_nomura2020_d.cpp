//https://atcoder.jp/contests/nomura2020/tasks/nomura2020_d
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
struct UnionFind {
	using T = int;
	const T def = 0;
	T f(T a, T b) { return a + b; }
	//==========================================
	vector<int> par;
	vector<T> value;
	UnionFind() {}
	UnionFind(int NV) { init(NV); }
	void init(int NV) { par.clear(); rep(i, 0, NV) par.push_back(i); value.resize(NV, 1); }
	void reset() { rep(i, 0, par.size()) par[i] = i; }
	int operator[](int x) {
		if (par[x] == x) return x;
		else {
			int res = operator[](par[x]);
			if (res != par[x]) {
				value[res] = f(value[res], value[par[x]]);
				value[par[x]] = def;
			}
			return par[x] = res;
		}
	}
	// uf(x,y)->y
	void operator()(int x, int y) {
		x = operator[](x); y = operator[](y);
		if (x != y) {
			value[y] += value[par[x]];
			value[par[x]] = def;
			par[x] = y;
		}
	}
	T getValues(int x) { return value[operator[](x)]; };
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, P[5010], K;
vector<int> gr;
//---------------------------------------------------------------------------------------------------
int cycle_num = 0;
bool pending[5010];
void unite() {
	UnionFind uf(N);
	int K = 0;
	rep(i, 0, N) {
		if (0 <= P[i]) {
			int x = i;
			int y = P[i];
			if (uf[x] != uf[y]) {
				uf(x, y);
			}
			else cycle_num++;
		}
		else K++;
	}

	rep(i, 0, N) if (P[i] < 0) pending[uf[i]] = true;
	rep(i, 0, N) if (i == uf[i] && pending[i]) gr.push_back(uf.getValues(i));
}
//---------------------------------------------------------------------------------------------------
Comb<mint, 10101> com;
mint dp[5010][5010];
bool vis[5010][5010];
mint calc() {
	dp[0][0] = 1;

	rep(i, 0, K) rep(len, 0, K) {
		dp[i + 1][len] += dp[i][len];
		dp[i + 1][len + 1] += dp[i][len] * gr[i];
	}

	mint res = 0;

	// cycle 1
	rep(i, 0, K) res += mint(gr[i] - 1) * (mint(N - 1) ^ (K - 1));

	// cycle greater than 1
	rep(len, 2, K + 1) res += dp[K][len] * com.fac[len - 1] * (mint(N - 1) ^ (K - len));

	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) {
		cin >> P[i], P[i]--;
		if (P[i] < 0) K++;
	}

	unite();

	mint ans = mint(N - cycle_num) * (mint(N - 1) ^ K);
	ans -= calc();

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- （[Functional Graph](https://www.hamayanhamayan.com/entry/2017/06/07/234608)）
///////////////////////// writeup2 start
とりあえず[解説動画](https://www.youtube.com/watch?v=NuhtAfH5SCc)を見よう。
なるほどなぁ。難しい。
まあ、ちょっと序盤のお気持ちはわからんのだけど、解説動画で解法としては理解したので同じことをもう一度説明する。

まず、Pi=-1が1つも無い状況を考えてみる。
この時は全ての要請先が分かっているが、この時に必要な道の最小値は、N-要請先を無向辺としたときの連結成分数となる。
Pi=-1があって、要請先を決めていくことを考えると、連結成分数を使うのは実はちょっと不便。
これは要請先を確定させても連結成分数が変わらない場合があるためである。
では、どうするのがいいだろうか。
今回の問題の特徴である、ある町からの遷移先は1つという部分である。
このグラフはFunctional Graphと言い、連結成分数＝サイクル数となっている。
よって、道の最小値はN-サイクル数と言い換えることができる。
サイクルが1つできたら、その先、どうなってもサイクルはできない。それがFunctional Graph。
これで、問題は(N-1)^K通りの要請方法について、サイクル数の総和を求められれば答えが得られる。

この方針を持ってくるのがちょっとあれだが、まだ実験してれば行けなくもない。
次が問題。

方針としては、主客転倒をする。
（あまりいいなじみの無いテクだから、テク名は気にしなくていい）
「(N-1)^K通りの要請方法について、サイクル数の総和を求める」という問題を
「全通りのサイクルについて、そのサイクルが出てくる要請方法の組合せを求めて総和を取る」という問題に言い換える。
この2つの問題の結果が等しくなることを理解するのが2つ目のステップ。
これは慣れないと難しい。
このような方針を主客転倒と言い、慣れるまで非自明だが、慣れると自明。

等しいことが理解できたとする。
全通りのサイクルを考えるには、まず要請先が決まっている頂点についてはあらかじめまとめて考える。
すると、遷移先の末尾は全て遷移先が決まっていない頂点となる連結成分が出てくる。
実際この連結成分は構成される頂点数だけが重要であるので、union findを使ってまとめておこう。
まとめた結果、連結成分ごとに(頂点数,要請先が決まってない頂点があるか)のデータに帰着できる。
自分の実装ではこれをunion関数内部でやっている。
結果が、gr配列に入ってる。

この状態でサイクルを考えてみる。
ある連結成分のサイクル、1->2->3->1というサイクルを考えてみよう。
加えて、i番目の連結成分の個数をcount(i)としておく。
全体の連結成分数がN個あるとすると、このサイクル以外の遷移についてはこのサイクルに影響を及ぼさないので、
どのようにつながっていてもいい。
よって、このサイクルの部分以外を作る要請方法は、(N-1)^(K-3)通りとなる。
サイクル部分を作る要請方法は、1->2でcount(2)の組合せがあるので、1->2->3->1をとなるサイクルの組合せは、
count(1)*count(2)*count(3)となる。
なのでこのサイクルが作られる要請方法は(N-1)^(K-3)*count(1)*count(2)*count(3)となる。
ここから範囲を広げていこう。
123の順番以外の132とかも考えるには(3-1)!通りあるので、順番を意識しないなら、
(3-1)!*(N-1)^(K-3)*count(1)*count(2)*count(3)通りとなる。
よくよく見てみると、count以外の部分はサイクルの個数だけで計算ができることが分かる。
なので、サイクルの長さ3のものは全部(3-1)!*(N-1)^(K-3)*count(1番目)*count(2番目)*count(3番目)とできる。
この全部そうであるという部分が重要で、抽象化できるということだ。

さて、以下のDPを考えよう。
dp[i][len] := i番目の連結成分まで考えたときに、len個のcountを掛け合わせた値の総和
これはDPで計算可能である。
すると、サイクルの長さ3のサイクルの要請方法は(3-1)!*(N-1)^(K-3)*dp[K][3]で一気に計算できる。
よって、len=2..Nについて(len-1)!*(N-1)^(K-len)*dp[K][len]の総和を取ると答え…
っぽいが、len=1の時は計算が少し違うので、注意。
len=1の時は、自分の連結成分の自分以外を指せば、サイクル1になるので、それを全部計算して足し合わせる。
このDP計算とまとめる計算をcalc関数でやってる。

あとは、N-サイクル数なので、Nを(N-1)^K倍したものから、calcの結果を引いてやれば答え。
///////////////////////// writeup2 end */
