//https://yukicoder.me/problems/no/1084
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
ll mul(ll a, ll b) { if (a == 0) return 0; if (infl / a < b) return infl; return min(infl, a * b); }
// スパーステーブルをまずは検討しよう
#ifdef _MSC_VER
inline unsigned int __builtin_clz(unsigned int x){unsigned long r;_BitScanReverse(&r,x);return 31-r;}
#endif // _MSC_VER
template<class V> struct SparseTable { // [L,R)
    const V def = 1;
    inline V comp(V a, V b) { return mul(a, b); }

    int n; vector<V> a, b[22]; inline int __lg(int x) { return 32 - 1 - __builtin_clz(x); }
    void init(V* start, V* end) {
        vector<V> v;
        for (auto ite = start; ite != end; ite++) v.push_back(*ite);
        init(v);
    }
    void init(vector<V> v) {
        int nn = v.size(); n = 1; while (n < nn) n *= 2; a.resize(n);
        rep(i, 0, 22) b[i].resize(n); rep(i, 0, nn) a[i] = v[i];

        int d = 1 << __lg(n - 1), e = d << 1;
        for (int h = 0, f; (f = 1 << h) <= d; ++h) {
            for (int i = f, r = f << 1; i < e; i += r) {
                b[h][i - 1] = a[i - 1];
                for (int j = i - 2; j >= i - f; --j) b[h][j] = comp(b[h][j + 1], a[j]);
                b[h][i] = a[i];
                for (int j = i + 1; j < i + f; ++j) b[h][j] = comp(b[h][j - 1], a[j]);
            }
        }
    }

    V get(int L,int R){assert(0<=L&&L<=R);if(L==R)return def;R--;if(L==R)return a[L];int h=__lg(L^R);
        return comp(b[h][L],b[h][R]);}};
template <typename T> struct ImosLinear {
    vector<T> v;
    vector<tuple<int, int, T>> buf;
    ImosLinear(int n) { init(n); } ImosLinear() {}
    void init(int n) { v.resize(n, 0); buf.clear(); }
    // [l,r)に傾きaで、切片bの一次関数を足す
    void set(int l, int r, T a, T b) {
        if (l + 1 < v.size()) v[l + 1] += a; if (r < v.size()) v[r] -= a;
        if (r < v.size()) buf.push_back(make_tuple(r, v.size(), (T)-(r - l - 1) * a));
        buf.push_back(make_tuple(l, r, b));
    }
    void build() {
        rep(i, 1, v.size()) v[i] += v[i - 1];
        for (auto t : buf) {
            int l, r; T b; tie(l, r, b) = t;
            v[l] += b;
            if (r < v.size()) v[r] -= b;
        }
        rep(i, 1, v.size()) v[i] += v[i - 1];
    }
    T operator[](int i) { return v[i]; }
    void dump() {
        cout << "dump : [";
        for (T i : v) cout << " " << i;
        cout << " ]" << endl;
    }
};
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









int N; ll A[101010];
SparseTable<ll> st;
ImosLinear<ll> imos;
int limit = 1000000000;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

    rep(i, 0, N) if (A[i] == 0) {
        cout << 0 << endl;
        return;
    }

    st.init(A, A + N);
    imos.init(N);

    rep(l, 0, N) {
        int ok = l + 1, ng = N + 1;
        while (ok + 1 != ng) {
            int md = (ok + ng) / 2;
            if (st.get(l, md) < limit) ok = md;
            else ng = md;
        }
        imos.set(l, ok, -1, ok - l);
    }

    imos.build();

    mint ans = 1;
    rep(i, 0, N) ans *= mint(A[i]) ^ imos[i];
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [区間積セグメントツリー（または、スパーステーブル）](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
- [一次(関数)imos](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
///////////////////////// writeup2 start
複合的な知識が必要。

まずは、全探索対象が区間となっているが、区間の全探索は間に合わない。
そこで、主客転倒をして全探索対象が変えられないか考えてみる。
つまり、「全部の区間についてAの総積の更に総積をとる」というのを「A×(Aが含まれる区間の個数)の総積」に置き換えて考える。
Aが含まれる区間の個数が分かれば、A[i]の区間の個数乗の総積が答えとなる。

これで区間の個数が高速に求められれば、A[i]の全探索で答えが導けることは分かったが、区間の個数を求めるのはどうやればいいだろう。
条件を満たす区間の個数を求めるときのテクとして、片方を全探索して、条件を満たすもう片方を高速に求めるテクがある。
このテクはかなり良く出てくるので、思いつきたい。

左端を全探索するとして、条件を満たす右端を左端から初めて順番に考えてみると、「満たす 満たす 満たす 満たさない 満たさない」のように
前半は満たすけど、後半は満たさないといった感じになる。
つまり、二分探索を使って境界線を探すことができるということである。
ここで、区間の総積を区間積セグメントツリー（か、より計算量の良いスパーステーブル）で求められるようにしておくことで、
二分探索で条件を満たす区間を割り出すことができる。
これで、[l,l], [l,l+1], ..., [l,r]は条件を満たすということを割り出せる。
なお、この部分は尺取り法の方が計算量がいい。
全探索＋二分探索は尺取り法で改善できるのはよくある話であり、こちらも練習しておくといいだろう。
あと、オーバーフローしないように注意。

この区間でAがどれだけ使われているか、個数を見てみると、5 4 3 2 1のような公差-1のような数列になっている。
全ての右端について、この公差-1のような数列を全部求めて足し合わせれば、それぞれのAについて区間の個数が求められる。
このような一次関数を高速に数列に足しこむテクとして、imos法がある。
定数を数列に足しこむテクとしてimos法を認識している人も多いと思うが、一次関数や二次関数も実は足しこむことができる。
一次関数であれば二回累積和をする。
具体的には公差a, 初項bを区間[L,R)に足しこむ場合は、
v[L] += a
v[R] -= a
をして一回、累積和を取る。
その後、
v[R] -= (R - L - 1) * a
v[L] += b
v[R] -= b
をして、更に累積和を取る。

これで、各Aの出てくる回数が分かったので、累乗を取って、総積を取ると答え。
///////////////////////// writeup2 end */
