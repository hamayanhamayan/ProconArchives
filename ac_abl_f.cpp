//https://atcoder.jp/contests/abl/tasks/abl_f
#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; using namespace atcoder;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt& operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt& operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r;
}
template<typename T, int FAC_MAX> struct Comb {
    vector<T> fac, ifac;
    Comb() {
        fac.resize(FAC_MAX, 1); ifac.resize(FAC_MAX, 1); rep(i, 1, FAC_MAX)fac[i] = fac[i - 1] * i;
        ifac[FAC_MAX - 1] = T(1) / fac[FAC_MAX - 1]; rrep(i, FAC_MAX - 2, 1)ifac[i] = ifac[i + 1] * T(i + 1);
    }
    T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
    T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
    // nHk = (n+k-1)Ck : n is separator (k balls to n boxs)
    T nHk(int n, int k) {
        if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k);
    }
    T pairCombination(int n) { if (n % 2 == 1)return T(0); return fac[n] * ifac[n / 2] / (T(2) ^ (n / 2)); }
    // combination of paris for n
};
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














int N, cnt[101010];
Comb<mint, 201010> com;
//---------------------------------------------------------------------------------------------------
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
vector<int> allConvolution(vector<vector<int>> vs) {
    min_priority_queue<pair<int, int>> que;
    int n = vs.size();

    rep(i, 0, n) que.push({ vs[i].size(), i });
    while (2 <= que.size()) {
        int i1 = que.top().second; que.pop();
        int i2 = que.top().second; que.pop();
        vs[i1] = convolution(vs[i1], vs[i2]);
        que.push({ vs[i1].size(), i1 });
    }

    return vs[que.top().second];
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
    rep(i, 0, N * 2) {
        int h; cin >> h;
        cnt[h]++;
    }

    vector<vector<int>> vs;
    rep(h, 1, 101010) {
        vector<int> cmb;
        rep(pr, 0, cnt[h] / 2 + 1) cmb.push_back((com.aCb(cnt[h], pr*2) * com.pairCombination(pr * 2)).get());
        vs.push_back(cmb);
    }
    sort(all(vs));

    vs.push_back({ 1 });
    auto dp = allConvolution(vs);

    mint ans = 0;
    int n = dp.size();
    rep(i, 0, n) {
        mint cmb = mint(dp[i]) * com.pairCombination(N * 2 - i * 2);
        if (i % 2 == 0) ans += cmb;
        else ans -= cmb;
    }

    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [包除原理](https://www.hamayanhamayan.com/entry/2017/04/17/161345)
- [NTT](https://www.hamayanhamayan.com/entry/2017/05/20/125607)
///////////////////////// writeup2 start
この問題は複合的な知識が要求される。
順番に理解をしていこう。

# 包除原理？

パッと見て包除原理感がある。
なんでやという感じではあるが、感がある主張派の気持ちも分かる。
「ペアになっているとダメ」という部分がだいぶ包除原理っぽく見える。
包除原理をするためにはという観点で考えると、以下のようなDPが必要になる。

dp[x][pr] := h[i]=xである人まで評価が終わっていて、同じ値を持つ人のペアがpr組あるときの場合の数（ペアになっていない人の組み合わせは考慮しない）
これを愚直に計算することを考えてみる。

h[i]=xである人がcnt[x]人いるとする。
この時に作れるペアは0ペア、1ペア、…、cnt[x]/2ペアである。
ここで同じ値を持つ人のペアをyペア作成する組み合わせは、以下の積である。

- C(cnt[x], y*2) : どの人をペア作成として使用するか
- y*2人を2人yグループに分ける組み合わせ : 使用する人でどのようにペアを作るか

上は簡単であるが、下の計算がムズイ。
自分はライブラリ化しているが、中身的には(y*2)!/y!/(2^y)である。
(y*2)!!と書くとこれになるっぽい（要出典）

この更新式を使うと、O(N^2)のDPが出来上がる。
高速化の必要があるが、これが高速に計算できたとすると、あとは包除定理を適用するだけ。

(-1)^pr * dp[100000][pr] * (N*2-pr*2)!!の総和

# O(N^2)のDPの高速化のために

DPの更新式を整理してみると以下のようになる。

dp[x + 1][pr + y] = sum{dp[x][pr] * C(cnt[x], y*2) * (y*2)!!}

これはかなり畳み込みに似ている。

cmb[x][y] := h[i]=xの人についてyペア作ったときの組み合わせ
cmb[x][y] = C(cnt[x], y*2) * (y*2)!!

このように定義すると、dp[x + 1][pr]はちょうどdp[x]とcmb[x]の畳み込みになっている！！
ここまで理解できれば、本問題は解けたようなもの。

dp[0][0] = 1というのが最初の状態なので、
dp[0] = 1
に対してcmb[1], cmb[2], ..., cmb[100000]を畳み込み計算していけば、答えのDPが得られる。

# 畳み込み計算の高速化

今回のように、複数の配列を全部畳み込み計算する場合に高速計算する方法がある。
具体的には要素の個数の総和をNとしたときに、全体でO(Nlog^2N)で計算する方法がある。
マージテクを使おう。
畳み込みしたい配列群の中からサイズが小さいものを2つ取ってきて、畳み込み計算をする。
次に、さらにそれを含んで畳み込みしたい配列群の中からサイズが小さいものを2つ取ってきて、畳み込み計算をする。
次に、さらにそれを含んで畳み込みしたい配列群の中からサイズが小さいものを2つ取ってきて、畳み込み計算をする。
…これを繰り返す。
最終的に配列が1つになればそれを返却して終了。
（正直これがO(Nlog^2N)になる理屈はよくわかっていないが、まあ早くなりそうな感じはする）
///////////////////////// writeup2 end */
