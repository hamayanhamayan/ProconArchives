//https://atcoder.jp/contests/abc168/tasks/abc168_e
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
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
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
ll A[201010], B[201010];
//---------------------------------------------------------------------------------------------------
pair<ll, ll> rev(pair<ll, ll> x) {
    ll a = -x.first;
    ll b = x.second;

    if (a < 0) return make_pair(-b, -a);
    return make_pair(b, a);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i] >> B[i];

    int zero_zero = 0;
    int zero_no = 0;
    int no_zero = 0;
    map<pair<ll, ll>,int> cnt;

    rep(i, 0, N) {
        if (A[i] == 0 && B[i] == 0) zero_zero++;
        else if (A[i] == 0) zero_no++;
        else if (B[i] == 0) no_zero++;
        else {
            ll g = gcd(abs(A[i]), abs(B[i]));
            A[i] /= g;
            B[i] /= g;
            if (B[i] < 0) {
                A[i] *= -1;
                B[i] *= -1;
            }
            cnt[make_pair(A[i], B[i])]++;
        }
    }

    mint ans = (mint(2) ^ zero_no) + (mint(2) ^ no_zero) - 1;
    set<pair<ll, ll>> used;
    fore(cn, cnt) if(!used.count(cn.first)) {
        auto p = cn.first;
        auto pp = rev(p);
        if (cnt.count(pp)) {
            ans *= (mint(2) ^ cnt[p]) + (mint(2) ^ cnt[pp]) - 1;
            used.insert(pp);
        }
        else {
            ans *= mint(2) ^ cnt[p];
        }
    }

    ans += zero_zero;
    ans -= 1;
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
条件式を少し変更して考える。
A[i]*A[j]+B[i]*B[j] = 0
A[i]*A[j] = -B[i]*B[j]
A[i]/B[i] = -B[j]/A[j]
このように考えると、各イワシについてA/Bを保持しておいて、A/Bが含まれるなら、-B/Aは含まれないようにすればいい。
つまり、条件を考える場合は、A/Bを計算しておき、A/Bと-B/Aが被らないように注意して数え上げればいい。

ここでA/Bの管理であるが、例えば、2/4と1/2は区別したくない。
こういう時に有理数クラスというのが便利になる。
自分は持ってないが、作るといざというときに役に立つので作るのがオススメ。
分子は正にして、分母分子はgcdを使って既約分数にしておくようなルールで分数を保持するクラスである。

有理数クラスは適切に持っているものと仮定する。
自分の実装ではpair<ll,ll>で(分子,分母)で持っている。

条件を見ると、A[i],B[i]が0であるときは分母に0が来る可能性があるので、ちょっとまずい。
A[i]=0かつB[i]=0である場合は、相手がどんな場合でも条件を満たすので、それしか選ぶことができない。
これは特殊パターンなので、A[i]=B[i]=0の場合を除いて数え上げ、i番目のみを選んだ1パターンを最後に足せばいい。

A[i]=0の場合にはB[j]=0である場合に条件を満たす。
B[i]=0の場合にはA[j]=0である場合に条件を満たす。
つまり、A[i],B[i]のどちらかが0の場合は互いにどちらかしか入れられないことになる。
A[i]=0がzero_no個で、B[i]=0がno_zero個あった場合、組合せは、2^zero_no + 2^no_zero - 1通りとなる。
どちらも入れるということができないので、A[i]=0のものだけを入れた組み合わせが2^zero_no通りで、
B[i]=0のものだけを入れた組み合わせが2^no_zero通りで、この和がどちらかを入れた組み合わせになる。
最後に-1しているのは、どちらの組合せ計算にも「全て取らない」という場合が含まれていて、
かぶって足されているので、-1をしている。

残っているのが、A[i]!=0かつB[i]!=0であるが、これは上と同じ方針で計算することができる。
同じ方針で計算をして、全部の組合せを掛け合わせると答え。
最後に-1をしているのは、全部取らない場合を数え上げてしまっているので、
これは条件の「1匹以上のイワシを選んで」というのに反するので引いている。
///////////////////////// writeup2 end */
