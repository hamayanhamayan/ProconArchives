//https://atcoder.jp/contests/agc047/tasks/agc047_b
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
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r;
}
int getrandmax() {
    static uint32_t y = time(NULL);
    y ^= (y << 13); y ^= (y >> 17);
    y ^= (y << 5);
    return abs((int)y);
}
// [l, r]
int getrand(int l, int r) {
    return getrandmax() % (r - l + 1) + l;
}
typedef ModInt<1000000007> mint1;
typedef ModInt<1000000009> mint2;
int primes[10] = { 10007, 10009, 10037, 10039, 10061, 10067, 10069, 10079, 10091, 10093 };
bool isShuffle = false;
struct RollingHash {
    mint1 p1; mint2 p2;
    int n;
    vector<mint1> m1; vector<mint2> m2;
    vector<mint1> v1; vector<mint2> v2;
    vector<mint1> r1; vector<mint2> r2;

    RollingHash() {
        if (!isShuffle) {
            rep(i, 0, 101) { int a = getrand(0, 9); int b = getrand(0, 9); swap(primes[a], primes[b]); }
            isShuffle = true;
        }
        p1 = primes[0], p2 = primes[1];
    }

    void init(string s, char o = 'a') {
        vector<int> v;
        fore(c, s) v.push_back(c - o + 1);
        init(v);
    }

    void init(vector<int> s) {
        n = s.size();
        m1.resize(n); m2.resize(n); v1.resize(n); v2.resize(n); r1.resize(n); r2.resize(n);

        m1[0] = 1; m2[0] = 1;
        v1[0] = s[0]; v2[0] = s[0];

        rep(i, 1, n) {
            m1[i] = m1[i - 1] * p1;
            m2[i] = m2[i - 1] * p2;
            v1[i] = v1[i - 1] + m1[i] * s[i];
            v2[i] = v2[i - 1] + m2[i] * s[i];
        }

        r1[n - 1] = mint1(1) / m1[n - 1];
        rrep(i, n - 2, 0) r1[i] = r1[i + 1] * p1;

        r2[n - 1] = mint2(1) / m2[n - 1];
        rrep(i, n - 2, 0) r2[i] = r2[i + 1] * p2;
    }
    // s[l..r]
    inline pair<mint1, mint2> hash(int l, int r) {
        if (l > r) return { 0,0 };
        assert(l <= r); assert(r < n);
        mint1 a = v1[r];
        if (l) a -= v1[l - 1];
        a *= r1[l];

        mint2 b = v2[r];
        if (l) b -= v2[l - 1];
        b *= r2[l];

        return { a, b };
    }
    // s[l..r]
	inline ll llhash(int l, int r) {
		auto h = hash(l, r);
		return 1LL * h.first.get() * h.second.Mod + h.second.get();
	}
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














int N;
string S[201010];
map<ll, int> cnt[26];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> S[i];
    rep(i, 0, N) reverse(all(S[i]));
    sort(S, S + N, [&](string a, string b) { return a.length() < b.length(); });

    ll ans = 0;
    
    RollingHash rh;
    rep(i, 0, N) {
        rh.init(S[i]);
        int n = S[i].length();
        
        int msk = 0;
        rrep(j, n - 1, 0) {
            msk |= (1 << (S[i][j] - 'a'));
            ll hh = rh.llhash(0, j - 1);
            rep(c, 0, 26) if ((msk & (1 << c)) && cnt[c].count(hh)) {
                ans += cnt[c][hh];
            }
        }

        ll h = rh.llhash(0, n - 2);
        cnt[S[i][n - 1] - 'a'][h]++;
    }

    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [Trie](https://www.hamayanhamayan.com/entry/2017/03/25/005452) （想定解）
- [ローリングハッシュ](https://www.hamayanhamayan.com/entry/2017/03/25/005452) （hamayanhamayan解法）
///////////////////////// writeup2 start
複数文字列なので、最初にTrieが思い浮かんだが、よくよく考えると実装が面倒なので、ロリハに変えた。
まあ、ロリハライブラリもバグり倒していたので、結局むっちゃかかった。

## 条件を言い換える

まず、文字列aを文字列bにできるかというのを考える。
自明な所から考えると、文字列の長さは|a|≧|b|でなくてはならない。
先頭2文字だけ操作できるということは、ストックできるのは1文字だけということになる。
そして、ストックすると必ず先頭の文字列になってしまうので、ストックするのは文字列bの先頭になる。
文字列bの先頭を持つと、その後は消すしかできないので、文字列aの末尾をどれだけ残すかという感じになる。

端的に条件を言い換えると、以下をすべて満たせば変換可能。

- |a|≧|b|
- bの先頭以外の末尾列と、同じ長さのaの末尾列が等しい
- bの先頭の文字が、aの↑の条件の末尾列以外の部分に含まれる

末尾といえば、suffix-arrayであるが、複数文字列なので怪しい所。
末尾を考えるよりも先頭を考えた方がよさそうだ。
以降は、文字列をリバースして、

- |a|≧|b|
- bの末尾以外の先頭列と、同じ長さのaの先頭列が等しい
- bの末尾の文字が、aの↑の条件の先頭列以外の部分に含まれる

として考えることにしよう。

## 先頭が等しくて、末尾の文字が含まれる？

文字列が等しいことを評価するにはローリングハッシュが使える。
ロリハを知らない場合はこの解法は難しい。
どこかで学んでこよう。
文字列を長さでソートして、以下の配列を作っていこう。

cnt[lst][hash] := 最後の文字がlstで、それ以外の文字列をハッシュ化するとhashとなる組は何通りか

これを作って置いて、ある文字列の評価になったときに、その文字列から変換可能な文字を考えていく。
文字列の長さを小さい順からやっていけば、ある文字列の評価時に、変換先の候補となる組はすべてcntに入っている状態を保てる。
文字列を後ろから見ていき、どの文字が含まれるかを持ちながら数え上げていく。

- 以下操作を文字列の末尾から行っていく
    - mskに今見ている文字列を入れる
    - 今見ている文字列より前にある先頭列をhash化する -> hh
    - mskが立っている（先頭列より後にその文字が含まれる）文字cに対してcnt[c][hh]の個数を見て、それを答えに足す

ハッシュの数は大きくなるので、mapに入れる必要がある。
mapに入れるものは遷移先と遷移元の2パターンがあるが、本解法では遷移先を入れている。
こうするとmapに入れる最大個数は2*10^5個となる。
実装を変えると、mapに入れる最大個数は10^6となり、自分の解法ではTLEしてしまった。
///////////////////////// writeup2 end */
