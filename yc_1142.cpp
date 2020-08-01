//https://yukicoder.me/problems/no/1142
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














int N, M, K, A[201010], B[201010];
//---------------------------------------------------------------------------------------------------
mint cnt[1 << 10];
vector<mint> get(int n, int* v) {
    vector<mint> acnt(1 << 10);
    rep(i, 0, 1 << 10) cnt[i] = 0;

    int tot = 0;
    cnt[0] += 1;
    rep(i, 0, n) {
        tot ^= v[i];
        cnt[tot] += 1;
    }

    rep(a, 0, 1 << 10) rep(b, a + 1, 1 << 10) acnt[a ^ b] += cnt[a] * cnt[b];
    rep(a, 0, 1 << 10) acnt[0] += cnt[a] * (cnt[a] - 1) / 2;

    return acnt;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, M) cin >> B[i];

    auto acnt = get(N, A);
    auto bcnt = get(M, B);

    mint ans = 0;
    rep(a, 0, 1 << 10) rep(b, 0, 1 << 10) if ((a ^ b) == K) ans += acnt[a] * bcnt[b];
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
どこから考えようか迷うと思う。
制約から弱点を抜きだそう。
a[i],b[i],Kはすべて1024に収まるので、そのxor和も1024に収まる。
1024^2の組み合わせは間に合うので、その組み合わせで何かするんだろう。

## 配列a,bで独立に考える

acnt[x] := 配列aで区間xor和がxである区間の個数
bcnt[x] := 配列bで区間xor和がxである区間の個数

これが分かっていれば、答えは、a xor b == Kであるa,bについてacnt[a]*bcnt[b]を総和を取れば答えになる。
acnt,bcntは同じものを計算しているので、同じアルゴリズムを使うことができる。
これを作る関数をget関数として実装していこう。
get(n, v) := 長さnの配列vでacnt[x]を作る

## get関数

「区間xor和がx」という条件をもっと扱いやすくできないだろうか。
これは累積和を使えばできる。
区間和や区間xor和を考えるときに、累積和を使うことはよくある。

tot[i] := [0,i]の区間の累積xor和とすると、
「区間[L,R]のxor和 = tot[R] xor tot[L - 1]」が成り立つ。
これを出力するacnt配列に組み込んで考えると、
acnt[x] := tot[i] ^ tot[j]=xであるような(i,j)の組み合わせ
となる。

こっからもまた大変なのだが、(i,j)の組み合わせを考えると、O(N^2)となってしまうので、
tot[i]の組み合わせを考えることにする。
こちらは、1024^2通りなので間に合う。

なので、tot[i]の値をさらに数えておこう。
cnt[i] := tot[j]=iとなるjの組み合わせ
acnt[x ^ y] += cnt[x] * cnt[y]
これで計算していけばいい。
注意点としてはx＜yで数え上げることで、重複を防ぐことと、x=yの場合は別途、個数から2つ選ぶようにして数え上げる。
///////////////////////// writeup2 end */
