//https://atcoder.jp/contests/agc047/tasks/agc047_c
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
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
template<class T> T extgcd(T a, T b, T & x, T & y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
struct MathsNTTModAny {
    template<int mod, int primitive_root>
    class NTT {
    public:
        int get_mod() const { return mod; }
        void _ntt(vector<ll>& a, int sign) {
            const int n = sz(a);
            assert((n ^ (n & -n)) == 0); //n = 2^k

            const int g = 3; //g is primitive root of mod
            int h = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
            if (sign == -1) h = (int)mod_inv(h, mod); //h = h^-1 % mod

            //bit reverse
            int i = 0;
            for (int j = 1; j < n - 1; ++j) {
                for (int k = n >> 1; k > (i ^= k); k >>= 1);
                if (j < i) swap(a[i], a[j]);
            }

            for (int m = 1; m < n; m *= 2) {
                const int m2 = 2 * m;
                const ll base = mod_pow(h, n / m2, mod);
                ll w = 1;
                FOR(x, m) {
                    for (int s = x; s < n; s += m2) {
                        ll u = a[s];
                        ll d = a[s + m] * w % mod;
                        a[s] = u + d;
                        if (a[s] >= mod) a[s] -= mod;
                        a[s + m] = u - d;
                        if (a[s + m] < 0) a[s + m] += mod;
                    }
                    w = w * base % mod;
                }
            }

            for (auto& x : a) if (x < 0) x += mod;
        }
        void ntt(vector<ll> & input) {
            _ntt(input, 1);
        }
        void intt(vector<ll> & input) {
            _ntt(input, -1);
            const int n_inv = mod_inv(sz(input), mod);
            for (auto& x : input) x = x * n_inv % mod;
        }

        vector<ll> convolution(const vector<ll> & a, const vector<ll> & b) {
            int ntt_size = 1;
            while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;

            vector<ll> _a = a, _b = b;
            _a.resize(ntt_size); _b.resize(ntt_size);

            ntt(_a);
            ntt(_b);

            FOR(i, ntt_size) {
                (_a[i] *= _b[i]) %= mod;
            }

            intt(_a);
            return _a;
        }
    };

    ll garner(vector<pair<int,int>> mr, int mod) {
        mr.emplace_back(mod, 0);

        vector<ll> coffs(sz(mr), 1);
        vector<ll> constants(sz(mr), 0);
        FOR(i, sz(mr) - 1) {
            // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first) を解く
            ll v = (mr[i].second - constants[i]) * mod_inv<ll>(coffs[i], mr[i].first) % mr[i].first;
            if (v < 0) v += mr[i].first;

            for (int j = i + 1; j < sz(mr); j++) {
                (constants[j] += coffs[j] * v) %= mr[j].first;
                (coffs[j] *= mr[i].first) %= mr[j].first;
            }
        }

        return constants[sz(mr) - 1];
    }

    typedef NTT<167772161, 3> NTT_1;
    typedef NTT<469762049, 3> NTT_2;
    typedef NTT<1224736769, 3> NTT_3;

    vector<ll> solve(vector<ll> a, vector<ll> b) {
        NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
        assert(ntt1.get_mod() < ntt2.get_mod() && ntt2.get_mod() < ntt3.get_mod());
        auto x = ntt1.convolution(a, b);
        auto y = ntt2.convolution(a, b);
        auto z = ntt3.convolution(a, b);

        const ll m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
        const ll m1_inv_m2 = mod_inv<ll>(m1, m2);
        const ll m12_inv_m3 = mod_inv<ll>(m1 * m2, m3);
        const ll m12_mod = m1 * m2;
        vector<ll> ret(sz(x));
        FOR(i, sz(x)) {
            ll v1 = (y[i] - x[i]) * m1_inv_m2 % m2;
            if (v1 < 0) v1 += m2;
            ll v2 = (z[i] - (x[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
            if (v2 < 0) v2 += m3;
            ll constants3 = (x[i] + m1 * v1 + m12_mod * v2);
            ret[i] = constants3;
        }

        return ret;
    }

    vector<int> solve(vector<int> a, vector<int> b) {
        vector<ll> x(all(a));
        vector<ll> y(all(b));

        auto z = solve(x, y);
        vector<int> res;
        fore(aa, z) res.push_back(aa);

        return res;
    }
};
// return primitive root of P
ll get_root(ll p) {
    rep(i, 2, p) {
        int x = 1;
        set<int> se;
        while (1) {
            if (se.size() == p - 1) return i;
            if (se.count(x)) break;
            se.insert(x);
            x = (x * i) % p;
        }
    }
    return -1;
}
// C[k] = sum_{1<=i,j<P and k=(i*j)modP}A[i]B[j]
// https://yukicoder.me/problems/no/931
vector<ll> convolutionMulModP(vector<int> A, vector<int> B, int P) {
	if (P == 2) return { 0, (int)((1LL * A[1] * B[1])) };

	ll root = get_root(P);
	vector<ll> a(1 << 18), b(1 << 18);
	ll v = 1;
	rep(i, 0, P - 1) {
		a[i] = A[v];
		b[i] = B[v];
		v = (v * root) % P;
	}

	MathsNTTModAny ntt;
	auto c = ntt.solve(a, b);

	vector<ll> res(P);
	v = 1;
	rep(i, 0, c.size()) {
		res[v] = res[v] + c[i];
		v = (v * root) % P;
	}
	return res;
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














int N, A[201010];
int P = 200003;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> A[i];

    vector<int> v(1 << 18);
    rep(i, 0, N) v[A[i]]++;

    auto comb = convolutionMulModP(v, v, P);

    ll ans = 0;
    int n = comb.size();
    rep(i, 0, n) ans += 1LL * comb[i] * i;
    rep(i, 0, N) ans -= (1LL * A[i] * A[i]) % P;
    cout << ans / 2 << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [FFT/NTT](https://www.hamayanhamayan.com/entry/2017/05/20/125607)
- 原子根
///////////////////////// writeup2 start
隠してはあるが、最初の1手が分かれば一気に（高度）典型化する。

## 主客転倒

全ての組み合わせに対して、とある計算をして総和を求める。
組合せはO(N^2)でこのままでは間に合わない。
主客転倒をしてみよう。
とある計算の計算結果はP未満となる。
よって、計算結果の方を考えてみると、O(P)であり、こっちの方が筋がよさそう。

計算結果起点で考えてみると、
計算結果がxとなる組合せをcomb[x]とすると、答えはx*comb[x]の総和となる。

## comb配列の計算

よって、comb配列が求まれば答えが計算可能。
comb[x] := (A[i] * A[j]) % P = x、かつ、i＜jであるような(i,j)の組
これは、類題になじみがある人がみると、ピンとくる条件になっている。畳み込み計算に帰着ができる。
comb[x] := (A[i] * A[j]) % P = xであるような(i,j)の組
i,jの大小関係を取っ払おう。
これを計算した後に、A[i]*A[i]のパターンを引いて、全体を÷2すれば同じが答えが得られる。

## 畳み込み計算（簡単版）

comb[x] := (A[i] * A[j]) % P = xであるような(i,j)の組
これを計算するのだが、
f[x] := A[i] + A[j] = xであるような(i,j)の組
であると考えてみる。
これはそれほど難しくなく、g[x] := A[i]=xであるiの個数として、配列gと配列gで普通の畳み込みをすれば求めることができる。
まず、これが分からない場合は畳み込み計算、もしくは、FFTについて勉強してきてほしい。

## 今回の畳み込み計算

今回は添え字部分が和ではなく、積になっている。
この場合の常套テクとして、原始根変換がある。
Pの原始根gをまずは探す。
そして、A[i] = g^B[i]のように変換していく。
すると、A[i] * A[j]はg^(B[i] + B[j])のように変換ができ、積を指数部の和として考えてFFTするようにする。

…とまぁ、解説したが、自分はこの辺は何となく理解なので、何とも言えない。
以下資料を参照した方がいい。

- [解説 No.931 Multiplicative Convolution - yukicoder](https://yukicoder.me/problems/no/931/editorial)
- [articles/pre-seisuuron.pdf at pre-releases · kirika-comp/articles](https://github.com/kirika-comp/articles/blob/pre-releases/pre-seisuuron.pdf)の31ページ
///////////////////////// writeup2 end */
