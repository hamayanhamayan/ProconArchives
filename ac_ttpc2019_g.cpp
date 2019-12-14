//https://atcoder.jp/contests/ttpc2019/tasks/ttpc2019_g
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int N, K;
string S;
Comb<mint, 201010> com;
mint cmb_miss[101010], cmb_same[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K >> S;

    int miss = 0, same = 0, center = N % 2;
    rep(i, 0, N / 2) {
        if(S[i] == S[N - 1 - i])
            same++;
        else
            miss++;
    }

    if(K == 1) {
        int ans = 0;
        if (0 < center and miss == 0)
            ans = 25;
        else if (miss == 1)
            ans = 2;
        cout << ans << endl;
        return;
    }

    rep(cnt_same, 0, same + 1) cmb_same[cnt_same] = com.aCb(same, cnt_same) * (mint(25) ^ cnt_same);
    rep(cnt_same, 1, same + 1) cmb_same[cnt_same] += cmb_same[cnt_same - 1];

    rep(cnt_miss, 0, miss + 1) cmb_miss[cnt_miss] = com.aCb(miss, cnt_miss) * (mint(24) ^ cnt_miss) * (mint(2) ^ (miss - cnt_miss));
    
    mint ans = 0;
    rep(cnt_miss, 0, miss + 1) rep(cnt_center, 0, center + 1)
    {
        int ok = -1, ng = same + 1;
        while(ok + 1 != ng) {
            int cnt_same = (ok + ng) / 2;
            if (cnt_same * 2 + cnt_miss * 2 + (miss - cnt_miss) + cnt_center <= K)
                ok = cnt_same;
            else
                ng = cnt_same;
        }

        if(0 <= ok) {
            mint co = cmb_same[ok] * cmb_miss[cnt_miss];
            if(0 < cnt_center)
                co *= 25;
            ans += co;
        }
    }
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
操作は逆に行うこともできるので、問題の言い換えができる。
「操作をちょうどK回行うことで、文字列Tを何種類の回分にできるか」
という問題になる。
今回は操作の組み合わせではなく、結果の組み合わせだけを考えている。
そのため、ちょうどK回と指定があるが、K回以下の回数と考えても問題ない。
同じ所を編集すれば、回数を無駄に増やせるからである。
「操作をK回以下行うことで、文字列Tを何種類の回分にできるか」
これで何が良くなるかというと、あるゴールの回分を考えた時に、最短手順で構築して
手数がK回以下であるかを判定すればいいためである。

さて、まずはDPかなという感じもする。
回分を構築していくので、前半部分を構築すれば後半も構築できるので、N/2で考えていく。
奇数のときは、真ん中も考慮する必要がある。
dp[i][k] := i番目まで確定していてk回操作済みのときの組み合わせ
これはO(NK)でできる。
だが、Kが10^9なので、高速化は難しそう。
DPではないのか？
よくよく考えると、回分で対応している部分は他の部分とは独立している。
なので、DPで順番に決めていく必要はなさそうだ。

ここまでは経験から順当に行くかもしれないが、これ以降が難しい。
回分で対応するグループは3通りに分けられる。
same: s[i]=S[N-i]になってる
miss: s[i]!=S[N-1]になってる
center: Nが奇数の場合で中心になってる
sameをそのままの文字にするときは操作0回、違う文字にするなら操作2回必要。
missをそのままの文字にするときは操作1回、違う文字にするなら操作2回必要。
centerそのままの文字にするときは操作0回、違う文字にするなら操作1回必要。
これでだいぶ抽象化された。
sameとmissの文字を変える回数で全探索すれば、重複なく全通り数えられるのでは？
sameで違う文字にする組がcnt_same個、missで違う文字にする組がcnt_miss個とすると、
cnt_same*2+cnt_miss*2+(miss-cnt_miss)≦Kを満たせばいい。
この組み合わせ計算は、以下を事前計算しておく。
sameで違う文字にcnt_same組する場合の組み合わせ cmb_same(cnt_same) = C(same, cnt_same) * 25^cnt_same
missで違う文字にcnt_miss組する場合の組み合わせ cmb_miss(cnt_miss) = C(miss, cnt_miss) * 24^cnt_miss * 2^(miss-cnt_miss)
すると、組み合わせはcmb_same(cnt_same)*cmb_miss(cnt_miss)となる。
これで、O(N^2)まで来た。
あとは、cnt_missで全探索する時に、使えるcnt_sameの範囲が[0,R]であるなら、
cmb_same(cnt_same)*cmb_miss(0) + cmb_same(cnt_same)*cmb_miss(1) + ... +  cmb_same(cnt_same)*cmb_miss(R)
= cmb_same(cnt_same) * (cmb_miss(0) + cmb_miss(1) + ... +  cmb_miss(R))
となるため、累積和で高速化可能。
これでO(N)で間に合う（自分は横着してO(NlogN)）
centerは2通りしかないので、こちらも全探索すればいい。

K=1のときは元々回分なのに壊すしかないというパターンが考えられるので場合分けして答えよう。
///////////////////////// writeup2 end */
